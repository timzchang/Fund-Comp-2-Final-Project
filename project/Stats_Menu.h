// Fundamentals of Computing II Final Project		April 21, 2015

// Header file for the State_Menu class. This class will contain a couple of
// images, a font, and the ability to draw the stats to the screen.

#ifndef STATS_MENU_H
#define STATS_MENU_H

#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <string>
using namespace std;

class Stats_Menu{
  public:
    Stats_Menu();					// default constructor
    Stats_Menu(string,string,string,SDL_Renderer*);	// non-default constructor
    ~Stats_Menu();					//destructor
    void draw(SDL_Renderer*,int,int,int,string,int,int,int,int);		// draws the menu to the screen (when player is at pos (arg2,arg3) and is on team arg4
    void print_stats();
  private:
    SDL_Texture* blue_menu;				// texture for blue background image
    SDL_Texture* red_menu;				// texture for red background image
    TTF_Font* font;					// font for text
};

#endif
