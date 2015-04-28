// Tim Chang, Mason Prosser, Lucas Unruh, Chris Syers		March 25, 2015
//   GamePiece.h						Fundamentals of Computing II Final Project
//   This is the Game Piece base class. All game pieces (characters, cursors, etc) will inherit from this class.
//   It contains information about how each piece will behave as a tile in a board (xpos, ypos, etc.)


#ifndef GAMEPIECE_H
#define GAMEPIECE_H
using namespace std;
//#include <SDL2/SDL.h>
//#include<SDL.h>
#include "Map.h"

class GamePiece{
 public:
  // constructors:
  GamePiece();
  GamePiece(int,int);			
  // member functions:
  virtual void move(int); 		//move function is universal for all game pieces
  virtual void move(int,int,int);	// move function that takes in a max x and max y in addition to direction
  virtual void draw(SDL_Renderer*) = 0; // each draw function of derived classes will be slightly different
  virtual void update() = 0;		// update will do something different for each dervied class
  //virtual void check_select(Character *) = 0;
  // get set variables:
  void setx(int);
  void sety(int);
  int getx();
  int gety();
 protected:
  int xpos; //the x and y position of game pieces
  int ypos;
};



#endif
