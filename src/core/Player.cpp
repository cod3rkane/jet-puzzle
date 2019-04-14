#include "Player.h"

Core::Player::Player() {

}

Core::Player::~Player() {

}

void Core::Player::render(SDL_Renderer* renderer) {
    this->sprite->render(renderer);
}

void Core::Player::updateState(double dt) {
  double vel = this->velocity * (dt / 1000.f);
  glm::ivec2 pos = glm::ivec2(this->position.x + vel, this->position.y + vel);

  if (pos.x + this->sprite->width >= this->window_settigs->width) {
    // do nothing
  } else if (pos.y + this->sprite->height >= this->window_settigs->height) {
    // do nothing
  } else if (pos.x <= 0.0f) {
    // do nothing
  } else if (pos.y <= 0.0f) {
    // do nothing
  } else {
    this->setPosition(pos);
  }
}

void Core::Player::setPosition(glm::ivec2 position) {
  this->position = position;
  this->sprite->setPosition(position);
}

void Core::Player::setRotation(double rotation) {
  this->rotation = rotation;
}

void Core::Player::setScale(glm::vec3 scale) {
  this->scale = scale;
}

