#include "Game.h"

Game::Game(const Core::Window* window_settings) {
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        std::cout << "ERROR: Could not initialize sdl" << std::endl;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    this->window = SDL_CreateWindow(
            window_settings->title.c_str(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            window_settings->width,
            window_settings->height,
            SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
    );

    if (!this->window) {
        std::cout << "ERROR: Could not create SDL window" << std::endl;
    }

    this->context = SDL_GL_CreateContext(this->window);

    if (this->context == NULL) {
        std::cout << "ERROR: COuld not create SDL context from window" << std::endl;
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);

    if (this->renderer == NULL) {
        SDL_Log("Error: Could not create SDL renderer from window");
        exit(1);
    }

    glewExperimental = GL_TRUE;
    glewInit();

    // use vsync
    if (SDL_GL_SetSwapInterval(1) < 0) {
        std::cout << "ERROR: Could not enable vsync" << std::endl;
    }

    this->isRunning = true;
}

void Game::main_loop() {
    SDL_Event sdlEvent;
    Core::Texture texture("src/assets/wall.jpg", this->renderer);

    while (this->isRunning) {
       while (SDL_PollEvent(&sdlEvent) != 0) {
           if (sdlEvent.type == SDL_QUIT) {
               this->isRunning = false;
           }
       }

       SDL_RenderClear(this->renderer);
       glClearColor(0.94f, 0.97f, 0.93f, 1.0f);
       glClear(GL_COLOR_BUFFER_BIT);

       // draw stuffs here
       texture.render(this->renderer);

       SDL_GL_SwapWindow(this->window);
       SDL_RenderPresent(this->renderer);
    }
}

Game::~Game() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_GL_DeleteContext(this->context);
    SDL_Quit();
}

