#include "mytcpsocket.h"
#include <QDebug>
#include <stdio.h>
#include <QFile>
#include <QFileInfoList>
#include "mytcpserver.h"

mytcpsocket::mytcpsocket(QObject *parent)
    : QTcpSocket{parent}
{
    connect(this,SIGNAL(readyRead()),this,SLOT(recvMsg()));
    connect(this,SIGNAL(disconnected()),this ,SLOT(clientOffline()));

    m_bUpload = false;
    m_pTimer = new QTimer;
    connect(m_pTimer, SIGNAL(timeout())
            , this, SLOT(sendFileToClient()));
}
QString mytcpsocket::getName()
{
    return m_strName;
}
void offline(mytcpsocket *mysocket)
{

}
void mytcpsocket::copyDir(QString strSrcDir, QString strDesDir)
{
    QDir dir;
    dir.mkdir(strDesDir);
    dir.setPath(strSrcDir);
    QString srcTmp;
    QString desTmp;
    QFileInfoList fileInforlist = dir.entryInfoList();
    for( int i =0; i < fileInforlist.size(); i++)
    {
        qDebug()<< "filename:" << fileInforlist[i].fileName();
        if(fileInforlist[i].isFile())
        {
            srcTmp = strSrcDir + '/' +fileInforlist[i].fileName();
            desTmp = strDesDir + '/' +fileInforlist[i].fileName();
            QFile::copy(srcTmp, desTmp);
        }
        else if (fileInforlist[i].isDir()){
            if(QString(".") == fileInforlist[i].fileName()|| QString("..") == fileInforlist[i].fileName())
            {
                continue;
            }
            else {
                srcTmp = strSrcDir + '/' +fileInforlist[i].fileName();
                desTmp = strDesDir + '/' +fileInforlist[i].fileName();
                copyDir(srcTmp,desTmp);
            }
        }
    }
}

PDU* mytcpsocket::writeUPD()
{
    uint uiPDULen = 0 ;
    this->read((char *)&uiPDULen , sizeof(uint));
    uint uiMsgLen = uiPDULen - sizeof(PDU);
    PDU * pdu = mkPDU(uiMsgLen);
    this->read(((char *)pdu + sizeof(uint)),uiPDULen - sizeof(uint));
    return pdu;
}

