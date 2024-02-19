#include "Level.h"
Level::Level() {
}
void Level::setup() {
}
void Level::draw(TFT_eSprite img) {
  for (int i; i < 16; i++) {
    for (int j; j < 30; j++) {
      switch (tileMap[i][j]) {
        case 0:
          break;
        case 1:
          img.fillRect(TILESIZE * j, TILESIZE * i, TILESIZE, TILESIZE, TFT_WHITE);
          break;
      }
    }
  }
}