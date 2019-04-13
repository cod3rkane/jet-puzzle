#ifndef CORE_TEXTURE_H
#define CORE_TEXTURE_H

#include <iostream>
#include <SDL2/SDL.h>
#include "StbImage.h"

namespace Core {
    class Texture {
    public:
        SDL_Texture* texture;
        Texture(std::string path, SDL_Renderer* renderer);
    };
}

#endif

