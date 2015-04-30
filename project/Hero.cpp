// Fundamentals of Cumputing II Final Project		April 28, 2015
// Christopher Syers, Mason Prosser, Tim Chang, Lucas Unruh

// Hero.cpp
// Interface for the Hero class. Defines the various member function of Hero.

#include "Hero.h"

// default constructor (calls default constructor of Character class). This is never used
Hero::Hero(){
  // set stats
  class_name = "Hero";
  player = 1;
  current_hitpoints = 25;
  max_hitpoints = 25;
  attack = 10;		
  defence = 7;
  attack_range = 1;
  mobility = 4;
  terrain_effect.push_back(0);	// There is no tile with number 0
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
  class_name = "Hero";
  player = my_player;			// sets which team the player is on
  current_hitpoints = 25;		// heros have 25 hp
  max_hitpoints = 25;			// heros have 25 hp
  attack = 10;				
  defence = 7;
  attack_range = 1;			// how far the player can attack
  mobility = 4;				// number of steps a character can take in a turn
// terain_effect is a vector of the number of movement it takes for this character to move over the tile type of its index.
// for example, because 2 indicates a tree tile, this character takes 1 movement to go over tree because terrain_effect(2) = 1. 
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
}
