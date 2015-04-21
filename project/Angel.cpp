// Angel.cpp
// Interface for the Angel class. Defines the various member function of Angel.

#include "Angel.h"

// default constructor (calls default constructor of Character class)
Angel::Angel(){
  // set stats
  player = 1;
  current_hitpoints = 19;
  max_hitpoints = 19;
  attack = 12;		
  defence = 6;
  attack_range = 1;
  mobility = 7;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);	// Plains
  terrain_effect.push_back(2);	// Trees
  terrain_effect.push_back(1);	// Hills
  terrain_effect.push_back(1);	// Water
  terrain_effect.push_back(1);	// Roots
  terrain_effect.push_back(2);	// Mountain/cliff
}

// non-default constructor. Calls non-default constructor of Character class.
Angel::Angel(string path,string name ,int x, int y, int my_player, SDL_Renderer* renderer,vector<vector <int> > tile_prop):Character(path,name,x,y,renderer,tile_prop){	
  // sets stats
  player = my_player;
  current_hitpoints = 19;
  max_hitpoints = 19;
  attack = 12;
  defence = 6;
  attack_range = 1;
  mobility = 7;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
}
