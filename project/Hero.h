#ifndef HERO_H
#define HERO_H
#include<vector>
#include<string>
#include"Character.h"
class Hero: public Character{
  public:
    Hero();
    Hero(string, int, int, SDL_Renderer*);
  private:
    int attack;
    int defence;
    int attack_range;
    int mobility;
    vector<int> terrain_effect;
};
#endif
