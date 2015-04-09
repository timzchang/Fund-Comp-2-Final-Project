// Charcter.cpp
// Implementation of the Character class. Contains definitions for all member functions.

#include "Character.h"

// default constructor (calls non-default of GamePiece which sets xpos and ypos to 0)
Character::Character(){
  direction = 0;			// direction starts at 0
  phase = 0;				// phase starts at 0
  character_texture = NULL;		// no image
  counter = 0;
  alive = 0;				// with non-default, make the character dead
}

// non-default construtor. Calls non-default of GamePiece to set xpos and ypos to passed in values
Character::Character(string path,int x, int y, SDL_Renderer* renderer):GamePiece(x,y){
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());				// loads the image into character_texture
  character_texture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
  direction = 0;								// direction starts at 0
  phase = 0;									// phase starts at 0
  SDL_FreeSurface(loadedSurface);						// frees the surface
  loadedSurface = NULL;								// grounds pointer
  counter = 0;
  alive = 1;									// indicates the character is alive
}

// deconstructor
Character::~Character(){
  if(character_texture!=NULL){				// if the character_texture isn't already Null,
    SDL_DestroyTexture(character_texture);		// destroy it
    character_texture = NULL;				// ground the pointer
  }
  direction = 0;				
  phase = 0;
}

// draw function. QUESTIONS ABOUT THIS: HOW CAN WE MAKE HERO USE THIS SAME FUNCTION
void Character::draw(SDL_Renderer* renderer){
  SDL_Rect destRect = {xpos*32, ypos*32, 32, 32};			// destination rectangle. Based on xpos and ypos of GamePiece
  SDL_Rect clipRect = {phase*32, direction*32, 32, 32};			// source rect. Clips the sprite sheet based on the phase.
  SDL_RenderCopy(renderer, character_texture, &clipRect, &destRect);	// draws it to the renderer that was passed in
}

// function to set the direction of the Character
void Character::change_direction(int face_direction){
  switch(face_direction){				// changed direction: 0 is up, 1 is right, 2 is down, and 3 is left
    case 0:
      direction=3;
      break;
    case 1:
      direction=2;
      break;
    case 2:
      direction=0;
      break;
    case 3:
      direction=1;
      break;
  }
}

// function to set phase
void Character::next_phase(){
  phase++;			// increments phase variable
  if(phase > 2) phase = 0;	// if it is greater than 2, reset to 0
}

// function that returns the current phase of the sprite
int Character::get_phase(){
	return phase;
}

// function that takes in a vector of vector and returns it populated with 1s where a character can move
void Character::check_valid_move(Map &current_map, int x, int y, int movement_remaining,vector< vector<int> > valid_map){
  if(movement_remaining <= 0) return;					// if the character is out of movement, end recursion
  if(x < 0 || x > current_map.get_width()) return;			// if the x is out of range, end function
  if(y < 0 || y > current_map.get_height()) return;			// if y coordinate is out of range, end function
  if(terrain_effect[current_map.get_tile_info(x,y)]==0) return;		// if the character can't move onto the x,y coordinate, end function
  valid_map[x][y] = 1;							// if it makes it through checks, the position is valid
  // repeat in all direction (recurrsion)
  check_valid_move(current_map,x,y-1,movement_remaining-current_map.get_tile_info(x,y-1),valid_map);
  check_valid_move(current_map,x+1,y,movement_remaining-current_map.get_tile_info(x+1,y),valid_map);
  check_valid_move(current_map,x,y+1,movement_remaining-current_map.get_tile_info(x,y+1),valid_map);
  check_valid_move(current_map,x-1,y,movement_remaining-current_map.get_tile_info(x-1,y),valid_map);
}

// updates counter of the character to determine when to change phase
void Character::update(){
  counter++;
  if(counter == 15){		// changes phase and resets every 15 counts
    counter = 0;
    next_phase();
  }
}
  
//function that return's the character's current hitpoints
int Character::getHitpoints(){
  return hitpoints;
}

// function that sets the character's hitpoints
void Character::setHitpoints(int new_hp){
  if(new_hp < 0) new_hp = 0;
  hitpoints = new_hp;
}
