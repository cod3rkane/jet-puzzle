#ifndef CORE_TILE_H
#define CORE_TILE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "Object.h"
#include "Sprite.h"

namespace Core {
  class Tile : public Core::Object {
    SDL_Rect box;
    int type;
    Core::Sprite sprite;
  public:
    Tile(int x, int y, int type, Core::Sprite sprite);
    ~Tile();
    SDL_Rect getBox();
    int getType();
    void render(SDL_Renderer* renderer);
    void updateState(double dt, const Uint8* keyboard_state);
    void setPosition(glm::ivec2 position);
    void setRotation(double rotation);
    void setScale(glm::vec3 scale);
    int getWidth();
    int getHeight();
  };
};

#endif

