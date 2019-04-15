#include "Player.h"

Core::Player::Player() {
}

Core::Player::~Player() {

}

void Core::Player::render(SDL_Renderer* renderer) {
    this->sprite->render(renderer);
}

void Core::Player::move(double dt, const Uint8 *key) {
  double vel = this->velocity * (dt / 1000.f);
  glm::ivec2 pos;

  if (key[SDL_SCANCODE_A]) {
    pos = glm::ivec2(this->position.x - vel, this->position.y);
  } else if (key[SDL_SCANCODE_D]) {
    pos = glm::ivec2(this->position.x + vel, this->position.y);
  } else if (key[SDL_SCANCODE_S]) {
    pos = glm::ivec2(this->position.x, this->position.y + vel);
  } else if (key[SDL_SCANCODE_W]) {
    pos = glm::ivec2(this->position.x, this->position.y - vel);
  } else {
    pos = this->position;
  }

  this->setPosition(pos);
  this->last_keyboard_state = key;
}

void Core::Player::updateState(double dt, const Uint8* keyboard_state) {
  if (this->isMoving) {
    this->move(dt, this->last_keyboard_state);
  } else {
    this->isMoving = true;
    this->move(dt, keyboard_state);
  }

  // if (pos.x + this->sprite->width >= this->window_settigs->width) {
  //   // do nothing
  // } else if (pos.y + this->sprite->height >= this->window_settigs->height) {
  //   // do nothing
  // } else if (pos.x <= 0.0f) {
  //   // do nothing
  // } else if (pos.y <= 0.0f) {
  //   // do nothing
  // } else {
  //   this->setPosition(pos);
  // }
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

