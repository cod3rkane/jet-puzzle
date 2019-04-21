#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "core/Window.h"
#include "core/Texture.h"
#include "core/Sprite.h"
#include "core/Player.h"
#include "core/Clock.h"
#include "core/TileMap.h"
#include "core/Tile.h"

class Game {
  SDL_Window* window;
  SDL_GLContext context;
  SDL_Renderer* renderer;
  bool isRunning;
  const Uint8* keyboard_state;
  const Core::Window* window_settings;
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;
  Uint32 frameStart;
  int frameTime;
public:
  Game(const Core::Window* window_settings);
  ~Game();
  void main_loop();
};

#endif

