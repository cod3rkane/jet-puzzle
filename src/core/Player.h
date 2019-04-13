#ifndef CORE_PLAYER_H
#define CORE_PLAYER_H

#include <SDL2/SDL.h>
#include "Sprite.h"
#include "Object.h"

namespace Core {
    class Player : public Core::Object {
    public:
        Core::Sprite* sprite;
        Player();
        ~Player();
        void render(SDL_Renderer* renderer);
        void updateState(double dt);
    };
};

#endif

