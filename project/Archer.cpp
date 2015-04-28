// Fundamentals of Computing II: Final Project		April 25, 2015
// Tim Chang, Mason Prosser, Christopher Syers, Lucas Unruh

// Archer.cpp
// Interface for the Archer class. Defines the various member function of Archer.

#include "Archer.h"

// default constructor (calls default constructor of Character class)
Archer::Archer(){
  // set stats
  player = 1;
  current_hitpoints = 18;
  max_hitpoints = 18;
  attack = 9;		
  defence = 6;
  attack_range = 2;
  mobility = 5;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);	// Plains
  terrain_effect.push_back(1);	// Trees
  terrain_effect.push_back(2);	// Hills
  terrain_effect.push_back(0);	// Water
  terrain_effect.push_back(2);	// Roots
  terrain_effect.push_back(0);	// Mountain/cliff
}

// non-default constructor. Calls non-default constructor of Character class.
Archer::Archer(string path, string my_name, int x, int y, int my_player, SDL_Renderer* renderer,vector<vector <int> > tile_prop):Character(path,my_name,x,y,renderer,tile_prop){	
  // sets stats see Hero.cpp for slightly more information on what the variables mean.
  player = my_player;
  current_hitpoints = 18;
  max_hitpoints = 18;
  attack = 9;
  defence = 6;
  attack_range = 2;
  mobility = 5;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
}
