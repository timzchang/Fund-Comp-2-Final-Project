// Fundamentals of Computer II Final Project		April 21, 2015

// Implementation of the Stats_Menu class.

#include "Stats_Menu.h"

// default constructor (sets things to null)
Stats_Menu::Stats_Menu(){
  red_menu = NULL;
  blue_menu = NULL;
  font = NULL; 
}

// non-default constructor (this is the one that will be used)
Stats_Menu::Stats_Menu(string path_blue, string path_red, string path_font, SDL_Renderer* renderer){
  SDL_Surface* loaded_surface;
  font = TTF_OpenFont(path_font.c_str(),28);		// loads the font with size 28 (might change later)
  if (font==NULL){					// checks to see if the font loaded correctly
    cout << "Could not load font" << endl;
  } 
  loaded_surface = IMG_Load(path_blue.c_str());		
  blue_menu = SDL_CreateTextureFromSurface(renderer,loaded_surface);	// stores the blue menu
  SDL_FreeSurface(loaded_surface);
  loaded_surface = IMG_Load(path_red.c_str());
  red_menu = SDL_CreateTextureFromSurface(renderer,loaded_surface);	// stores the red menu
  SDL_FreeSurface(loaded_surface);					// frees the surface used for the creation of the textures
  loaded_surface = NULL;
}

// deconstructor
Stats_Menu::~Stats_Menu(){
// frees all of the textures and fonts
  SDL_DestroyTexture(red_menu);
  SDL_DestroyTexture(blue_menu);
  TTF_CloseFont(font);
  red_menu = NULL;
  blue_menu = NULL;
  font = NULL;
}

// TEST FUNCTION: NOT ACTUALLY USED
void Stats_Menu::print_stats(){
  int w,h;
  SDL_QueryTexture(red_menu,NULL,NULL,&w,&h);
  cout << "Width: " << w << "\t Height: " << h << endl;		// prints out height and width of texture
}

// function to draw the stat menu
void Stats_Menu::draw(SDL_Renderer* renderer, int y, int map_height, int team){
  if(team == 1){		// blue team (player 1)
    if(y < map_height/2){	// if the character is currently in the bottom half of the screen
      SDL_Rect dest = {0,map_height*32-96,192,96};				// HARD CODED! WILL NEED TO BE CHANGED IF LEVEL 2 IS ADDED
      SDL_Rect source = {0,0,192,96};     			// gets whole image
      SDL_RenderCopy(renderer,blue_menu,&source,&dest);		// draws the rectangle to the renderer
    }else{			// if the character is in the top half of the screen 
      SDL_Rect dest = {0,0,192,96};				// HARD CODED! WILL NEED TO BE CHANGED IF LEVEL 2 IS ADDED
      SDL_Rect source = {0,0,192,96};     			// gets whole image
      SDL_RenderCopy(renderer,blue_menu,&source,&dest);		// draws the rectangle to the renderer
    }
  }else{			// red team (player 2)
    if(y < map_height/2){	// if the character is in the bottom half the screen
      SDL_Rect dest = {0,map_height*32-96,192,96};				// HARD CODED! WILL NEED TO BE CHANGED IF LEVEL 2 IS ADDED
      SDL_Rect source = {0,0,192,96};     			// gets whole image
      SDL_RenderCopy(renderer,red_menu,&source,&dest);		// draws the rectangle to the renderer
    }else{			// if the character is in the top hald of the screen
      SDL_Rect dest = {0,0,192,96};				// HARD CODED! WILL NEED TO BE CHANGED IF LEVEL 2 IS ADDED
      SDL_Rect source = {0,0,192,96};     			// gets whole image
      SDL_RenderCopy(renderer,red_menu,&source,&dest);		// draws the rectangle to the renderer
    }
  }
}
