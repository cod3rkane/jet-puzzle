#ifndef CORE_SPRITE_H
#define CORE_SPRITE_H

#include <iostream>
#include <SDL2/SDL.h>
#include "Texture.h"

namespace Core {
    class Sprite : public Core::Texture {
        SDL_Rect* clip;
        SDL_Rect* render_quad;
    public:
        Sprite(std::string path, SDL_Renderer* renderer, SDL_Rect* renderQuad);
        void render(SDL_Renderer* renderer) override;
    };
};

#endif

