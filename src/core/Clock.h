#ifndef CORE_CLOCK_H
#define CORE_CLOCK_H

#include <SDL2/SDL.h>

namespace Core {
  class Clock {
  private:
    int startTicks;
    int pausedTicks;
    bool paused;
    bool started;

  public:
    Clock() {
      startTicks = 0;
      pausedTicks = 0;
      paused = false;
      started = false;
    }

    void start() {
      started = true;
      paused = false;
      startTicks = SDL_GetTicks();
    }

    void stop() {
      started = false;
      paused = true;
    }

    void pause() {
      if (started == true && paused == false) {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
      }
    }

    void unpause() {
      if (paused == true) {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
      }
    }

    int get_ticks() {
      if (started == true) {
        if (paused == true) {
          return pausedTicks;
        } else {
          return SDL_GetTicks() - startTicks;
        }
      }

      return 0;
    }

    bool is_started() {
      return started;
    }

    bool is_paused() {
      return paused;
    }
  };
}

#endif

