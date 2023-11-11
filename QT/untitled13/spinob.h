#ifndef SPINOB_H
#define SPINOB_H

#include <QObject>
#include <QSpinBox>
#include <QSlider>
class Spinob : public QObject
{
    Q_OBJECT
public:
    explicit Spinob(QObject *parent = nullptr);
private:

QSpinBox *spin;
QSlider * slider;
signals:

};

#endif // SPINOB_H
