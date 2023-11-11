#ifndef BUTTON_H
#define BUTTON_H
#include<QString>
#include <QPushButton>
#include <QWidget>

class Button : public QPushButton
{
    Q_OBJECT
public:
   // explicit Button(QWidget *parent = nullptr);
    Button(QString normalImgPath,QString pressedImgPath = "");
    // 下坠
    void downBounce();
    // 上弹
    void upBounce();

    // 正常显示的图片路径
    QString normalImgPath;
    // 按压时的图片路径
    QString pressedImgPath;

//    // 鼠标按下事件
    void mousePressEvent(QMouseEvent *e);
//    // 鼠标释放事件
    void mouseReleaseEvent(QMouseEvent *e);

signals:

public slots:

};


#endif // BUTTON_H
