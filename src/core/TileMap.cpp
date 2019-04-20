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
  for (Core::Tile &tile : this->tiles) {
    tile.setPosition(glm::ivec2(tile.getType() * tile.getWidth(), 0));
    tile.render(renderer);
  }
}

void Core::TileMap::updateState(double dt, const Uint8 *keyboard_state) {

}

void Core::TileMap::setPosition(glm::ivec2 position) {}

void Core::TileMap::setRotation(double rotation) {}

void Core::TileMap::setScale(glm::vec3 scale) {}

void Core::TileMap::setGrid(int x, int y) {
  this->grid_x = x;
  this->grid_y = y;
}

