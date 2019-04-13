#include "Sprite.h"

Core::Sprite::Sprite(std::string path, SDL_Renderer* renderer, SDL_Rect* renderQuad): Core::Texture(path, renderer) {
    this->render_quad = renderQuad;
}

void Core::Sprite::render(SDL_Renderer* renderer) {
    SDL_RenderCopyEx(renderer, this->texture, this->clip, this->render_quad, this->angle, NULL, SDL_FLIP_NONE);
}

