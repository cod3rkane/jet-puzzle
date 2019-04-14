#ifndef CORE_SPRITE_H
#define CORE_SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Texture.h"

namespace Core {
  class Sprite : public Core::Texture {
  public:
    SDL_Rect* clip;
    int width;
    int height;

    Sprite(std::string path, SDL_Renderer* renderer, int width, int height);
    void render(SDL_Renderer* renderer) override;
  };
};

#endif

