#include "Player.h"

Core::Player::Player() {

}

Core::Player::~Player() {

}

void Core::Player::render(SDL_Renderer* renderer) {
    this->sprite->render(renderer);
}

void Core::Player::updateState(double dt) {}

