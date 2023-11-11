#ifndef DATACONFIG_H
#define DATACONFIG_H
#include <QMap>
#include <QVector>
#include <QObject>

class dataconfig : public QObject
{
    Q_OBJECT
public:
    explicit dataconfig(QObject *parent = nullptr);
    QMap<int,QVector<QVector<int>>> mData;
signals:

};

#endif // DATACONFIG_H
