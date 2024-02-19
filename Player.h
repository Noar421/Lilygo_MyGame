#ifndef Player_h
#define Player_h
#include "Config.h" 
class Player {
public:
  Player();
  void setup(int x, int y);
  void draw();

private:
  int x;
  int y;  
};

#endif