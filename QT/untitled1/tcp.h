#ifndef TCP_H
#define TCP_H

#include <QTcpSocket>
#include <QObject>

class tcp : public QTcpSocket
{
public:
    explicit tcp(QObject *parent = nullptr);
};

#endif // TCP_H
