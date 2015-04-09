/* CSE20212 Final Project                4/7/2015
   Mason Prosser, Tim Chang, Chris Syers, Lucas Unruh
   Cursor.h
   Header file for cursor, which will be the player's way of interacting with the map */

#ifndef CURSOR_H
#define CURSOR_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GamePiece.h"
using namespace std;

class Cursor: public GamePiece {
  public:
    Cursor();					// Default constructor
    Cursor(string, string, SDL_Renderer*, int, int);	// Non-default constructor
    ~Cursor();					// Deconstructor
    void draw(SDL_Renderer*);			// Draw the cursor to the screen
    void next_phase();				// changes the phase of the cursor
    int get_phase();				// gets current phase of the cursor
    void update();				// updates clock counts
    void setHitpoints(int);
    int getHitpoints();
  private:
    int phase;			// phase of the cursor (0 for big, 1 for small)
    SDL_Texture* cursor_1;	// Outer cursor
    SDL_Texture* cursor_2;	// Inner cursor
    int counter;
};
#endif
