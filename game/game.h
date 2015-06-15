#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "gameobject.h"
#include "texture2d.h"
#include "material.h"
#include "mesh.h"


class Game
{
public:
    Game();

    void init();
    void run();
    void cleanup();

private:
    SDL_Window* mainwindow = NULL;
    SDL_GLContext maincontext;

    Hodhr::GameObject * cubeObject;

    Hodhr::Texture2D * cubeTexture;
    Hodhr::Texture2D * cubeNormalTexture;

    Hodhr::Material * cubeMaterial;

    Hodhr::GameObject * catObject;


};

#endif // GAME_H
