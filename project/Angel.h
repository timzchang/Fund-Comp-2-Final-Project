// Fundmentals of Computing II: Final Project		April 28, 2015
// Christopher Syers, Tim Chang, Lucas Unruh, Mason Prosser

// Angel.h
// interface for the Angel class. Derivative of Character, sets certain stats. Has no
// data members. The uniqueness comes in because it has speicifc stats that are set
// in the constructor

#ifndef ANGEL_H
#define ANGEL_H
#include<vector>
#include<string>
#include"Map.h"
#include"Character.h"
class Angel: public Character{
  public:
    Angel();					// default constructor
    Angel(string,string, int, int, int, SDL_Renderer*,vector<vector <int> >);// non-default constructor
  private:
};
#endif
