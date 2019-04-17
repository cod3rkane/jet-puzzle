#include "Tile.h"

Core::Tile::Tile(int x, int y, int type, Core::Sprite sprite) {
  this->box = { x, y, sprite.width, sprite.height };
  this->type = type;
  this->sprite = &sprite;
  this->sprite->clip = &this->box;
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
  this->sprite->render(renderer);
}


void Core::Tile::updateState(double dt, const Uint8* keyboard_state) {

}

void Core::Tile::setPosition(glm::ivec2 position) {
  this->position = position;
  this->sprite->setPosition(position);
}

void Core::Tile::setRotation(double rotation) {

}

void Core::Tile::setScale(glm::vec3 scale) {

}
