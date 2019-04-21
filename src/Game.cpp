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
  Core::Clock delta;
  delta.start();

  // TileMap
  Core::Sprite hexmap("src/assets/hex-map.png", this->renderer, 77, 64);
  std::vector<Core::Tile> tiles = {
                                   Core::Tile(0, 0, 0, hexmap),
                                   Core::Tile(77, 0, 1, hexmap),
                                   Core::Tile(154, 0, 2, hexmap),
                                   Core::Tile(231, 0, 3, hexmap),
                                   Core::Tile(308, 0, 4, hexmap),
                                   Core::Tile(385, 0, 5, hexmap),
                                   Core::Tile(462, 0, 6, hexmap),
                                   Core::Tile(538, 0, 7, hexmap)
  };
  Core::TileMap map("src/assets/hex-map.png", tiles);
  map.setGrid(4, 2);

  SDL_Rect cropPlane = { 19, 278, 40, 50 };
  Core::Player plane;
  hexmap.clip = &cropPlane;

  plane.sprite = &hexmap;
  plane.window_settigs = this->window_settings;
  plane.setPosition(glm::ivec2(100, 0));

  while (this->isRunning) {
    frameStart = SDL_GetTicks();

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
    map.render(this->renderer);
    plane.render(this->renderer);

    SDL_GL_SwapWindow(this->window);
    SDL_RenderPresent(this->renderer);

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
      SDL_Delay(frameDelay - frameTime);
    }
  }
}

Game::~Game() {
  SDL_DestroyRenderer(this->renderer);
  SDL_DestroyWindow(this->window);
  SDL_GL_DeleteContext(this->context);
  SDL_Quit();
}

