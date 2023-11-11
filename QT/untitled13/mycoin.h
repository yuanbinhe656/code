#ifndef MYCOIN_H
#define MYCOIN_H
#include<QPushButton>
#include <QWidget>

class mycoin : public QPushButton
{
    Q_OBJECT
public:
   // explicit mycoin(QWidget *parent = nullptr);
    mycoin(QString btnImg);
    int posX;
    int posY;
    bool flag;
    bool isAnimation = false;
    int min = 1;
    int max = 8;
    bool notPress = false;
    void changeFlag(int ms);
    QTimer *timer1;
    QTimer *timer2;
    void mousePressEvent(QMouseEvent *e);

signals:

};

#endif // MYCOIN_H
