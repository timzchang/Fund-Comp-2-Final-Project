// Christopher Syers, Mason Prosser, Lucas Unruh, and Tim Chang
// Fundamentals of Computing II Final Project

// April 25, 2015

// Interface for Choice_Menu class, which is a text box that will be displayed after a character
// picks a new location to move to. It will include options to wait or attack.

#ifndef CHOICE_MENU_H
#define CHOICE_MENU_H
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
//#include<SDL.h>
//#include<SDL_image.h>
#include <string>
#include <SDL2/SDL_ttf.h>
//#include<SDL_ttf.h>
using namespace std;

class Choice_Menu{
  public:
    Choice_Menu(); // default constructor
    Choice_Menu(SDL_Renderer*,string,string);		// non-default constructor
    ~Choice_Menu();					// deconstructor
    int draw(SDL_Renderer*,int,int);		// function that draws the menu to the screen
  private:
    SDL_Texture* menu_image_attack;
    SDL_Texture* menu_image_wait;
};

#endif
