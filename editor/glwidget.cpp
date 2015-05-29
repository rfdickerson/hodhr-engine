#include "glwidget.h"
#include "debug.h"
#include "camera.h"
#include "material.h"
#include "shader.h"
#include "gameobject.h"
#include "rendertexture.h"
#include "resources.h"
#include "graphics.h"
#include "scene.h"
#include "light.h"
#include "color.h"

#include <QTimer>

#define GLEW_STATIC

using namespace Hodhr;

GLWidget::GLWidget(QWidget *parent)
    : QOpenGLWidget(parent),
      xRot(0),
      yRot(0),
      zRot(0)
{

}

GLWidget::~GLWidget()
{
    cleanup();
}

QSize GLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const
{
    return QSize(800, 600);
}

void GLWidget::initializeGL()
{

     // connect(context(), &QOpenGLContext::aboutToBeDestroyed, this, &GLWidget::cleanup);
        // glewExperimental = true;

     GLenum err = glewInit();
     if (err==GLEW_OK)
     {
         if (Debug::getInstance()) {
            Debug::getInstance()->addLog("Display", "GLEW Initialized successfully");
         }
     }

     // initializeOpenGLFunctions();
     glClearColor(1, 1, 1, 1);

     scene = new Scene;

     GameObject *cameraGameObject = new GameObject("The Camera");
     Hodhr::Camera *camera = new Hodhr::Camera(*cameraGameObject, 500,400);
     Hodhr::Camera::setCurrent( camera );
     camera->resetProjectionMatrix();
     camera->transform().translate(-5.0f,0.0f,0.0f);
     scene->AddGameObject(cameraGameObject);

     GameObject *lightGameObject = new GameObject("The Light");
     Light *lightComp = new Light(*lightGameObject);
     lightComp->setColor( Color::Yellow() );
     // light.transform.position =
     scene->AddGameObject(lightGameObject);

     //Hodhr::RenderTexture * renderTexture = Hodhr::RenderTexture::getTemporary(800,600,16);
     //renderTexture->create();

     // renderTexture->bindForWriting();
     //Hodhr::RenderTexture::active = renderTexture;
     //camera->targetTexture = renderTexture;

     Shader * phongShader = Resources::LoadShader("../Hodhr/resources/shaders/basic.sdr");
     phongShader->compile();

     //Shader* fragShader = Resources::loadShader("resources/shaders/geometry_pass.fs");
     //fragShader->compile();

     //Shader::find("Diffuse");
     Material *mat = new Material();
     mat->setShader( phongShader );

     //Shader::setGlobalColor("background", Color::pink());

     // plane->transform->translate(1,1,1);

      if (Debug::getInstance()) {
        Debug::getInstance()->addLog("Materials", "Added the phong material.");
      }
     Scene::SetCurrent(scene);

     // Hodhr::Camera::current()->render();

     // c.allCameras;
}

void GLWidget::cleanup()
{

    delete plane;

    makeCurrent();
    doneCurrent();
}

QString GLWidget::getOpenGLVersion() const
{
    return QString((char*)glewGetString(GLEW_VERSION));
}

void GLWidget::paintGL()
{
    makeCurrent();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    // glEnable(GL_DEPTH_TEST);
    // glEnable(GL_CULL_FACE);

    // Hodhr::Camera::current()->transform->rotate(0.1,xRot,yRot);

    if (plane) {
        plane->transform()->rotate(xRot,yRot,zRot);
    }

    Hodhr::Camera::current()->resetProjectionMatrix();
    Hodhr::Camera::current()->render();

    // Hodhr::RenderTexture::active->getNativeTextureID();

    scene->Render();

    // Deferred Shading Rendering Path

    // G-Buffer pass

    // Lighting pass

    // Debug::addLog("Draw", "rotation changed.");

}


void GLWidget::resizeGL(int w, int h)
{

    Hodhr::Camera::current()->resetProjectionMatrix();

}

void GLWidget::draw()
{

}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360 * 16)
        angle -= 360 * 16;
}

void GLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        update();
    }
}

void GLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        update();
    }
}

void GLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        update();
    }
}

void GLWidget::addObject()
{
    if (!plane) {
     plane = GameObject::createPrimitive(GAMEOBJECT_QUAD);
     scene->AddGameObject(plane);

     Hodhr::Camera::current()->transform().lookAt(*plane->transform(), glm::vec3(0,1,0));
    }
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{

    lastPos = event->pos();

}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton)
    {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();

}
