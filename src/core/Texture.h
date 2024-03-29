#ifndef CORE_TEXTURE_H
#define CORE_TEXTURE_H

#include <iostream>
#include <SDL2/SDL.h>
#include "StbImage.h"
#include "Object.h"

namespace Core {
  class Texture : public Core::Object {
  public:
    SDL_Texture* texture;
    Texture();
    Texture(std::string path, SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer);
    void updateState(double dt, const Uint8* keyboard_state);
    void setPosition(glm::ivec2 position);
    void setRotation(double rotation);
    void setScale(glm::vec3 scale);
  };
}

#endif

