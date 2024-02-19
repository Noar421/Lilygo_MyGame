#ifndef Player_h
#define Player_h
#include "Config.h" 
class Player {

public:
  Player();
  void setup(int x, int y);
  void update(int dx, int dy, TFT_eSprite &img, uint dt);

private:
  int x;
  int y;
  int dx = 0;
  int dy = 0;
  void move(int dx, int dy, uint dt);
  void draw(TFT_eSprite &img);
};

#endif