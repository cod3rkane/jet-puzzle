#include "TileMap.h"

Core::TileMap::TileMap() {
}

Core::TileMap::~TileMap() {

}

void Core::TileMap::render(SDL_Renderer *renderer) {
  this->sprite->render(renderer);
}

void Core::TileMap::updateState(double dt, const Uint8 *keyboard_state) {

}

void Core::TileMap::setPosition(glm::ivec2 position) {}

void Core::TileMap::setRotation(double rotation) {}

void Core::TileMap::setScale(glm::vec3 scale) {}
