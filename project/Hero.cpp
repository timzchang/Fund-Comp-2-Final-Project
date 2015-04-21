// Hero.cpp
// Interface for the Hero class. Defines the various member function of Hero.

#include "Hero.h"

// default constructor (calls default constructor of Character class)
Hero::Hero(){
  // set stats
  player = 1;
  current_hitpoints = 25;
  max_hitpoints = 25;
  attack = 10;		
  defence = 7;
  attack_range = 1;
  mobility = 4;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);	// Plains
  terrain_effect.push_back(1);	// Trees
  terrain_effect.push_back(2);	// Hills
  terrain_effect.push_back(0);	// Water
  terrain_effect.push_back(2);	// Roots
  terrain_effect.push_back(0);	// Mountain/cliff
}

// non-default constructor. Calls non-default constructor of Character class.
Hero::Hero(string path, string my_name, int x, int y, int my_player, SDL_Renderer* renderer,vector<vector <int> > tile_prop):Character(path,my_name,x,y,renderer,tile_prop){	
  // sets stats
  player = my_player;
  current_hitpoints = 25;
  max_hitpoints = 25;
  attack = 10;
  defence = 7;
  attack_range = 1;
  mobility = 4;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
}
