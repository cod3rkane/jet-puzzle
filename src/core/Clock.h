#ifndef CORE_CLOCK_H
#define CORE_CLOCK_H

#include <SDL2/SDL.h>

namespace Core {
    struct Clock {
        Uint64 NOW = SDL_GetPerformanceCounter();
        Uint64 LAST = 0;
        double deltatime = 0;

        void tick() {
            LAST = NOW;
            NOW = SDL_GetPerformanceCounter();
            deltatime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );
        }
    };
}

#endif

