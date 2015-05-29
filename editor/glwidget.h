#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GLEW_STATIC
#include "GL/glew.h"

#include <QOpenGLWidget>
#include <QMouseEvent>
// #include <QOpenGLFunctions>

// #include "camera.h"

#include "scene.h"

class GLWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    QString getOpenGLVersion() const;

public slots:
    void cleanup();
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void addObject();

signals:
    // signaling rotation from mouse movement.
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:

    void draw();

    int xRot;
    int yRot;
    int zRot;

    Hodhr::Scene *scene;
    Hodhr::GameObject *plane = 0;

    QPoint lastPos;

};

#endif // GLWIDGET_H
