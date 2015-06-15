#include "game.h"

#include <SDL2/SDL.h>

#include "scene.h"
#include "gameobject.h"
#include "camera.h"
#include "light.h"
#include "debug.h"
#include "shader.h"
#include "resources.h"
#include "material.h"
#include "graphics.h"
#include "consoledebug.h"
#include "meshrenderer.h"

const char * PROGRAM_NAME = "Hodhr Player";
const int HEIGHT = 720;
const int WIDTH = 1280;
const int FRAME_DELAY = 8;
const float SPEED = 0.4f;

using namespace Hodhr;

Game::Game()
{



}

void Game::init()
{


    int a;
    a = 3;

    Uint16 frame_target;

    //SDL_Window* mainwindow = NULL;
    //SDL_GLContext maincontext;
    SDL_DisplayMode target, closest;

    target.w = WIDTH;
     target.h = HEIGHT;
     target.format = 0;
     target.refresh_rate = 0;
     target.driverdata = 0;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) <0) {
        fprintf(stderr, "Could not initialize SDL\n");
      }

      if (SDL_GetClosestDisplayMode(0, &target, &closest)== NULL)
        {
          printf("\nNo suitable display mode was found!");
          return;
        }

      frame_target = 1.0f/((float)closest.refresh_rate)*1000;

        //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
        //SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
        SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

        // SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
        // SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);


        mainwindow = SDL_CreateWindow(PROGRAM_NAME,
                        SDL_WINDOWPOS_CENTERED,
                        SDL_WINDOWPOS_CENTERED,
                        WIDTH, HEIGHT,
                        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

      if( mainwindow == NULL )
          {
              printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
          }

      maincontext = SDL_GL_CreateContext(mainwindow);

      SDL_GL_MakeCurrent(mainwindow, maincontext);

      SDL_GL_SetSwapInterval(1);
    //  SDL_SetRelativeMouseMode(SDL_TRUE);

      glewExperimental = GL_TRUE;

      GLenum result = glewInit();
      if (result != GLEW_OK) {
          fprintf(stderr, "Problem initializing GLEW\n");
      }

      if (GLEW_VERSION_1_2) {
          fprintf(stderr, "Graphics successfully initialized\n");
          fprintf(stderr, "Version: %s\n", glGetString(GL_VERSION));
          fprintf(stderr, "Vendor: %s\n", glGetString(GL_VENDOR));
          fprintf(stderr, "Renderer: %s\n", glGetString(GL_RENDERER));
          fprintf(stderr, "Shading: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

      }

      Graphics::checkErrors("Finished loading GLEW.");

      ConsoleDebug * consoleDebug = new ConsoleDebug();
      Debug::setInstance(consoleDebug);



    Scene* scene = new Scene();

    GameObject * cameraGameObject = new GameObject("The Camera");
    Hodhr::Camera *camera = new Hodhr::Camera(*cameraGameObject, WIDTH, HEIGHT);
    Hodhr::Camera::setCurrent( camera );
    camera->resetProjectionMatrix();
    camera->transform().translate(7.0f,0.0f,0.0f);

    scene->AddGameObject(cameraGameObject);

    GameObject *lightGameObject = new GameObject("The Light");
    Light *lightComp = new Light(*lightGameObject);
    lightComp->setColor( Color::Yellow() );
    lightGameObject->transform()->translate(0,0,5);
    // light.transform.position =
    scene->AddGameObject(lightGameObject);

    Shader * phongShader = Resources::LoadShader("../../Hodhr/resources/shaders/phong.sdr");
    phongShader->compile();

    cubeMaterial = new Material();
    cubeMaterial->setShader( phongShader );

    //cubeObject = GameObject::createPrimitive(GAMEOBJECT_CUBE);
    //scene->AddGameObject(cubeObject);

    cubeTexture = Resources::LoadTexture("../../Hodhr/resources/images/torusdiffuse.dds");
    cubeNormalTexture = Resources::LoadTexture("../../Hodhr/resources/images/torus_n.dds");

    cubeMaterial->setMainTexture(cubeTexture);
    cubeMaterial->setTexture("_normaltex", cubeNormalTexture);

    catObject = GameObject::createFromFile("../../Hodhr/resources/models/torus.obj");
    scene->AddGameObject(catObject);

    MeshRenderer *renderer = catObject->GetComponent<MeshRenderer>();
    renderer->setMaterial(cubeMaterial);

    camera->transform().translate(5.0f,0.0f,0.0f);
    Hodhr::Camera::current()->transform().lookAt(*catObject->transform(), glm::vec3(0,1,0));

    Scene::SetCurrent(scene);

     //SDL_Delay( 2000 );
}

void Game::run()
{
    SDL_Event event;
    int done = 0;
       // int interval = 20;

       //  int x, y;

       Uint32 currentTick, targetTick;
       int lastTick = SDL_GetTicks();
       float dt;

       bool keysHeld[323] = {false};


       Graphics::checkErrors("Finished loading.");

       while (done == 0) {
           Camera * camera = Camera::current();
             currentTick = SDL_GetTicks();
             dt = static_cast<float>((currentTick-lastTick))*0.1f;

             // targetTick = currentTick + FRAME_DELAY;
             targetTick = currentTick + FRAME_DELAY;

             // waitTicks = (oldTicks + interval) - currentTick;
             // oldTicks = currentTick;

             while (SDL_PollEvent(&event))        {
               if ( event.type == SDL_MOUSEMOTION ) {
                 // x = event.motion.x;
                 // y = event.motion.y;


                 //camera.rotate(dt, event.motion.xrel, event.motion.yrel);

                   //camera->transform().rotate(0.1, event.motion.xrel, event.motion.yrel);
                   glm::vec3 offset(event.motion.yrel, 0, event.motion.xrel);
                   // offset *= dt;
                   offset *= 0.005;
                   catObject->transform()->rotate(offset, SPACE_SELF);
                   // camera->transform().rotate(offset, SPACE_SELF);
                   // camera->resetProjectionMatrix();

                   // char out [80];

                   /* sprintf(out, "Camera direction: %f, %f, %f",
                           camera->transform().direction()[0],
                           camera->transform().direction()[1],
                           camera->transform().direction()[2]);
                           */

                   /**
                   sprintf(out, "Plane rotation is: %f, %f, %f",
                           plane->transform()->rotation().x,
                           plane->transform()->rotation().y,
                           plane->transform()->rotation().z
                           );

                   Debug::getInstance()->addLog("Camera", out);

                   sprintf(out, "Offset is now %f, dt: %f", offset.x, dt);
                   Debug::getInstance()->addLog("Mouse", out);
                   **/

               }

               if (event.type == SDL_QUIT) { done = 1;}
               if (event.type == SDL_KEYDOWN) {
                 keysHeld[event.key.keysym.sym] = true;
               }
               if (event.type == SDL_KEYUP) {
                 keysHeld[event.key.keysym.sym] = false;
               }


             }

             if (keysHeld[SDLK_ESCAPE]) {
               done = 1;
             }
             if (keysHeld[SDLK_w]) {
                 camera->transform().translate(0.1,0,0);
                 char out [80];
                 sprintf(out, "Camera position: %f, %f, %f",
                         camera->transform().position()[0],
                         camera->transform().position()[1],
                         camera->transform().position()[2]);

                 // Debug::log("Camera", out);

               //camera.move(dt, SPEED);
             }
             if (keysHeld[SDLK_s]) {
               //camera.move(dt, -SPEED);
                 camera->transform().translate(-0.1,0,0);

                 char out [80];
                 sprintf(out, "Camera position: %f, %f, %f",
                         camera->transform().position()[0],
                         camera->transform().position()[1],
                         camera->transform().position()[2]);

                 // Debug::log("Camera", out);

             }


             /* draw the scene */

             if (camera) {
                camera->resetProjectionMatrix();
                camera->render();
             }

             //scene->Render();

             SDL_GL_SwapWindow(mainwindow);

             currentTick = SDL_GetTicks();
               if (targetTick > currentTick) {
                   SDL_Delay(targetTick-currentTick);
               }

             lastTick = currentTick;
           }
}

void Game::cleanup()
{

    delete catObject;
    delete cubeTexture;
    delete cubeMaterial;

    SDL_GL_DeleteContext(maincontext);
    SDL_DestroyWindow( mainwindow );

    Debug::deleteInstance();

    SDL_Quit();
}

