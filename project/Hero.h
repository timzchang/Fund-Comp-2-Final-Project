#ifndef HERO_H
#define HERO_H
#include<vector>
#include<string>
#include"Map.h"
#include"Character.h"
class Hero: public Character{
  public:
    Hero();
    Hero(string, int, int, SDL_Renderer*);
  private:
};
#endif
