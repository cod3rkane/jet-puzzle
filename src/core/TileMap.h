#ifndef CORE_TILE_MAP_H
#define CORE_TILE_MAP_H

#include <iostream>
#include "Object.h"
#include "Sprite.h"
#include "Tile.h"

namespace Core {
  class TileMap : public Core::Object {
  public:
    std::string sprite_path;
    std::string level;

    TileMap();
    TileMap(std::string sprite_path);
    ~TileMap();
    void render(SDL_Renderer* renderer);
    void updateState(double dt, const Uint8* keyboard_state);
    void setPosition(glm::ivec2 position);
    void setRotation(double rotation);
    void setScale(glm::vec3 scale);
  };
};

#endif

