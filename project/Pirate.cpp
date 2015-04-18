// Pirate.cpp
// Interface for the Pirate class. Defines the various member function of Pirate.

#include "Pirate.h"

// default constructor (calls default constructor of Character class)
Pirate::Pirate(){
  // set stats
  hitpoints = 28;
  attack = 11;		
  defence = 6;
  attack_range = 1;
  mobility = 4;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);	// Plains
  terrain_effect.push_back(1);	// Trees
  terrain_effect.push_back(2);	// Hills
  terrain_effect.push_back(1);	// Water
  terrain_effect.push_back(2);	// Roots
  terrain_effect.push_back(0);	// Mountain/cliff
}

// non-default constructor. Calls non-default constructor of Character class.
Pirate::Pirate(string path, int x, int y, SDL_Renderer* renderer,vector<vector <int> > tile_prop):Character(path,x,y,renderer,tile_prop){	
  // sets stats
  hitpoints = 28;
  attack = 11;
  defence = 6;
  attack_range = 1;
  mobility = 4;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
}
