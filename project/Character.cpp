// Charcter.cpp
// Implementation of the Character class. Contains definitions for all member functions.

#include "Character.h"
#include <iostream>
#include <string>
using namespace std;
// default constructor (calls non-default of GamePiece which sets xpos and ypos to 0)
Character::Character(){
  direction = 0;			// direction starts at 0
  phase = 1;				// phase starts at 1 (stand still)
  character_texture = NULL;		// no image
  counter = 0;
  alive = 0;				// with non-default, make the character dead
  selected = 0;
  name = "Anonymous";
  canMove = 1;
}

// non-default construtor. Calls non-default of GamePiece to set xpos and ypos to passed in values
Character::Character(string path,string my_name,int x, int y, SDL_Renderer* renderer,vector<vector <int> > tile_prop):GamePiece(x,y), vb(tile_prop/*[0]*/.size(),tile_prop.size(),"../media/blue_highlight.png","../media/red_highlight.png",renderer){
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());				// loads the image into character_texture
  character_texture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
  direction = 0;								// direction starts at 0
  phase = 1;									// phase starts at 1 (stand still phase)
  SDL_FreeSurface(loadedSurface);						// frees the surface
  loadedSurface = NULL;								// grounds pointer
  counter = 0;
  alive = 1;									// indicates the character is alive
  selected = 0;
  tile_properties = tile_prop;
  name = my_name;
  canMove = 1;
  attacking = 0;   //should be set to 1 when attacking.
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
  if(alive == 0){
    return;
  }
  if(selected == 1){
    vb.draw(renderer);
  }
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
void Character::check_valid_move(int x, int y, int movement_remaining, vector<Character *> * players){
// BE CAREFUL WITH COORDINATE SYSTEM - IT IS SLIGHTLY CONFUSING WITH GRAPHICS COORDINATES AND REGULAR VECTOR ARGUMENTS
  if(movement_remaining < 0){  	// if the character is out of movement
    return;		
  }
  if(terrain_effect[tile_properties[y][x]]==0) 
    return;							// if the character can't move onto the x,y coordinate, end function

//  vector<Character *>::iterator it;
 // for(it = (*players).begin(); it != (*players).end(); ++it){
 //   if((*it)->gety() == x && (*it)->getx() == y)
      /*if (player != (*it)->getPlayer())*/// return;			// if coordinate is occupied by enemy player, end function
 // }
  vb.set_tile(1,y,x);						// if it makes it through checks, the position is valid
  // repeat in all direction (recursion)
  if(y-1 >= 0){
    check_valid_move(x,y-1,movement_remaining-terrain_effect[tile_properties[y-1][x]], players);
  }
  if(x+1 < tile_properties.size()){
    check_valid_move(x+1,y,movement_remaining-terrain_effect[tile_properties[y][x+1]], players);
  }
  if(y+1 < tile_properties[0].size()){
    check_valid_move(x,y+1,movement_remaining-terrain_effect[tile_properties[y+1][x]], players);
  }
  if(x-1 >= 0){
    check_valid_move(x-1,y,movement_remaining-terrain_effect[tile_properties[y][x-1]], players);
  }
}

// updates counter of the character to determine when to change phase
void Character::update(){
  if(current_hitpoints==0){
    alive = 0;
  }
  if(selected==1){
    counter++;
    if(counter == 15){		// changes phase and resets every 15 counts
      counter = 0;
      next_phase();
    }
    vb.add_attack_spots(attack_range);
  }
}
  
//function that returns the character's current hitpoints
int Character::getCurrentHitpoints(){
  return current_hitpoints;
}

// function that sets the character's hitpoints
void Character::setCurrentHitpoints(int new_hp){
  if(new_hp < 0) new_hp = 0;
  current_hitpoints = new_hp;
}

// function that returns the character's max hitpoints
int Character::getMaxHitpoints(){
  return max_hitpoints;
}

// function that returns the character's name
string Character::getName(){
  return name;
}

// function that returns the character's attack
int Character::getAttack(){
  return attack;
}

// function that returns the character's defence
int Character::getDefence(){
  return defence;
}

// function to get character's movement
int Character::getMobility(){
  return mobility;
}

