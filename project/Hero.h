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
    void check_valid_move(Map, int, int, int, vector<vector<int>>*);
  private:
    int attack;
    int defence;
    int attack_range;
    int mobility;
    vector<int> terrain_effect;
};
#endif
