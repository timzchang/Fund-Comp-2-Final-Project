#include "Hero.h"

Hero::Hero(){
  attack = 10;
  defence = 7;
  attack_range = 1;
  mobility = 6;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
}

Hero::Hero(string path, int x, int y, SDL_Renderer* renderer):Character(path,x,y,renderer){
  attack = 10;
  defence = 7;
  attack_range = 1;
  mobility = 6;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
}
