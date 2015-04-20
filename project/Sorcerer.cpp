// Sorcerer.cpp
// Interface for the Sorcerer class. Defines the various member function of Sorcerer.

#include "Sorcerer.h"

// default constructor (calls default constructor of Character class)
Sorcerer::Sorcerer(){
  // set stats
  hitpoints = 15;
  attack = 14;		
  defence = 6;
  attack_range = 2;
  mobility = 3;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);	// Plains
  terrain_effect.push_back(1);	// Trees
  terrain_effect.push_back(2);	// Hills
  terrain_effect.push_back(0);	// Water
  terrain_effect.push_back(2);	// Roots
  terrain_effect.push_back(0);	// Mountain/cliff
}

// non-default constructor. Calls non-default constructor of Character class.
Sorcerer::Sorcerer(string path, string my_name, int x, int y, SDL_Renderer* renderer,vector<vector <int> > tile_prop):Character(path,my_name,x,y,renderer,tile_prop){	
  // sets stats
  hitpoints = 15;
  attack = 14;
  defence = 6;
  attack_range = 2;
  mobility = 3;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
}
