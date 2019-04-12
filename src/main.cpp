#include <iostream>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "Game.h"
#include "core/Window.h"

int main() {
    Core::Window window_settings = {
        1280,
        720,
        "Jet Puzzle"
    };

    Game jetPuzzle(&window_settings);
    jetPuzzle.main_loop();

    return EXIT_SUCCESS;
}
