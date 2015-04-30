// Fundmentals of Computing II: Final Project		April 28, 2015
// Christopher Syers, Tim Chang, Lucas Unruh, Mason Prosser
// Pirate.cpp
// Interface for the Pirate class. Defines the various member function of Pirate.

#include "Pirate.h"

// default constructor (calls default constructor of Character class)
Pirate::Pirate(){
  // set stats
  class_name = "Pirate";
  player = 1;
  current_hitpoints = 25;
  max_hitpoints = 25;
  attack = 11;		
  defence = 4;
  attack_range = 1;
  mobility = 4;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);	// Plains
  terrain_effect.push_back(1);	// Trees
  terrain_effect.push_back(2);	// Hills
  terrain_effect.push_back(1);	// Water
  terrain_effect.push_back(2);	// Roots
  terrain_effect.push_back(0);	// Mountain/clifaf
}

// non-default constructor. Calls non-default constructor of Character class.
Pirate::Pirate(string path, string my_name, int x, int y, int my_player, SDL_Renderer* renderer,vector<vector <int> > tile_prop):Character(path,my_name,x,y,renderer,tile_prop){	
  // sets stats. See Hero.cpp or Character.cpp for more information on what the stats mean
  class_name = "Pirate";
  player = my_player;
  current_hitpoints = 25;
  max_hitpoints = 25;
  attack = 11;
  defence = 4;
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
