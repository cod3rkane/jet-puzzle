#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "core/Window.h"

class Game {
    SDL_Window* window;
    SDL_GLContext context;
    bool isRunning;
public:
    Game(const Core::Window* window_settings);
    ~Game();
    void main_loop();
};

#endif

