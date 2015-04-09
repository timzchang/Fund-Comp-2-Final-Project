/* Tim Chang, Mason Prosser, Lucas Unruh, Chris Syers
   GamePiece.h
   This is the Game Piece base class. All game pieces (characters, cursors, etc) will inherit from this class.
 */

#ifndef GAMEPIECE_H
#define GAMEPIECE_H
using namespace std;
#include <SDL2/SDL.h>

class GamePiece{
 public:
  GamePiece();
  GamePiece(int,int);
  void move(int); //move function is universal for all game pieces
  virtual void draw(SDL_Renderer*) = 0; // each draw function of derived classes will be slightly different
  virtual void update() = 0;		// update will do something different for each dervied class
  void setx(int);
  void sety(int);
  int getx();
  int gety();
 protected:
  int xpos; //the x and y position of game pieces
  int ypos;
};



#endif
