// Fundamentals of Computing II: Final Project		April 28, 2015
// Christopher Syers, Lucas Unruh, Mason Prosser, Tim Chang

// Archer.h
// interface for the Archer class. Derivative of Character, sets certain stats. Has no
// data members. The uniqueness comes in because it has speicifc stats that are set
// in the constructor

#ifndef ARCHER_H
#define ARCHER_H
#include<vector>
#include<string>
#include"Map.h"
#include"Character.h"
class Archer: public Character{
  public:
    Archer();					// default constructor
    Archer(string, string, int, int, int, SDL_Renderer*,vector<vector <int> >);// non-default constructor
  private:
};
#endif
