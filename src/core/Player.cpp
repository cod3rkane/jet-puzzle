#include "Player.h"

Core::Player::Player() {

}

Core::Player::~Player() {

}

void Core::Player::render(SDL_Renderer* renderer) {
    this->sprite->render(renderer);
}

void Core::Player::updateState(double dt) {}

void Core::Player::setPosition(glm::ivec2 position) {
  this->position = position;
}

void Core::Player::setRotation(double rotation) {
  this->rotation = rotation;
}

void Core::Player::setScale(glm::vec3 scale) {
  this->scale = scale;
}

