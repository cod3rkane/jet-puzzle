#include "Tile.h"

Core::Tile::Tile(int x, int y, int width, int height, int type) {
  this->box = { x, y, width, height };
  this->type = type;
}

Core::Tile::~Tile() {

}


SDL_Rect Core::Tile::getBox() {
  return this->box;
}

int Core::Tile::getType() {
  return this->type;
}

void Core::Tile::render(SDL_Renderer* renderer) {

}


void Core::Tile::updateState(double dt, const Uint8* keyboard_state) {

}

void Core::Tile::setPosition(glm::ivec2 position) {

}

void Core::Tile::setRotation(double rotation) {

}

void Core::Tile::setScale(glm::vec3 scale) {

}
