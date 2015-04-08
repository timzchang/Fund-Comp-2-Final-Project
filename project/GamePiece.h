/* Tim Chang, Mason Prosser, Lucas Unruh, Chris Syers
   GamePiece.h
   This is the Game Piece base class. All game pieces (characters, cursors, etc) will inherit from this class.
 */

#ifndef GAMEPIECE_H
#define GAMEPIECE_H
using namespace std;

class GamePiece{
 public:
  GamePiece(int,int);
  void move(int,int); //move function is universal for all game pieces
  virtual void draw() = 0; //each draw function of derived classes will be slightly different
  void setx(int);
  void sety(int);
  int getx();
  int gety();
 protected:
  int xpos; //the x and y position of game pieces
  int ypos;
};



#endif
