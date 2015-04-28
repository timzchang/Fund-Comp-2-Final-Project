// Christopher Syers, Mason Prosser, Lucas Unruh, and Tim Chang
// Fundamentals of Computing II Final Project

// April 25, 2015

// Christopher Syers, Mason Prosser, Lucas Unruh, Tim Chang

// Interface for Choice_Menu class, which is a text box that will be displayed after a character
// picks a new location to move to. It will include options to wait or attack. This class is not
// going to be in the final version of the game.

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
    Choice_Menu(); 					// default constructor
    Choice_Menu(SDL_Renderer*,string,string);		// non-default constructor
    ~Choice_Menu();					// deconstructor
    int draw(SDL_Renderer*,int,int);			// function that draws the menu to the screen
  private:
    SDL_Texture* menu_image_attack;			// image for the option to attack
    SDL_Texture* menu_image_wait;			// image for the option to wait
};

#endif
