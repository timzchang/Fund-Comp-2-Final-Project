// Pirate.h
// interface for the Pirate class. Derivative of Character, sets certain stats. Has no
// data members. The uniqueness comes in because it has speicifc stats that are set
// in the constructor

#ifndef PIRATE_H
#define PIRATE_H
#include<vector>
#include<string>
#include"Map.h"
#include"Character.h"
class Pirate: public Character{
  public:
    Pirate();					// default constructor
    Pirate(string, int, int, SDL_Renderer*,vector<vector <int> >);// non-default constructor
  private:
};
#endif
