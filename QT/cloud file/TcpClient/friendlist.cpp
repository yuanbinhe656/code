#include "friendlist.h"
#include "ui_friendlist.h"
#include "protocol.h"
#include <QInputDialog>
#include <QMessageBox>
#include <tcpclient.h>

friendlist::friendlist(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::friendlist)
{
        ui->setupUi(this);

    m_pOnline = new online;






}

friendlist::~friendlist()
{
    delete ui;
}

void friendlist::showAllOnlinUsr(PDU *pdu)
{
    if(pdu == nullptr)
    {
        return ;
    }
    m_pOnline->showUsr(pdu);
}

void friendlist::updateFriendList(PDU *pdu)
{
    if(pdu == nullptr)
    {
        return ;
    }
    uint uiSize = pdu->uiMsgLen / 32;
    char caName[32] = {'\0'};
    for(uint i =0 ;i < uiSize ;i++)
    {
        memcpy(caName ,pdu->caData + i * 32,32);
        ui->friendlist_list->addItem(caName);
    }
}

void friendlist::updateGroupMsg(PDU *pdu)
{
    QString strMsg = QString("%1 says : %2").arg(pdu->caData).arg((char *)pdu->caMsg);
    ui->show_Msg_text->append(strMsg);
}

QListWidget *friendlist::getFriendList()
{
        return ui->friendlist_list;
}






void friendlist::on_delFriend_pb_clicked()
{
    if(ui->friendlist_list->currentItem() != NULL)
    {
        QString strFirendName = ui->friendlist_list->currentItem()->text();
        QString strselfName = TcpClient::getInstance().loginName();
        PDU * pdu = mkPDU(0);
        memcpy(pdu->caData,strselfName.toStdString().c_str(),strselfName.size());
        memcpy(pdu->caData + 32 , strFirendName.toStdString().c_str(),strFirendName.size());
        pdu->uiMsgType = ENUM_MSG_TYPE_DEL_FILE_REQUEST;
        TcpClient::getInstance().getTcpSocket().write((char *)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = nullptr;
    }
}


void friendlist::on_flush_pb_clicked()
{
    ui->friendlist_list->clear();
     QString strName = TcpClient::getInstance().loginName();
     PDU *pdu = mkPDU(0);
     pdu->uiMsgType = ENUM_MSG_TYPE_FLUSH_FRIEND_REQUEST;
     memcpy(pdu->caData,strName.toStdString().c_str(),strName.size());
     TcpClient::getInstance().getTcpSocket().write((char *)pdu,pdu->uiPDULen);
     free(pdu);
     pdu = nullptr;
}


void friendlist::on_showOnline_pb_clicked()
{
    if(m_pOnline->isHidden())
    {
        m_pOnline->show();
        this->hide();
        PDU * pdu = mkPDU(0);
        pdu->uiMsgType = ENUM_MSG_TYPE_ALL_ONLINE_REQUEST;
        TcpClient ::getInstance().getTcpSocket().write((char*)pdu ,pdu->uiPDULen);
        free(pdu) ;
        pdu = nullptr;
    }
    else {
        m_pOnline->hide();
    }
}


void friendlist::on_serchFriend_pb_clicked()
{
    m_strSerrchName = QInputDialog::getText(this,"搜索","用户名");
    if(m_strSerrchName.isEmpty())
    {
        return;
    }
   qDebug()<<m_strSerrchName;
   PDU * pdu = mkPDU(0);
   pdu->uiMsgType = ENUM_MSG_TYPE_SEARCH_USR_REQUEST;
   memcpy(pdu->caData,m_strSerrchName.toStdString().c_str(),m_strSerrchName.size());
   TcpClient::getInstance().getTcpSocket().write((char *)pdu,pdu->uiPDULen);
   free(pdu);
   pdu = nullptr;
}


void friendlist::on_sendMsg_pb_clicked()
{
    QString strMsg = ui->inputTX->text();
    if(!strMsg.isEmpty())
    {
        PDU * pdu =mkPDU(strMsg.size() + 1);
        pdu->uiMsgType = ENUM_MSG_TYPE_GROUP_CHAT_REQUEST;
        QString strName = TcpClient::getInstance().loginName();
        memcpy(pdu->caData,strName.toStdString().c_str(),strName.size());
        memcpy(pdu->caMsg,strMsg.toStdString().c_str(),strMsg.size());
        TcpClient::getInstance().getTcpSocket().write((char *)pdu,pdu->uiPDULen);
        free(pdu);
        pdu = nullptr;
    }
}


void friendlist::on_chat_pb_clicked()
{
    if(ui->friendlist_list->currentItem()!= NULL)
    {
        QString strFirendName = ui->friendlist_list->currentItem()->text();

        QString strselfName = TcpClient::getInstance().loginName();

    }
}



