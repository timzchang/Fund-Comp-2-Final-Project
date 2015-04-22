    /* CSE20212 Final Project                4/7/2015
   Mason Prosser, Tim Chang, Chris Syers, Lucas Unruh
   Cursor.h
   Header file for cursor, which will be the player's way of interacting with the map */

#ifndef CURSOR_H
#define CURSOR_H

#include <string>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include "GamePiece.h"
#include "Character.h"
#include "Map.h"
#include <vector>
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
    void move(int,int,int);
    void toggle_select(vector<Character *> *, Map *); //if the cursor is over a character, it will be selected or deselected. If it is not over a character and the move vector>1, we process_move_vector
    void move_select(vector<Character *> *, int move, Map *); //loop through character vector, if a character is selected (there should only be one at a time), update a move vector.
    //TEST FUNCTION PLEASE IGNORE
    void test_move(int change, int max_width, int max_height);
  private:
    int phase;			// phase of the cursor (0 for big, 1 for small)
    SDL_Texture* cursor_1;	// Outer cursor
    SDL_Texture* cursor_2;	// Inner cursor
    int counter;
};
#endif
