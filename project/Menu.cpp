// Lucas Unruh, Mason Prosser, Tim Chang, Chris Syers		April 28, 2015
// Fundamentals of Computing II Final Project
// Menu.cpp

// implementation of the Menu class

#include "Menu.h"

// non-default constructor
Menu::Menu(string menu_path, string cursor_path, string instruction_path, string controls_path, SDL_Renderer* renderer){
  phase=0;									// starts with the cursor at the first position
  // surfaces to hold images
  SDL_Surface* menu_surface = IMG_Load(menu_path.c_str());			
  SDL_Surface* cursor_surface = IMG_Load(cursor_path.c_str());
  SDL_Surface* instruction_surface = IMG_Load(instruction_path.c_str());
  SDL_Surface* controls_surface = IMG_Load(controls_path.c_str());
  // create the four textures from the menus
  menu_text = SDL_CreateTextureFromSurface(renderer, menu_surface);
  cursor_text = SDL_CreateTextureFromSurface(renderer, cursor_surface);
  instruction_text = SDL_CreateTextureFromSurface(renderer, instruction_surface);
  controls_text = SDL_CreateTextureFromSurface(renderer, controls_surface);
  // free the surfaces
  SDL_FreeSurface(menu_surface);
  SDL_FreeSurface(cursor_surface);
  SDL_FreeSurface(instruction_surface);
  SDL_FreeSurface(controls_surface);
  // ground the pointers 
  menu_surface = NULL;
  cursor_surface = NULL;
  instruction_surface = NULL;
  controls_surface = NULL;
}

// deconstructor
Menu::~Menu(){
  if(menu_text != NULL){		// if it isn't already null,
    SDL_DestroyTexture(menu_text);	// destroy it
    menu_text=NULL;
  }
  if(cursor_text != NULL){		// if it isn't already null,
    SDL_DestroyTexture(cursor_text);	// destroy it
    cursor_text=NULL;
  }
  if(instruction_text != NULL){		// if it isn't already null
    SDL_DestroyTexture(instruction_text);	// destroy it 
    instruction_text=NULL;
  }
  if(controls_text != NULL){         // if it isn't already null
    SDL_DestroyTexture(controls_text);       // destroy it
    controls_text=NULL;
  }
}

// function that draws the menu onto the screen (and the cursor)
void Menu::display_menu(SDL_Renderer* renderer){
  SDL_RenderCopy(renderer, menu_text, NULL, NULL);		// draw the menu
  SDL_Rect Rect = {50, 195 +32*phase, 150, 50};			// destination rectangle of the sword cursor. 
  SDL_RenderCopy(renderer, cursor_text, NULL, &Rect);		// draw the sword cursor
}

// function that draws the instruction menu onto the screen
void Menu::display_instruction(SDL_Renderer* renderer){
  SDL_RenderCopy(renderer, instruction_text, NULL, NULL);	// draw the instructions
}

// function that draws the controls list onto the screen
void Menu::display_controls(SDL_Renderer* renderer){
  SDL_RenderCopy(renderer, controls_text, NULL, NULL);          //draws the controls list
}

// function that allows the sword cursor to be moved up
void Menu::cursor_up(){
  phase--;			// reduce the phase of the cursor 
  if(phase < 0) phase = 3;	// if you click up from the first position, move it to the last position
}

// function that allows that sword cursor to be moved down
void Menu::cursor_down(){
  phase++;			// increment the phase
  if(phase > 3) phase = 0;	// if you click down from the last one, go up to the first one
}

// function that returns that phase of the cursor
int Menu::get_phase(){
  return phase;
}
