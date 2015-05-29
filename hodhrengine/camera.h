#ifndef CAMERA_H
#define CAMERA_H

#include "behavior.h"
#include "color.h"
//#include "rendertexture.h"

#include <glm/glm.hpp>

#include <vector>

namespace Hodhr {

class Color;
class RenderTexture;

class Camera : public Behavior
{
public:

    typedef enum {
        RenderForward,
        RenderDeferredLighting,
        RenderDeferredShading
    } RenderingPath;

    typedef enum  {
        BEFORE_DEPTH_TEXTURE,
        AFTER_DEPTH_TEXTURE,
        BEFORE_GBUFFER,
        AFTER_GBUFFER,
        BEFORE_FINAL_PASS,
        AFTER_FINAL_PASS
    } CameraEvent;


    Camera(const GameObject& gameObject, int width, int height);
    ~Camera();

    void resetProjectionMatrix();
    void render();
    glm::mat4 projectionMatrix() const;
    glm::mat4 viewMatrix() const;

    static std::vector<Camera*> & allCameras();
    static Camera * current();
    static void setCurrent(Camera *camera);

    // public member variables

protected:

    /**
     * @brief List of references to all the cameras.
     */
    static std::vector<Camera*> mAllCameras;


    int width;

    int height;

    Color backgroundColor;

    bool useOcclusionCulling;

    float fieldOfView;

    float velocity;

    float aspect;

    float near;
    float far;

    RenderingPath renderingPath;

    RenderTexture * targetTexture;

    glm::mat4 mProjectionMatrix; // projection matrix
    glm::mat4 mViewMatrix;

    static Camera * mCurrent;


};

}

#endif // CAMERA_H
