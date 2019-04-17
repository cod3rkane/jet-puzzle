#include "Game.h"

Game::Game(const Core::Window* window_settings) {
  if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
    std::cout << "ERROR: Could not initialize sdl" << std::endl;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
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

  glViewport(0, 0, window_settings->width, window_settings->height);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  this->isRunning = true;
  this->window_settings = window_settings;
}

void Game::main_loop() {
  SDL_Event sdlEvent;
  SDL_Rect cropPlane = { 0, 0, 256, 256 };
  SDL_Rect cropBalls = { 0, 0, 100, 100 };

  Core::Sprite planesSprite("src/assets/airplanes", this->renderer, 256, 256);
  planesSprite.clip = &cropPlane;
  Core::Player plane;
  plane.sprite = &planesSprite;
  plane.window_settigs = this->window_settings;
  plane.setPosition(glm::ivec2(600, 300));

  Core::Clock delta;
  delta.start();


  // TileMap
  Core::Sprite hexmap("src/assets/hex-map.png", this->renderer, 82, 65);
  SDL_Rect crophex = { 0, 545, 82, 65 };
  hexmap.clip = &crophex;

  while (this->isRunning) {
    while (SDL_PollEvent(&sdlEvent) != 0) {
      if (sdlEvent.type == SDL_QUIT) {
        this->isRunning = false;
      }
    }

    // process input
    this->keyboard_state = SDL_GetKeyboardState(NULL);

    // update game
    plane.updateState(delta.get_ticks(), this->keyboard_state);
    delta.start();

    SDL_RenderClear(this->renderer);
    glClearColor(0.94f, 0.97f, 0.93f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // render
    plane.render(this->renderer);
    hexmap.render(this->renderer);

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

