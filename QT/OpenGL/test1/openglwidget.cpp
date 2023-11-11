#include "openglwidget.h"

openglwidget::openglwidget(QWidget *parent) : QOpenGLWidget(parent)
{

}

void openglwidget::initializeGL()
{
    initializeOpenGLFunctions();
}

void openglwidget::resizeGL(int w, int h)
{

}

void openglwidget::paintGL()
{
    glClearColor(0.2f,0.3f,0.3f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
