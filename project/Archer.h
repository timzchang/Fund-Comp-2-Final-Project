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
    Archer(string, int, int, SDL_Renderer*,vector<vector <int> >);// non-default constructor
  private:
};
#endif
