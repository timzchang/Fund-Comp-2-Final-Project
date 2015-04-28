// Tim Chang, Mason Prosser, Lucas Unruh, Chris Syers
//  GamePiece.cpp		March 25, 2015		Fundamentals of Computing II Final Project
//  Implementation of Gamepiece class. Only the crucial move function is really in here.

#include"GamePiece.h"
#include <iostream>
using namespace std;

// default constructor
GamePiece::GamePiece(){
  xpos = 0;
  ypos = 0;
}

// non-default constructor: called in the non-default constructors of all of the derived classes
GamePiece::GamePiece(int x, int y){
  xpos = x;
  ypos = y;
}

// move function that shouldn't be called. Each derived class should have its own implementation of this
void GamePiece::move(int direction){
  switch(direction){
  case 0:
    ypos -= 1;
    break;
  case 1:
    xpos += 1;
    break;
  case 2:
    ypos += 1;
    break;
  case 3:
    xpos -= 1;
  }
}

// set function for a GamePiece's xpos
void GamePiece::setx(int x){
  xpos = x;
}

// set function for a GamePiece's ypos
void GamePiece::sety(int y){
  ypos = y;
}

// returns the current xpos of the object
int GamePiece::getx(){
  return xpos;
}

// returns the current ypos of the object
int GamePiece::gety(){
  return ypos;
}

// this function should never be run as a GamePiece - each derived class should have their own implementation of it.
void GamePiece::move(int choice, int a, int b){
  std::cout<<"This shouldn't be here"<<std::endl;
}
