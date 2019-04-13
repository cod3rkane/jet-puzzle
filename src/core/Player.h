#ifndef CORE_PLAYER_H
#define CORE_PLAYER_H

#include <SDL2/SDL.h>
#include "Texture.h"
#include "Object"

namespace Core {
    class Player : Core::Object {
        Core::Texture texture;
    public:
        void render(SDL_Renderer* renderer);
    };
};

#endif

