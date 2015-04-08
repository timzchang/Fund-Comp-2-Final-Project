/*Tim Chang, Mason Prosser, Lucas Unruh, Chris Syers
  GamePiece.cpp
  Implementation of Gamepiece class. Only the crucial move function is really in here.
*/

#include"GamePiece.h"

GamePiece::GamePiece(int x, int y){
  xpos = x;
  ypos = y;
}

void GamePiece::move(int direction){
  switch(direction){
  case 0:
    y -= 1;
    break;
  case 1:
    x += 1;
    break;
  case 2:
    y -= 1;
    break;
  case 3:
    x -= 1;
  }
}

void GamePiece::setx(int x){
  xpos = x;
}

void GamePiece::sety(int y){
  ypos = y;
}

int GamePiece::getx(){
  return xpos;
}

int GamePiece::gety(){
  return ypos;
}
