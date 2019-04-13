#include "Sprite.h"

Core::Sprite::Sprite(std::string path, SDL_Renderer* renderer, SDL_Rect* renderQuad): Core::Texture(path, renderer) {
    this->render_quad = renderQuad;
}

void Core::Sprite::render(SDL_Renderer* renderer) {
    SDL_Rect clip = { 0, 0, 100, 100 };
    SDL_RenderCopy(renderer, this->texture, this->clip, this->render_quad);
}