void mytcpsocket::recvMsg()
{
qDebug()<<"creat dir:";
    //if(!m_bUPload)
    if(!m_bUpload)
    {
        PDU * pdu = writeUPD();
        switch (pdu->uiMsgType)
        {
            case ENUM_MSG_TYPE_REGIST_REQUEST:
        {
            char caName[32] = {'\0'};
            char caPwd[32] = {'\0'};
            strncpy(caName, pdu->caData, 32);
            strncpy(caPwd, pdu->caData + 32 , 32);
            bool ret = QpeDB::getInstance().handleRegist(caName,caPwd);


            PDU* respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_REGIST_RESPOND;
            if(ret)
            {
                strcpy(respdu->caData,REGIST_OK);
               QDir dir;
   qDebug()<<"creat dir:";


            }else
            {
                strcpy(respdu->caData,REGIST_FAILED);
            }
            write((char*)respdu,respdu->uiPDULen);
            free (respdu);
            respdu = nullptr;
            break;

        }
        case ENUM_MSG_TYPE_LOGIN_REQUEST:
        {
            char caName[32] = {'\0'};
            char caPwd[32] = {'\0'};
            strncpy(caName, pdu->caData, 32);
            strncpy(caPwd, pdu->caData + 32 , 32);
            bool ret = QpeDB::getInstance().handleLogin(caName,caPwd);
            PDU* respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_LOGIN_RESPOND;
            if(ret)
            {
                strcpy(respdu->caData,LOGIN_OK);
                m_strName = caName;


            }else
            {
                strcpy(respdu->caData,LOGIN_FAILED);
            }
            if(write((char*)respdu,respdu->uiPDULen))
            {
                qDebug()<<"fasong";
            }
            free (respdu);
            respdu = nullptr;
            break;

        }
    case ENUM_MSG_TYPE_ALL_ONLINE_REQUEST:
        {
            qDebug()<<"all online request";
            QStringList ret = QpeDB::getInstance().handleALLOnline();
            uint uiMsglen = ret.size() * 32;
            PDU * pdus =mkPDU(uiMsglen);
            pdus->uiMsgType = ENUM_MSG_TYPE_ALL_ONLINE_RESPOND;
            for (int i = 0 ;i< ret.size();i++)
            {
                memcpy((char*)pdus->caMsg+ i*32,ret.at(i).toStdString().c_str(),ret.at(i).size());

            }
            write((char *)pdus,pdus->uiPDULen);
            free(pdus);
            pdus =nullptr;
            break;
        }
        case ENUM_MSG_TYPE_SEARCH_USR_REQUEST:
        {
            int ret = QpeDB::getInstance().handleSearchUsr(pdu->caData);
            PDU * respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_SEARCH_USR_RESPOND;
            if(ret == -1)
            {
                strcpy(respdu->caData,SEARCH_USR_NO);
            }
            else if(ret == 1)
            {
                strcpy(respdu->caData,SEARCH_USR_ONLINE);
            }
            else if(ret == 0)
            {
                strcpy(respdu->caData,SEARCH_USR_OFFLINE);
            }
            write((char*)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = nullptr;
            break;
        }
        case ENUM_MSG_TYPE_ADD_FRIEND_REQUEST:
        {
            char caPerName[32] = {'\0'};
            char Name[32] = {'\0'};
            strncpy(caPerName,pdu->caData,32);
            strncpy(Name,pdu->caData +32,32);
            int ret = QpeDB::getInstance().handleAddFriend(caPerName,Name);
            PDU *respdu = mkPDU(0);
               respdu->uiMsgType = ENUM_MSG_TYPE_ADD_FRIEND_REFUSE;
            if(ret == -1)
            {
                strcpy(respdu->caData,UNKNOW_ERROR);
                write((char*)respdu,respdu->uiPDULen);
            }
            else if(ret == 0)
            {
                strcpy(respdu->caData,EXISTED_FRIEND);
                write((char *)respdu,respdu->uiPDULen);
            }
            else if(ret == 1)
            {
                MyTcpServer::getInstance().resend(caPerName,pdu);
            }
            else if(ret = 2)
            {
                strcpy(respdu->caData,ADD_FRIEND_OFFLINE);
                write((char *)respdu,respdu->uiPDULen);
            }
            else if(ret == 3)
            {
                strcpy(respdu->caData,ADD_FRIEND_NO_EXIST);
                write((char *)respdu , respdu->uiPDULen);
            }
            free(respdu);
            respdu=nullptr;
            break;
        }
        case ENUM_MSG_TYPE_ADD_FRIEND_AGGREE:
        {
            char caPerName[32] = {'\0'};
            char Name[32] = {'\0'};
            strncpy(caPerName,pdu->caData,32);
            strncpy(Name,pdu->caData +32,32);
        QpeDB::getInstance().handleAgreeAddFriend(caPerName,Name);
        MyTcpServer::getInstance().resend(Name,pdu);
            break;
        }
        case ENUM_MSG_TYPE_ADD_FRIEND_REFUSE:
        {
            char caName[32] = {'\0'};
            strncpy(caName,pdu->caData+32,32);
            MyTcpServer::getInstance().resend(caName,pdu);
            break;
        }
        case ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST:
        {
            char caName[32] = {'\0'};
            strncpy(caName,pdu->caData,32);
            QStringList ret = QpeDB::getInstance().handleFlushFriend(caName);
            uint Mslen = ret.size();
            PDU * respdu = mkPDU(Mslen*32);
            respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FRIEND_RESPOND;
            for(int i = 0; i < Mslen ; i++)
            {
                memcpy((char *)respdu->caMsg + i* 32,ret.at(i).toStdString().c_str(),ret.at(i).size());
                write((char *)respdu , respdu->uiPDULen);
                free(respdu);
                respdu = nullptr;
            }
            break;
        }
        case ENUM_MSG_TYPE_DELETE_FRIEND_REQUEST:
        {
            char caSelfName[32] = {'\0'};
            char caFriend[32] = {'\0'};
            strncpy(caSelfName,pdu->caData,32);
            strncpy(caFriend,pdu->caData + 32,32);
            QpeDB::getInstance().handleDelFriend(caSelfName,caFriend);

            PDU *respdu = mkPDU(0);
            respdu->uiMsgType = ENUM_MSG_TYPE_DELETE_FRIEND_RESPOND;
            strcpy(respdu->caData,DEL_FRIEND_OK);
            write((char *)respdu,respdu->uiPDULen);
            free(respdu);
            respdu = nullptr;
            MyTcpServer::getInstance().resend(caFriend,pdu);
            break;
        }
        case ENUM_MSG_TYPE_PRIVATE_CHAT_REQUEST:
        {
            char caSelfName[32] = {'\0'};
            char caFriend[32] = {'\0'};
            strncpy(caSelfName,pdu->caData,32);
            strncpy(caFriend,pdu->caData + 32,32);
            MyTcpServer::getInstance().resend(caFriend,pdu);
            break;
        }
        case ENUM_MSG_TYPE_GROUP_CHAT_REQUEST:
        {
            char caSelfName[32] = {'\0'};

            strncpy(caSelfName,pdu->caData,32);
            QStringList onlineFriend = QpeDB::getInstance().handleFlushFriend(caSelfName);
            QString tmp;
            for(int i =0;i<onlineFriend.size();i++)
            {
                tmp = onlineFriend.at(i);
                MyTcpServer::getInstance().resend(tmp.toStdString().c_str(),pdu);
            }
            break;
        }
        case ENUM_MSG_TYPE_CREATE_DIR_REQUEST:
                {
                    QDir dir;
                    QString strCurPath = QString("%1").arg((char*)(pdu->caMsg));
                    qDebug() << strCurPath;
                    bool ret = dir.exists(strCurPath);
                    PDU *respdu = NULL;
                    if (ret)  //当前目录存在
                    {
                        char caNewDir[32] = {'\0'};
                        memcpy(caNewDir, pdu->caData+32, 32);
                        QString strNewPath = strCurPath+"/"+caNewDir;
                        qDebug() << strNewPath;
                        ret = dir.exists(strNewPath);
                        qDebug() << "-->" << ret;
                        if (ret)  //创建的文件名已存在
                        {
                            respdu = mkPDU(0);
                            respdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_RESPOND;
                            strcpy(respdu->caData, FILE_NAME_EXIST);
                        }
                        else   //创建的文件名不存在
                        {
                            dir.mkdir(strNewPath);
                            respdu = mkPDU(0);
                            respdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_RESPOND;
                            strcpy(respdu->caData, CREAT_DIR_OK);
                        }
                    }
                    else     //当前目录不存在
                    {
                        respdu = mkPDU(0);
                        respdu->uiMsgType = ENUM_MSG_TYPE_CREATE_DIR_RESPOND;
                        strcpy(respdu->caData, DIR_NO_EXIST);
                    }
                    write((char*)respdu, respdu->uiPDULen);
                    free(respdu);
                    respdu = NULL;
                    break;
                }
                case ENUM_MSG_TYPE_FLUSH_FILE_REQUEST:
                {
                    char *pCurPath = new char[pdu->uiMsgLen];
                    memcpy(pCurPath, pdu->caMsg, pdu->uiMsgLen);
                    QDir dir(pCurPath);
                    QFileInfoList fileInfoList = dir.entryInfoList();
                    int iFileCount = fileInfoList.size();
                    PDU *respdu = mkPDU(sizeof(FileInfo)*iFileCount);
                    respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FILE_RESPOND;
                    FileInfo *pFileInfo = NULL;
                    QString strFileName;
                    for (int i=0; i<iFileCount; i++)
                    {
                        pFileInfo = (FileInfo*)(respdu->caMsg)+i;
                        strFileName = fileInfoList[i].fileName();

                        memcpy(pFileInfo->caFileName, strFileName.toStdString().c_str(), strFileName.size());
                        if (fileInfoList[i].isDir())
                        {
                            pFileInfo->iFileType = 0;
                        }
                        else if (fileInfoList[i].isFile())
                        {
                            pFileInfo->iFileType = 1;
                        }
                    }
                    write((char*)respdu, respdu->uiPDULen);
                    free(respdu);
                    respdu = NULL;
                    break;
                }
                case ENUM_MSG_TYPE_DEL_DIR_REQUEST:
                {
                    char caName[32] = {'\0'};
                    strcpy(caName, pdu->caData);
                    char *pPath = new char[pdu->uiMsgLen];
                    memcpy(pPath, pdu->caMsg, pdu->uiMsgLen);
                    QString strPath = QString("%1/%2").arg(pPath).arg(caName);
                    qDebug() << strPath;

                    QFileInfo fileInfo(strPath);
                    bool ret = false;
                    if (fileInfo.isDir())
                    {
                        QDir dir;
                        dir.setPath(strPath);
                        ret = dir.removeRecursively();
                    }
                    else if (fileInfo.isFile())  //常规文件
                    {
                        ret = false;
                    }
                    PDU *respdu = NULL;
                    if (ret)
                    {
                        respdu = mkPDU(strlen(DEL_DIR_OK)+1);
                        respdu->uiMsgType = ENUM_MSG_TYPE_DEL_DIR_RESPOND;
                        memcpy(respdu->caData, DEL_DIR_OK, strlen(DEL_DIR_OK));
                    }
                    else
                    {
                        respdu = mkPDU(strlen(DEL_DIR_FAILURED)+1);
                        respdu->uiMsgType = ENUM_MSG_TYPE_DEL_DIR_RESPOND;
                        memcpy(respdu->caData, DEL_DIR_FAILURED, strlen(DEL_DIR_FAILURED));
                    }

                    write((char*)respdu, respdu->uiPDULen);
                    free(respdu);
                    respdu = NULL;

                    break;
                }
                case ENUM_MSG_TYPE_RENAME_FILE_REQUEST:
                {
                    char caOldName[32] = {'\0'};
                    char caNewName[32] = {'\0'};
                    strncpy(caOldName, pdu->caData, 32);
                    strncpy(caNewName, pdu->caData+32, 32);

                    char *pPath = new char[pdu->uiMsgLen];
                    memcpy(pPath, pdu->caMsg, pdu->uiMsgLen);

                    QString strOldPath = QString("%1/%2").arg(pPath).arg(caOldName);
                    QString strNewPath = QString("%1/%2").arg(pPath).arg(caNewName);

                    qDebug() << strOldPath;
                    qDebug() << strNewPath;

                    QDir dir;
                    bool ret = dir.rename(strOldPath, strNewPath);
                    PDU *respdu = mkPDU(0);
                    respdu->uiMsgType = ENUM_MSG_TYPE_RENAME_FILE_RESPOND;
                    if (ret)
                    {
                        strcpy(respdu->caData, RENAME_FILE_OK);
                    }
                    else
                    {
                        strcpy(respdu->caData, RENAME_FILE_FAILURED);
                    }

                    write((char*)respdu, respdu->uiPDULen);
                    free(respdu);
                    respdu = NULL;

                    break;
                }
                case ENUM_MSG_TYPE_ENTER_DIR_REQUEST:
                {
                    char caEnterName[32] = {'\0'};
                    strncpy(caEnterName, pdu->caData, 32);

                    char *pPath = new char[pdu->uiMsgLen];
                    memcpy(pPath, pdu->caMsg, pdu->uiMsgLen);

                    QString strPath = QString("%1/%2").arg(pPath).arg(caEnterName);

                    qDebug() << strPath;

                    QFileInfo fileInfo(strPath);
                    PDU *respdu = NULL;
                    if (fileInfo.isDir())
                    {
                        QDir dir(strPath);
                        QFileInfoList fileInfoList = dir.entryInfoList();
                        int iFileCount = fileInfoList.size();
                        respdu = mkPDU(sizeof(FileInfo)*iFileCount);
                        respdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FILE_RESPOND;
                        FileInfo *pFileInfo = NULL;
                        QString strFileName;
                        for (int i=0; i<iFileCount; i++)
                        {
                            pFileInfo = (FileInfo*)(respdu->caMsg)+i;
                            strFileName = fileInfoList[i].fileName();

                            memcpy(pFileInfo->caFileName, strFileName.toStdString().c_str(), strFileName.size());
                            if (fileInfoList[i].isDir())
                            {
                                pFileInfo->iFileType = 0;
                            }
                            else if (fileInfoList[i].isFile())
                            {
                                pFileInfo->iFileType = 1;
                            }
                        }
                        write((char*)respdu, respdu->uiPDULen);
                        free(respdu);
                        respdu = NULL;
                    }
                    else if (fileInfo.isFile())
                    {
                        respdu = mkPDU(0);
                        respdu->uiMsgType = ENUM_MSG_TYPE_ENTER_DIR_RESPOND;
                        strcpy(respdu->caData, ENTER_DIR_FAILURED);

                        write((char*)respdu, respdu->uiPDULen);
                        free(respdu);
                        respdu = NULL;
                    }

                    break;
                }
                case ENUM_MSG_TYPE_DEL_FILE_REQUEST:
                {
                    char caName[32] = {'\0'};
                    strcpy(caName, pdu->caData);
                    char *pPath = new char[pdu->uiMsgLen];
                    memcpy(pPath, pdu->caMsg, pdu->uiMsgLen);
                    QString strPath = QString("%1/%2").arg(pPath).arg(caName);
                    qDebug() << strPath;

                    QFileInfo fileInfo(strPath);
                    bool ret = false;
                    if (fileInfo.isDir())
                    {
                        ret = false;
                    }
                    else if (fileInfo.isFile())  //常规文件
                    {
                        QDir dir;
                        ret = dir.remove(strPath);
                    }
                    PDU *respdu = NULL;
                    if (ret)
                    {
                        respdu = mkPDU(strlen(DEL_FILE_OK)+1);
                        respdu->uiMsgType = ENUM_MSG_TYPE_DEL_FILE_RESPOND;
                        memcpy(respdu->caData, DEL_FILE_OK, strlen(DEL_FILE_OK));
                    }
                    else
                    {
                        respdu = mkPDU(strlen(DEL_FILE_FAILURED)+1);
                        respdu->uiMsgType = ENUM_MSG_TYPE_DEL_FILE_RESPOND;
                        memcpy(respdu->caData, DEL_FILE_FAILURED, strlen(DEL_FILE_FAILURED));
                    }

                    write((char*)respdu, respdu->uiPDULen);
                    free(respdu);
                    respdu = NULL;
                    break;
                }
                case ENUM_MSG_TYPE_UPLOAD_FILE_REQUEST:
                {
                    char caFileName[32] = {'\0'};
                    qint64 fileSize = 0;
                    sscanf(pdu->caData, "%s %lld", caFileName, &fileSize);
                    char *pPath = new char[pdu->uiMsgLen];
                    memcpy(pPath, pdu->caMsg, pdu->uiMsgLen);
                    QString strPath = QString("%1/%2").arg(pPath).arg(caFileName);
                    qDebug() << strPath;
                    delete []pPath;
                    pPath = NULL;

                    m_file.setFileName(strPath);
                    //以只写的方式打开文件，若文件不存在，则会自动创建文件
                    if (m_file.open(QIODevice::WriteOnly))
                    {
                        m_bUpload = true;
                        m_iTotal = fileSize;
                        m_iRecved = 0;
                    }

                    break;
                }
                case ENUM_MSG_TYPE_DOWNLOAD_FILE_REQUEST:
                {
                    char caFileName[32] = {'\0'};
                    strcpy(caFileName, pdu->caData);
                    char *pPath = new char[pdu->uiMsgLen];
                    memcpy(pPath, pdu->caMsg, pdu->uiMsgLen);
                    QString strPath = QString("%1/%2").arg(pPath).arg(caFileName);
                    qDebug() << strPath;
                    delete []pPath;
                    pPath = NULL;

                    QFileInfo fileInfo(strPath);
                    qint64 fileSize = fileInfo.size();
                    PDU *respdu = mkPDU(0);
                    respdu->uiMsgType = ENUM_MSG_TYPE_DOWNLOAD_FILE_RESPOND;
                    sprintf(respdu->caData, "%s %lld", caFileName, fileSize);

                    write((char*)respdu, respdu->uiPDULen);
                    free(respdu);
                    respdu = NULL;

                    m_file.setFileName(strPath);
                    m_file.open(QIODevice::ReadOnly);
                    m_pTimer->start(1000);

                    break;
                }
                case ENUM_MSG_TYPE_SHARE_FILE_REQUEST:
                {
                    char caSendName[32] = {'\0'};
                    int num = 0;
                    sscanf(pdu->caData, "%s%d", caSendName, &num);
                    int size = num*32;
                    PDU *respdu = mkPDU(pdu->uiMsgLen-size);
                    respdu->uiMsgType = ENUM_MSG_TYPE_SHARE_FILE_NOTE;
                    strcpy(respdu->caData, caSendName);
                    memcpy(respdu->caMsg, (char*)(pdu->caMsg)+size, pdu->uiMsgLen-size);

                    char caRecvName[32] = {'\0'};
                    for (int i=0; i<num; i++)
                    {
                        memcpy(caRecvName, (char*)(pdu->caMsg)+i*32, 32);
                        MyTcpServer::getInstance().resend(caRecvName, respdu);
                    }
                    free(respdu);
                    respdu = NULL;

                    respdu = mkPDU(0);
                    respdu->uiMsgType = ENUM_MSG_TYPE_SHARE_FILE_RESPOND;
                    strcpy(respdu->caData, "share file ok");
                    write((char*)respdu, respdu->uiPDULen);
                    free(respdu);
                    respdu = NULL;

                    break;
                }
                case ENUM_MSG_TYPE_SHARE_FILE_NOTE_RESPOND:
                {
                    QString strRecvPath = QString("./%1").arg(pdu->caData);
                    QString strShareFilePath = QString("%1").arg((char*)(pdu->caMsg));
                    int index = strShareFilePath.lastIndexOf('/');
                    QString strFileName = strShareFilePath.right(strShareFilePath.size()-index-1);
                    strRecvPath = strRecvPath+'/'+strFileName;

                    QFileInfo fileInfo(strShareFilePath);
                    if (fileInfo.isFile())
                    {
                        QFile::copy(strShareFilePath, strRecvPath);
                    }
                    else if (fileInfo.isDir())
                    {
                        copyDir(strShareFilePath, strRecvPath);
                    }
                    break;
                }
                case ENUM_MSG_TYPE_MOVE_FILE_REQUEST:
                {
                    char caFileName[32] = {'\0'};
                    int srcLen = 0;
                    int destLen = 0;
                    sscanf(pdu->caData, "%d%d%s", &srcLen, &destLen, caFileName);

                    char *pSrcPath = new char[srcLen+1];
                    char *pDestPath = new char[destLen+1+32];
                    memset(pSrcPath, '\0', srcLen+1);
                    memset(pDestPath, '\0', destLen+1+32);

                    memcpy(pSrcPath, pdu->caMsg, srcLen);
                    memcpy(pDestPath, (char*)(pdu->caMsg)+(srcLen+1), destLen);

                    PDU *respdu = mkPDU(0);
                    respdu->uiMsgType = ENUM_MSG_TYPE_MOVE_FILE_RESPOND;
                    QFileInfo fileInfo(pDestPath);
                    if (fileInfo.isDir())
                    {
                        strcat(pDestPath, "/");
                        strcat(pDestPath, caFileName);

                        bool ret = QFile::rename(pSrcPath, pDestPath);
                        if (ret)
                        {
                            strcpy(respdu->caData, MOVE_FILE_OK);
                        }
                        else
                        {
                            strcpy(respdu->caData, COMMON_ERR);
                        }
                    }
                    else if (fileInfo.isFile())
                    {
                        strcpy(respdu->caData, MOVE_FILE_FAILURED);
                    }

                    write((char*)respdu, respdu->uiPDULen);
                    free(respdu);
                    respdu = NULL;

                    break;
                }
                default:
                    break;
                }

                free(pdu);
                pdu = NULL;
            }
            else
            {
                PDU *respdu = NULL;
                respdu = mkPDU(0);
                respdu->uiMsgType = ENUM_MSG_TYPE_UPLOAD_FILE_RESPOND;

                QByteArray buff = readAll();
                m_file.write(buff);
                m_iRecved += buff.size();
                if (m_iTotal == m_iRecved)
                {
                    m_file.close();
                    m_bUpload = false;

                    strcpy(respdu->caData, UPLOAD_FILE_OK);
                    write((char*)respdu, respdu->uiPDULen);
                    free(respdu);
                    respdu = NULL;
                }
                else if (m_iTotal < m_iRecved)
                {
                    m_file.close();
                    m_bUpload = false;
                    strcpy(respdu->caData, UPLOAD_FILE_FAILURED);

                    write((char*)respdu, respdu->uiPDULen);
                    free(respdu);
                    respdu = NULL;
                }

            }
}

void mytcpsocket::clientOffline()
{
    QpeDB::getInstance().handexit(m_strName.toStdString().c_str());
    emit offline(this);
}

void mytcpsocket::sendFileToClient()
{
    char *pData = new char[4096];
    qint64 ret = 0;
    while (true)
    {
        ret = m_file.read(pData, 4096);
        if (ret > 0 && ret <= 4096)
        {
            write(pData, ret);
        }
        else if (0 == ret)
        {
            m_file.close();
            break;
        }
        else if (ret < 0)
        {
            qDebug() << "发送文件内容给客户端过程中失败";
            m_file.close();
            break;
        }
    }
    delete []pData;
    pData = NULL;
}


