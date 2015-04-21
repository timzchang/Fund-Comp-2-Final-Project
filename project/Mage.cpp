// Mage.cpp
// Interface for the Mage class. Defines the various member function of Mage.

#include "Mage.h"

// default constructor (calls default constructor of Character class)
Mage::Mage(){
  // set stats
  player = 1;
  current_hitpoints = 15;
  max_hitpoints = 15;
  attack = 13;		
  defence = 6;
  attack_range = 2;
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
Mage::Mage(string path, string name, int x, int y, int my_player, SDL_Renderer* renderer,vector<vector <int> > tile_prop):Character(path,name,x,y,renderer,tile_prop){	
  // sets stats
  player = my_player;
  current_hitpoints = 15;
  max_hitpoints = 15;
  attack = 13;
  defence = 6;
  attack_range = 2;
  mobility = 4;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
}
