#ifndef SPIXD_H
#define SPIXD_H

#include <QWidget>
#include <QSpinBox>
#include <QSlider>
class spixd : public QWidget
{
    Q_OBJECT
public:
    explicit spixd(QWidget *parent = nullptr);
private:
    QSpinBox *spin;
    QSlider * slider;
signals:

};

#endif // SPIXD_H
