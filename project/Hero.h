// Hero.h
// interface for the Hero class. Derivative of Character, sets certain stats. Has no
// data members. The uniqueness comes in because it has speicifc stats that are set
// in the constructor

#ifndef HERO_H
#define HERO_H
#include<vector>
#include<string>
#include"Map.h"
#include"Character.h"
class Hero: public Character{
  public:
    Hero();					// default constructor
    Hero(string, int, int, SDL_Renderer*);	// non-default constructor
    void draw(SDL_Renderer*);
  private:
};
#endif
