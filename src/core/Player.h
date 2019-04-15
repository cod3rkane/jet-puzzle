#ifndef CORE_PLAYER_H
#define CORE_PLAYER_H

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "Sprite.h"
#include "Object.h"
#include "Window.h"

namespace Core {
  class Player : public Core::Object {
    int velocity = 366;
    bool isMoving = false;
    const Uint8* last_keyboard_state;
  public:
    Core::Sprite* sprite;
    const Core::Window* window_settigs;

    Player();
    ~Player();
    void render(SDL_Renderer* renderer);
    void updateState(double dt, const Uint8* keyboard_state);
    void setPosition(glm::ivec2 position);
    void setRotation(double rotation);
    void setScale(glm::vec3 scale);
    void move(double dt, const Uint8* key);
  };
};

#endif

