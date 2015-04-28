// Fundmentals of Computing II: Final Project		April 28, 2015
// Christopher Syers, Tim Chang, Lucas Unruh, Mason Prosser

// Mage.h
// interface for the Mage class. Derivative of Character, sets certain stats. Has no
// data members. The uniqueness comes in because it has speicifc stats that are set
// in the constructor

#ifndef MAGE_H
#define MAGE_H
#include<vector>
#include<string>
#include"Map.h"
#include"Character.h"
class Mage: public Character{
  public:
    Mage();					// default constructor
    Mage(string,string, int, int, int, SDL_Renderer*,vector<vector <int> >);// non-default constructor
  private:
};
#endif
