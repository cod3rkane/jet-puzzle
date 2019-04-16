#include "Player.h"

Core::Player::Player() {
}

Core::Player::~Player() {

}

void Core::Player::render(SDL_Renderer* renderer) {
    this->sprite->render(renderer);
}

void Core::Player::move(double dt, Core::Movement direction) {
  double vel = this->velocity * (dt / 1000.f);
  glm::ivec2 pos;

  switch (direction) {
  case Core::UP:
    pos = glm::ivec2(this->position.x, this->position.y - vel);
    break;
  case Core::RIGHT:
    pos = glm::ivec2(this->position.x + vel, this->position.y);
    break;
  case Core::DOWN:
    pos  = glm::ivec2(this->position.x, this->position.y + vel);
    break;
  case Core::LEFT:
    pos = glm::ivec2(this->position.x - vel, this->position.y);
    break;
  default:
    pos = this->position;
  }

  if (pos.x + this->sprite->width >= this->window_settigs->width) {
    // do nothing
    this->isMoving = false;
  } else if (pos.y + this->sprite->height >= this->window_settigs->height) {
    // do nothing
    this->isMoving = false;
  } else if (pos.x <= 0.0f) {
    // do nothing
    this->isMoving = false;
  } else if (pos.y <= 0.0f) {
    // do nothing
    this->isMoving = false;
  } else {
    this->setPosition(pos);
    this->last_keyboard_state = direction;
    this->isMoving = true;
  }
}

void Core::Player::updateState(double dt, const Uint8* keyboard_state) {
  if (this->isMoving) {
    this->move(dt, this->last_keyboard_state);
  } else {
    if (keyboard_state[SDL_SCANCODE_W]) {
      this->move(dt, Core::UP);
    } else if (keyboard_state[SDL_SCANCODE_D]) {
      this->move(dt, Core::RIGHT);
    } else if (keyboard_state[SDL_SCANCODE_S]) {
      this->move(dt, Core::DOWN);
    } else if (keyboard_state[SDL_SCANCODE_A]) {
      this->move(dt, Core::LEFT);
    }
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

