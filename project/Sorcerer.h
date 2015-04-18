// Sorcerer.h
// interface for the Sorcerer class. Derivative of Character, sets certain stats. Has no
// data members. The uniqueness comes in because it has speicifc stats that are set
// in the constructor

#ifndef SORCERER_H
#define SORCERER_H
#include<vector>
#include<string>
#include"Map.h"
#include"Character.h"
class Sorcerer: public Character{
  public:
    Sorcerer();					// default constructor
    Sorcerer(string, int, int, SDL_Renderer*,vector<vector <int> >);// non-default constructor
  private:
};
#endif
