/* CSE20212 Final Project                4/7/2015
   Mason Prosser, Tim Chang, Chris Syers, Lucas Unruh
   Cursor.h
   Header file for cursor, which will be the player's way of interacting with the map */

#ifndef CURSOR_H
#define CURSOR_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Game_Piece.h"
using namespace std;

class Cursor: public Game_Piece {
  public:
    Cursor();					// Default constructor
    Cursor(string, string, SDL_Renderer*, int, int);	// Non-default constructor
    ~Cursor();					// Deconstructor
    draw(SDL_Renderer*, int);			// Draw the cursor to the screen
  private:
    SDL_Texture* cursor_1;	// Outer cursor
    SDL_Texture* cursor_2;	// Inner cursor
};
#endif
