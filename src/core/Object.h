#ifndef CORE_OBJECT_H
#define CORE_OBJECT_H

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

namespace Core {
  class Object {
  public:
    glm::ivec2 position = glm::ivec2(0, 0);
    double rotation = 0;
    glm::vec3 scale = glm::vec3(0, 0, 0);
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void updateState(double dt) = 0;
    virtual void setPosition(glm::ivec2 position) = 0;
    virtual void setRotation(double rotation) = 0;
    virtual void setScale(glm::vec3 scale) = 0;
  };
};

#endif

