#include "Player.h"
Player::Player() {
}
void Player::setup(int _x, int _y) {
  x = _x;
  y = _y;
}
void Player::draw(TFT_eSprite img) {
  img.fillRect(x, y, TILESIZE, TILESIZE, TFT_RED);
}

void Player::move(int dx, int dy, uint dt) {
  x += (int)(dx * (dt/1000) * PLAYER_SPEED);
  y += (int)(dy * (dt/1000) * PLAYER_SPEED);
}

void Player::update(int dx, int dy, TFT_eSprite img, uint dt) {
  move(dx, dy, dt);
  draw(img);
}
