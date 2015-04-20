// Soldier.h
// interface for the Soldier class. Derivative of Character, sets certain stats. Has no
// data members. The uniqueness comes in because it has speicifc stats that are set
// in the constructor

#ifndef SOLDIER_H
#define SOLDIER_H
#include<vector>
#include<string>
#include"Map.h"
#include"Character.h"
class Soldier: public Character{
  public:
    Soldier();					// default constructor
    Soldier(string,string, int, int, SDL_Renderer*,vector<vector <int> >);// non-default constructor
  private:
};
#endif
