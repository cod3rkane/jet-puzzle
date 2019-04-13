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
        Texture(std::string path, SDL_Renderer* renderer);
        void render(SDL_Renderer* renderer);
        void updateState(double dt);
    };
}

#endif

