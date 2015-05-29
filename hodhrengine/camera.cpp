#include "camera.h"
#include "debug.h"
#include "behavior.h"
#include "color.h"
#include "rendertexture.h"
#include "mesh.h"
#include "graphics.h"
#include "object.h"
#include "gameobject.h"
#include "meshfilter.h"
#include "renderer.h"
#include "meshrenderer.h"
#include "scene.h"

#define GLM_FORCE_RADIANS

#include "glm/gtc/constants.hpp"
#include "glm/gtx/transform.hpp"

using namespace Hodhr;

std::vector<Camera*> Camera::mAllCameras;
Camera * Camera::mCurrent = NULL;


Camera::Camera(const GameObject& gameObject, int width, int height)
    : Behavior(gameObject), width(width), height(height),
      near(0.1), far(100.0f)
{
    aspect = (float)width/(float)height;
    fieldOfView = 45.0f;

    mAllCameras.push_back(this);

    backgroundColor = Color::DarkGrey();


    Debug::log("Graphics", "Added a camera");

}

Camera::~Camera()
{

}

glm::mat4 Camera::projectionMatrix() const
{
    return mProjectionMatrix;
}

glm::mat4 Camera::viewMatrix() const
{
    return mViewMatrix;
}

Camera * Camera::current()
{

    if (mCurrent == NULL) {
        Debug::log("Camera", "No current camera is bound!");
    }
    return mCurrent;
}

void Camera::setCurrent(Camera *camera)
{

    Debug::log("Camera", "Setting a new current camera");


    mCurrent = camera;
}


void Camera::resetProjectionMatrix()
{
    mViewMatrix = glm::lookAt(
                transform().position(),
                transform().position()+transform().direction(),
                transform().up());

    mProjectionMatrix = glm::perspective(
                fieldOfView,
                aspect,
                near,
                far);
}

void Camera::render()
{

    const GLfloat r = backgroundColor.red();
    const GLfloat g = backgroundColor.green();
    const GLfloat b = backgroundColor.blue();
    const GLfloat a = backgroundColor.alpha();

    Graphics::checkErrors("Camera prepare render.");

    glClearColor(r,
                 g,
                 b,
                 a);

       glEnable(GL_DEPTH_TEST);
       glEnable(GL_DEPTH_CLAMP);
       glDepthFunc(GL_LESS);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    std::vector<GameObject*>::const_iterator it;


    Scene *scene = Scene::GetCurrent();
    const std::vector<GameObject*> objects = scene->GetGameObjects();


    for (it = objects.begin();it!=objects.end();it++)
    {

        GameObject *o = (GameObject*) *it;

        MeshRenderer *renderer = (MeshRenderer*) o->GetComponent<MeshRenderer>();
        if (renderer == NULL)
        {
            continue;
        }

        const Material *mat = renderer->material;
        MeshFilter *mf = (MeshFilter*) o->GetComponent<MeshFilter>();
        if (mf) {
            Graphics::drawMesh(*mf->mesh(),o->transform()->position(),
                               o->transform()->rotation(),
                               *mat);
        }




    }
}

std::vector<Camera*> & Camera::allCameras()
{
    return mAllCameras;
}


