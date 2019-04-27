#ifndef CORE_TILE_MAP_H
#define CORE_TILE_MAP_H

#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <fstream>
#include <string>
#include <sstream>
#include "Object.h"
#include "Sprite.h"
#include "Tile.h"

namespace Core {
  struct vec2 {
    int x;
    int y;
  };

  class TileMap : public Core::Object {
    int grid_x;
    int grid_y;
  public:
    std::string sprite_path;
    std::vector<Core::Tile> tiles;

    TileMap();
    TileMap(std::string sprite_path, std::vector<Core::Tile> tiles);
    ~TileMap();
    void render(SDL_Renderer* renderer);
    void updateState(double dt, const Uint8* keyboard_state);
    void setPosition(glm::ivec2 position);
    void setRotation(double rotation);
    void setScale(glm::vec3 scale);
    void setGrid(int x, int y);
    static Core::vec2 getPosFromTileset(int index);
    static Core::TileMap fromFile(const GLchar* file, Core::Sprite sprite);
  };
};

#endif

