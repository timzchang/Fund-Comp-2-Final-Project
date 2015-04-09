/*CSE20212 Final Project                4/7/2015
  Mason Prosser, Tim Chang, Chris Syers, Lucas Unruh
   Cursor.cpp
   Implementation of Cursor class */

#include "Cursor.h"
// Default constructor
Cursor::Cursor():GamePiece(){
  cursor_1 = NULL;
  cursor_2 = NULL;
  phase = 0;
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
