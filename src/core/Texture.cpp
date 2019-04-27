#include "Texture.h"

Core::Texture::Texture() {}

Core::Texture::Texture(std::string path, SDL_Renderer* renderer) {
  int width;
  int height;
  int original_format;
  int req_format = STBI_rgb_alpha;
  unsigned char* data = stbi_load(
                                  path.c_str(),
                                  &width,
                                  &height,
                                  &original_format,
                                  req_format
                                  );

  if (data == NULL) {
    SDL_Log("Loading image failed: %s", stbi_failure_reason());
    exit(1);
  }

  int depth;
  int pitch;
  Uint32 pixel_format;

  if (req_format == STBI_rgb) {
    depth = 24;
    pitch = 3*width; // 3 bytes per pixel * pixels per row
    pixel_format = SDL_PIXELFORMAT_RGB24;
  } else { // STBI_rgb_alpha (RGBA)
    depth = 32;
    pitch = 4*width;
    pixel_format = SDL_PIXELFORMAT_RGBA32;
  }

  SDL_Surface* surf = SDL_CreateRGBSurfaceWithFormatFrom(
                                                         (void*)data,
                                                         width,
                                                         height,
                                                         depth,
                                                         pitch,
                                                         pixel_format
                                                         );

  if (surf == NULL) {
    SDL_Log("Creating surface failed: %s", SDL_GetError());
    stbi_image_free(data);
    exit(1);
  }

  SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 0, 0xFF, 0xFF));
  this->texture = SDL_CreateTextureFromSurface(renderer, surf);

  SDL_FreeSurface(surf);
  stbi_image_free(data);
}

void Core::Texture::render(SDL_Renderer* renderer) {
  SDL_RenderCopy(renderer, this->texture, NULL, NULL);
}

void Core::Texture::updateState(double dt, const Uint8* keyboard_state) {}

void Core::Texture::setPosition(glm::ivec2 position) {
  this->position = position;
}

void Core::Texture::setRotation(double rotation) {
  this->rotation = rotation;
}

void Core::Texture::setScale(glm::vec3 scale) {
  this->scale = scale;
}

