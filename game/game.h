#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "gameobject.h"
#include "texture2d.h"


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

    Hodhr::GameObject * plane;

    Hodhr::Texture2D * cubeTexture;
};

#endif // GAME_H
