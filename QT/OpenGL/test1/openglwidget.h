#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
class openglwidget : public QOpenGLWidget,public QOpenGLFunctions_3_3_Core
{

public:
    explicit openglwidget(QWidget *parent = nullptr);

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
signals:

};

#endif // OPENGLWIDGET_H
