#ifndef CORE_OBJECT_H
#define CORE_OBJECT_H

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

namespace Core {
    class Object {
    public:
        glm::vec3* position;
        glm::vec3* rotation;
        glm::vec3* scale;
        virtual void render(SDL_Renderer* renderer) = 0;
    };
};

#endif

