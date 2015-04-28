// Christopher Syers, Tim Chang, Lucas Unruh, and Mason Prosser
// Fundamentals of Computing II Final Project

// April 25, 2015

// Tim Chang, Mason Prosser, Christopher Syers, Luncas Unruh

// Implementation of the Choice_Menu class. Includes definitions for constructors and a draw function

#include "Choice_Menu.h"

// default constructor
Choice_Menu::Choice_Menu(){
  menu_image_attack = NULL;
  menu_image_wait = NULL;
}

// non deafult constructor that loads an image to the texture
Choice_Menu::Choice_Menu(SDL_Renderer* renderer,string attack_path, string wait_path){
  SDL_Surface* loadedSurface = NULL;							// temporary surface
  loadedSurface = IMG_Load(attack_path.c_str());					// loads attack_path png into loadedSurface
  menu_image_attack = SDL_CreateTextureFromSurface(renderer,loadedSurface); 		// creates the menu_image_attack texture
  SDL_FreeSurface(loadedSurface);							// free the surface
  loadedSurface = NULL;
  loadedSurface = IMG_Load(wait_path.c_str());						// loads the other png for the wait option
  menu_image_wait = SDL_CreateTextureFromSurface(renderer,loadedSurface); 		// creates the menu_image_wait texture
  SDL_FreeSurface(loadedSurface);							// frees the surface
  loadedSurface = NULL;
}

// deconstructor
Choice_Menu::~Choice_Menu(){
  if(menu_image_attack!=NULL){
    SDL_DestroyTexture(menu_image_attack);
    menu_image_attack = NULL;
  }
  if(menu_image_wait!=NULL){
    SDL_DestroyTexture(menu_image_wait);
    menu_image_wait = NULL;
  }
}

// draws the menu to the screen. Doesn't do anything really because we decided
// to remove it from the game before this function was written properly.
int Choice_Menu::draw(SDL_Renderer* renderer, int x, int y){
  SDL_RenderCopy(renderer,menu_image_attack,NULL,NULL);
}
