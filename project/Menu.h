// Christopher Syers, Lucas Unruh, Mason Prosser, Tim Chang	April 28, 2015
// Menu.h

// Interface of the Menu class. It is drawn at the beginning of the main function.
// It has a menu texture, and instruction texture, and a sword cursor.

#ifndef MENU_H
#define MENU_H
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
using namespace std;

class Menu {
  public:
    Menu(string, string, string, SDL_Renderer*);		// non-default constructor
    ~Menu();							// deconstructor
    void display_menu(SDL_Renderer*);				// draws the menu and cursor
    void display_instruction(SDL_Renderer*);			// displays the instruction_text texture
    void cursor_up();						// changes the phase of the cursor
    void cursor_down();						// changes the phase of the cursor
    int get_phase();						// returns the phase of the counter
  private:
    // textures for each of the images
    SDL_Texture* menu_text;	
    SDL_Texture* cursor_text;
    SDL_Texture* instruction_text;
    int phase;							// phase determines where the sword cursor is drawn
    
};
#endif
