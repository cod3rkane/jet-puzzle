#include "TileMap.h"

Core::TileMap::TileMap() {
}

Core::TileMap::TileMap(std::string sprite_path, std::vector<Core::Tile> tiles) {
  this->sprite_path = sprite_path;
  this->tiles = tiles;
}

Core::TileMap::~TileMap() {

}

void Core::TileMap::render(SDL_Renderer *renderer) {
  for (int y = 0; y < this->grid_y; y++) {
    for (int x = 0; x < this->grid_x; x++) {
      int index = x + (y * this->grid_x);
      glm::ivec2 const pos(
                     x * this->tiles[index].getWidth(),
                     y * this->tiles[index].getHeight()
                     );
      glm::ivec2 const finalPos(pos.x + this->position.x, pos.y + this->position.y);
      this->tiles[index].setPosition(finalPos);
      this->tiles[index].render(renderer);
    }
  }
}

void Core::TileMap::updateState(double dt, const Uint8 *keyboard_state) {

}

void Core::TileMap::setPosition(glm::ivec2 position) {
  this->position = position;
}

void Core::TileMap::setRotation(double rotation) {
  this->rotation = rotation;
}

void Core::TileMap::setScale(glm::vec3 scale) {
  this->scale = scale;
}

void Core::TileMap::setGrid(int x, int y) {
  this->grid_x = x;
  this->grid_y = y;
}

void Core::TileMap::fromFile(const GLchar* file, Core::Sprite sprite) {
  std::vector<Core::Tile> tileList;
  std::string line;
  std::ifstream fstream(file);
  std::string tileCode;

  if (fstream) {
    while (std::getline(fstream, line)) {
      std::istringstream sstream(line);
      while (sstream >> tileCode) {
        int isCollidable = 0;
        if (tileCode.find_first_of("#") != std::string::npos) {
          tileCode.erase(tileCode.begin());
          isCollidable = 1;
        }
        Core::vec2 pos = getPosFromTileset(std::stoi(tileCode));
        Core::Tile tile(pos.x, pos.y, isCollidable, sprite);
        tileList.push_back(tile);
      }
    }
  }

  this->tiles = tileList;
}

Core::vec2 Core::TileMap::getPosFromTileset(int index) {
  int tile_w = 77;
  int tile_h = 64;
  int max_tileset_rows = 5;
  int max_tileset_cols = 6;
  int i = 0;
  Core::vec2 vec2;

  for (int x = 0; x < max_tileset_rows; x++) {
    for (int y = 0; y < max_tileset_cols; y++) {
      if (i == index) {
        int a = x * tile_w;
        int b = y * tile_h;
        vec2 = { a, b };
      }
      i++;
    }
  }

  return vec2;
}

