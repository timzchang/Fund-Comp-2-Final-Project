// Christopher Syers, Tim Chang, Lucas Unruh, Mason Prosser
// April 10, 2015		Fund Comp II Project: Fire Emblem
// Valid_board.h

// Interface for a Valid_board class that contains a 2d vector of ints the size
// of the Map, and functionality to resize it and clear it to 0. Will be modified
// by the check_valid function of a Character object.

#ifndef VALID_BOARD_H
#define VALID_BOARD_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <vector>
#include <string>
using namespace std;

class Valid_board{
  public:
    Valid_board(int=0,int=0);				// non-default constrctor with deafult values of 0 and 0
    Valid_board(int,int,string,SDL_Renderer*);		// the non-default constructor that will acutally be used
    ~Valid_board();					// destructor
    void to_zeros();					// sets the current 2d vector of ints to all 0s
    void resize(int, int);				// resizes the board and fills it with 0s
    void print();					// for testing purposes
    void set_tile(int,int);				// sets tile (int, int) to 1
    int get_num_rows();					// returns the number of rows
    int get_num_cols();					// returns the number of column
    void draw(SDL_Renderer*);				// draws all valid location with 
  private:
    vector< vector<int> > valid_tiles;			// stores 0s and 1s, 0s where a character cannot go and 1s where it can
    SDL_Texture* blue_highlight;			// stores the picture of the blue highlight
};

#endif
