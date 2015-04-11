// Christopher Syers, Tim Chang, Lucas Unruh, Mason Prosser
// April 10, 2015		Fund Comp II Project: Fire Emblem
// Valid_board.h

// Interface for a Valid_board class that contains a 2d vector of ints the size
// of the Map, and functionality to resize it and clear it to 0. Will be modified
// by the check_valid function of a Character object.

#ifndef VALID_BOARD_H
#define VALID_BOARD_H

#include <vector>
using namespace std;

class Valid_board{
  public:
    Valid_board(int=0,int=0);			// non-deafult constructor with default values of 0 and 0
    void to_zeros();				// sets the current 2d vector of ints to all 0s
    void resize(int, int);			// resizes the board and fills it with 0s
    void print();				// for testing purposes
    void set_tile(int,int);			// sets tile (int, int) to 1
    int get_num_rows();				// returns the number of rows
    int get_num_cols();				// returns the number of column
  private:
    vector< vector<int> > valid_tiles;		// stores 0s and 1s, 0s where a character cannot go and 1s where it can
};

#endif
