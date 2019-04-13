#include "Sprite.h"

Core::Sprite::Sprite(std::string path, SDL_Renderer* renderer, int width, int height): Core::Texture(path, renderer) {
  this->width = width;
  this->height = height;
}

void Core::Sprite::render(SDL_Renderer* renderer) {
  SDL_Rect render_quad = { this->position.x, this->position.y, this->width, this->height };
  SDL_RenderCopyEx(
                   renderer,
                   this->texture,
                   this->clip,
                   &render_quad,
                   this->rotation,
                   NULL,
                   SDL_FLIP_NONE
                   );
}

