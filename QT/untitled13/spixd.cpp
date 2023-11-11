#include "spixd.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
spixd::spixd(QWidget *parent)
    : QWidget{parent}
{
    spin = new QSpinBox(this);
    slider = new QSlider(Qt::Horizontal,this);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spin);
    layout->addWidget(slider);
    setLayout(layout);
    //connect(spin,static_cast<void (QSpinBox::*)(int)>(&QSpinbox::valueChanged),slider,&QSlider::setValue);
    connect(spin,&QSpinBox::valueChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::valueChanged,spin,&QSpinBox::setValue);

}
