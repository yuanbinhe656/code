#ifndef FRIENDLIST_H
#define FRIENDLIST_H

#include <QWidget>
#include <online.h>
#include "QVBoxLayout"
#include "QHBoxLayout"
#include <QListWidget>
namespace Ui {
class friendlist;
}

class friendlist : public QWidget
{
    Q_OBJECT

public:
    explicit friendlist(QWidget *parent = nullptr);
    ~friendlist();
    void showAllOnlinUsr(PDU *pdu);
    void updateFriendList(PDU *pdu);
    void updateGroupMsg(PDU *pdu);

    QString m_strSerrchName;
    QListWidget *getFriendList();


public slots:

private slots:
    void on_delFriend_pb_clicked();

    void on_flush_pb_clicked();

    void on_showOnline_pb_clicked();

    void on_serchFriend_pb_clicked();

    void on_sendMsg_pb_clicked();

    void on_chat_pb_clicked();


private:
    Ui::friendlist *ui;

    online *m_pOnline;
};

#endif // FRIENDLIST_H
