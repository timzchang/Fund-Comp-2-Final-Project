// Soldier.cpp
// Interface for the Soldier class. Defines the various member function of Soldier.

#include "Soldier.h"

// default constructor (calls default constructor of Character class)
Soldier::Soldier(){
  // set stats
  current_hitpoints = 26;
  max_hitpoints = 26;
  attack = 7;		
  defence = 9;
  attack_range = 1;
  mobility = 3;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);	// Plains
  terrain_effect.push_back(1);	// Trees
  terrain_effect.push_back(2);	// Hills
  terrain_effect.push_back(0);	// Water
  terrain_effect.push_back(0);	// Roots
  terrain_effect.push_back(0);	// Mountain/cliff
}

// non-default constructor. Calls non-default constructor of Character class.
Soldier::Soldier(string path, string my_name, int x, int y, SDL_Renderer* renderer,vector<vector <int> > tile_prop):Character(path,my_name,x,y,renderer,tile_prop){	
  // sets stats
  current_hitpoints = 26;
  max_hitpoints = 26;
  attack = 7;
  defence = 9;
  attack_range = 1;
  mobility = 3;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
  terrain_effect.push_back(0);
  terrain_effect.push_back(0);
}
