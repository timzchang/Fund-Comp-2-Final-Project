/*CSE20212 Final Project                4/7/2015
  Mason Prosser, Tim Chang, Chris Syers, Lucas Unruh
   Cursor.cpp
   Implementation of Cursor class */

#include "Cursor.h"
#include "Character.h"
#include<iostream>
#include<vector>
// Default constructor
Cursor::Cursor():GamePiece(){
  cursor_1 = NULL;
  cursor_2 = NULL;
  phase = 0;
  counter = 0;
}

// Non-default constructor
Cursor::Cursor(string path1, string path2, SDL_Renderer* renderer, int x, int y):GamePiece(x,y){
  // Load images of cursors
  SDL_Surface* loadedSurface = IMG_Load(path1.c_str());
  cursor_1 = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  SDL_FreeSurface(loadedSurface);
  loadedSurface = NULL;

  loadedSurface = IMG_Load(path2.c_str());
  cursor_2 = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  SDL_FreeSurface(loadedSurface);
  loadedSurface = NULL;
  
  phase = 0; 			// phase starts at 0
  counter = 0;
}

// Deconstructor
Cursor::~Cursor(){
  if(cursor_1 != NULL){
    SDL_DestroyTexture(cursor_1);
    cursor_1 = NULL;
  }

  if(cursor_2 != NULL){
    SDL_DestroyTexture(cursor_2);
    cursor_2 = NULL;
  }
}

//draw function. Function decides which cursor to render by passing in the counter from main
void Cursor::draw(SDL_Renderer * renderer){
  SDL_Rect destRect = {xpos*32, ypos*32, 32, 32};
  SDL_Rect cursorRect = {0, 0, 32, 32};
  if(phase == 0){
    SDL_RenderCopy(renderer, cursor_1, &cursorRect, &destRect);
  }else{
    SDL_RenderCopy(renderer, cursor_2, &cursorRect, &destRect);
  }
}

// moves to the next phase
void Cursor::next_phase(){
// toggles the phase
  if(phase == 0){
    phase = 1;
  }else{
    phase = 0;
  }
}

// function that gets the phase of the Cursor
int Cursor::get_phase(){
  return phase;
}

// updates clock count to determine when to change images
void Cursor::update(){
  counter++;
  if(counter == 40){		// updates every 40 clock cycles
    counter = 0;
    next_phase();
  }
}

// function that moves the cursor and keeps it from going outside of the map.
void Cursor::move(int change, int max_width, int max_height){
  switch(change){
    case(0):
      if(ypos==0) return;
      else ypos = ypos-1;
      break;
    case(1):
      if(xpos == max_width-1) return;
      else xpos = xpos+1;
      break;
    case(2):
      if(ypos == max_height-1) return;
      else ypos = ypos+1;
      break;
    case(3):
      if(xpos==0) return;
      else xpos = xpos-1;
      break;
  }
}

//******NEW FUNCTION toggle_select():
//if Cursor is over a character, it will be selected or deselected. Needs the character vector to loop through each character.
//if selected:
//  check_valid_move(x,y,mobility) is called, displaying the possible moveset
//if unselected:
//  unselect and process_move_vector(level_width,level_height)
//needs map object and moves vector for the 2 valid board functions.
void Cursor::toggle_select(vector<Character *> * players, Map * level){
    for (vector<Character *>::iterator hero=(*players).begin(); hero !=(*players).end(); ++hero) { //hero iterator to loop through player vector
      if(this->getx()==(*hero)->getx() && this->gety()==(*hero)->gety()){                    //if this cursor and character are on the same coordinate
        if((*hero)->get_select()==0){                                                        //and this player is not selected
          (*hero)->select();                                                                 //select (this only changes the "selected" member of Character to 1. Makes the guy animate as well.)
          (*hero)->check_valid_move((*hero)->getx(),(*hero)->gety(),(*hero)->getMobility()); //this is the one that updates its valid board
        }else{
          (*hero)->unselect();                                                               //similarly, this only changes "selected" to 0. stops the guy from being animated
          (*hero)->process_move_vector(level->get_width(),level->get_height());              //process move vector.
        }
      }
        if((*hero)->get_select() && (*hero)->size_move()>0){                                 //if this hero is selected and its move vector is greater than zero
          (*hero)->unselect();                                                               //deselect and process move vector.
          (*hero)->process_move_vector(level->get_width(),level->get_height());
        }
    }
}


//NEXT IMPROVEMENT:
//if there is a character selected, limit the movement of the cursor to the valid board. I don't know how we should approach this.
//Currently the "move_cursor()" function is in main.
//I originally thought calling this function every keypress would be inefficient, but it might be necessary.
//
//******NEW FUNCTION move_select():*******
//This function is called each time someone hits the arrow keys.
//it will loop through the character vector in search of a character who is selected.
//if the character is selectecd, we will update its move vector with the "move" value.
void Cursor::move_select(vector<Character *> * players, int move){
    for (vector<Character *>::iterator hero=(*players).begin(); hero !=(*players).end(); ++hero) { //hero iterator to loop through player vector
        if((*hero)->get_select())
            (*hero)->add_move(move);
            
    }
}