// returns the terrain's effect on mobility
int Character::get_terrain_effect(int tile){
  if(tile < 0) return -1;
  return terrain_effect[tile];
}

// changes selected data member to 1
void Character::select(){ //maybe move check_valid_moves() in here?
  selected = 1;
}

// changes selected data member to 0
void Character::unselect(){ 
  selected = 0;
  phase = 1;
  direction = 0;
  
}

int Character::get_select(){
    return selected;
}

// function to move the character. 0 up, 1 right, 2 down, and 3 left.
void Character::move(int change, int max_width, int max_height){
  switch(change){			
    case(0):
      change_direction(0);		// turns the character to face upward
      if(ypos==0) return;		// if the character is already at the end of the map, don't do anything
      else ypos = ypos-1;		// move the character up 1 spot
      break;				// end the function
    case(1):
      change_direction(1);		// turn the character right
      if(xpos == max_width-1) return;	// if it is already at the right limit, do nothing
      else xpos = xpos+1;		// move the character right 1 space
      break;				// end the function
    case(2):
      change_direction(2);		// turns the player down
      if(ypos == max_height-1) return;	// if the player is at the bottom of the map, do nothing
      else ypos = ypos+1;		// move the character down
      break;				// end loop
    case(3):
      change_direction(3);		// change direction to the left
      if(xpos==0) return;		// if the character is already at the left limit, do nothing
      else xpos = xpos-1;		// move character to the left
      break;				// end loop
  }
}

// clears the move vector of the character. Used after the vector has been processed
void Character::clear_move(){
    moves.clear();
}

// function that moves a series of direction that are in a vector
// called everytime character is deselected and moved.
void Character::process_move_vector(int max_width,int max_height){
  for(int i = 0; i<moves.size(); i++){
    move(moves[i],max_width,max_height);
  }
    vb.to_zeros(); //clear the valid board after we process the move vector.
    vb.set_tile(1,ypos,xpos); //if we set tile to 1, add_attack_values will draw the attack range.
    clear_move(); //after processing, clear the move vector.
    //takeMove();	  // once a character has processed a move vector, take its move capability
}

//Key:
//0 = up
//1 = right
//2 = down
//3 = left
//we add a move specified by "move" into the moves vector. If the move is opposite of a previous one, we pop_back.
void Character::add_move(int move){
    if(moves.size()>0){                             //if we have a moves vector greater than one, we have to check the previous move
        if(moves[moves.size()-1]==2 && move==0)      //if previous move was down, and we move up, pop_back
            moves.pop_back();
        else if(moves[moves.size()-1]==0 && move==2) //if previous move was up and we move down, pop_back
            moves.pop_back();
        else if(moves[moves.size()-1]==1 && move==3) //if previous move was right and we move left, pop_back
            moves.pop_back();
        else if(moves[moves.size()-1]==3 && move==1) //if previous move was left and we move right, pop_back
            moves.pop_back();
        else
            moves.push_back(move); //else push back the move
    }else
        moves.push_back(move); //first move
}

int Character::size_move(){
    return moves.size();
}

// function to return the player's team
int Character::getPlayer(){
  return player; 
}

// returns vb location at x,y
int Character::get_tile(int x,int y){
    return vb.get_value(x,y);
}

// returns vb width. Need for Cursor::move()
int Character::get_vb_width(){
    return vb.get_num_cols();
}

// returns vb height. Need for Cursor::move()
int Character::get_vb_height(){
    return vb.get_num_rows();
}

// sets canMove to 1. Used when a turn expires to reset all character to be able to move
void Character::setMove(){
  canMove = 1;
}


// makes CanMove data member 0. Used to indicate a player has taken a move so that they cannot go twice in a turn
void Character::takeMove(){
  canMove = 0;
}

// get function for the data member canMove. Used to count the number of moves left for a team
int Character::getMove(){
  return canMove;
}

// function to tell if a Character is alive (1 if they are alive, 0 if they are head)
// used to see which characters should be removed from the players vector
int Character::isAlive(){
  if(alive){
    return 1;
  }
  return 0;
}

int Character::getAttacking(){
    return attacking;
}

void Character::setAttacking(int i){
    attacking = i;
}

void Character::attack_phase(vector<Character *> * players, Character * hero){
    
}
