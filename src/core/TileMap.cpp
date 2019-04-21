#include "TileMap.h"

Core::TileMap::TileMap() {
}

Core::TileMap::TileMap(std::string sprite_path, std::vector<Core::Tile> tiles) {
  this->sprite_path = sprite_path;
  this->tiles = tiles;
}

Core::TileMap::~TileMap() {

}

void Core::TileMap::render(SDL_Renderer *renderer) {
  for (int y = 0; y < this->grid_y; y++) {
    for (int x = 0; x < this->grid_x; x++) {
      int index = x + (y * this->grid_x);
      glm::ivec2 const pos(
                     x * this->tiles[index].getWidth(),
                     y * this->tiles[index].getHeight()
                     );
      glm::ivec2 const finalPos(pos.x + this->position.x, pos.y + this->position.y);
      this->tiles[index].setPosition(finalPos);
      this->tiles[index].render(renderer);
    }
  }
}

void Core::TileMap::updateState(double dt, const Uint8 *keyboard_state) {

}

void Core::TileMap::setPosition(glm::ivec2 position) {
  this->position = position;
}

void Core::TileMap::setRotation(double rotation) {
  this->rotation = rotation;
}

void Core::TileMap::setScale(glm::vec3 scale) {
  this->scale = scale;
}

void Core::TileMap::setGrid(int x, int y) {
  this->grid_x = x;
  this->grid_y = y;
}

