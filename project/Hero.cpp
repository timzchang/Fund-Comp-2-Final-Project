// Hero.cpp
// Interface for the Hero class. Defines the various member function of Hero.

#include "Hero.h"

// default constructor (calls default constructor of Character class)
Hero::Hero(){
  // set stats
  hitpoints = 25;
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

// non-default constructor. Calls non-default constructor of Character class.
Hero::Hero(string path, int x, int y, SDL_Renderer* renderer):Character(path,x,y,renderer){	
  // sets stats
  hitpoints = 25;
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

// function that returns the Hero's hitpoints
int Hero::getHitpoints(){
  return hitpoints;
}

// function that sets the Hero's hitpoints
int Hero::setHitpoints(int new_hitpoints){
  if(new_hitpoints < 0) new_hitpoints = 0;		// if the new hitpoints is negative, just put to 0
  hitpoints = new_hitpoints;
}
