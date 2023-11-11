#include "button.h"
#include <QDebug>
#include <QPropertyAnimation>
//Button::Button(QWidget *parent)
//    : QWidget{parent}
//{

//}
Button::Button(QString normalImgPath,QString pressedImgPath )

{
    this->normalImgPath = normalImgPath;
    this->pressedImgPath = pressedImgPath;
    QPixmap pix;
    if(!pix.load(this->normalImgPath))
    {
       qDebug()<<normalImgPath<<"图片加载失败";
        return ;
    }
    this->resize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
  this->setIconSize(pix.size());

}
// 下坠
void Button:: downBounce()
{
QPropertyAnimation * ani = new QPropertyAnimation(this,"geometry");
ani->setDuration(200);
ani->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
ani->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
ani->setEasingCurve(QEasingCurve::OutBounce);
ani->start();
}
// 上弹
void Button::upBounce()
{
    QPropertyAnimation * ani = new QPropertyAnimation(this,"geometry");
    ani->setDuration(200);
    ani->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    ani->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    ani->setEasingCurve(QEasingCurve::OutBounce);
    ani->start();
}
// 鼠标按下事件
void Button::mousePressEvent(QMouseEvent *e)
{
    if(this->pressedImgPath!=""){
          this->setStyleSheet("background:rgb(255,150,128)");
            QPixmap pix;
            if(!pix.load(this->pressedImgPath))
    {
          qDebug()<<this->pressedImgPath<<"图片加载失败";
            return;
}
            this->resize(pix.width(),pix.height());
        //    this->setStyleSheet("QPushButton{border:0px}");
            this->setIcon(pix);
          this->setIconSize(pix.size());
}
    return QPushButton::mousePressEvent(e);

}
//// 鼠标释放事件
void Button::mouseReleaseEvent(QMouseEvent *e)
{
            if(this->normalImgPath!=""){
                //   this->setStyleSheet("background:rgb(255,150,128)");
                    QPixmap pix;
                    if(!pix.load(this->normalImgPath))
            {
                  qDebug()<<this->normalImgPath<<"图片加载失败";
                    return;
        }
                    this->resize(pix.width(),pix.height());
                    this->setStyleSheet("QPushButton{border:0px}");
                    this->setIcon(pix);
                  this->setIconSize(pix.size());
        }
            return QPushButton::mouseReleaseEvent(e);
}
