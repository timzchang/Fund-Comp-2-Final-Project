// Fundamentals of Computing II: Final Project 		April 25, 2015
// Christopher Syers, Lucas Unruh, Mason Prosser, Tim Chang
// Soldier.cpp
// Interface for the Soldier class. Defines the various member function of Soldier.

#include "Soldier.h"

// default constructor (calls default constructor of Character class)
Soldier::Soldier(){
  // set stats
  class_name = "Soldier";
  player = 1;
  current_hitpoints = 25;
  max_hitpoints = 25;
  attack = 7;		
  defence = 7;
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
Soldier::Soldier(string path, string my_name, int x, int y, int my_player, SDL_Renderer* renderer,vector<vector <int> > tile_prop):Character(path,my_name,x,y,renderer,tile_prop){	
  // sets stats. See Hero.cpp or Character.cpp for information about what the stats mean
  class_name = "Soldier";
  player = my_player;
  current_hitpoints = 25;
  max_hitpoints = 25;
  attack = 7;
  defence = 7;
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
