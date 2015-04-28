// Fundamentals of Computer II Final Project		April 21, 2015
// Tim Chang, Mason Prosser, Lucas Unruh, Christopher Syers

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
  font = TTF_OpenFont(path_font.c_str(),56);		// loads the font with size 56 (might change later)
  if (font==NULL){					// checks to see if the font loaded correctly
    cout << "Could not load font" << endl;
  } 
  loaded_surface = IMG_Load(path_blue.c_str());		
  blue_menu = SDL_CreateTextureFromSurface(renderer,loaded_surface);	// stores the blue menu
  SDL_FreeSurface(loaded_surface);
  loaded_surface = NULL;
  loaded_surface = IMG_Load(path_red.c_str());
  red_menu = SDL_CreateTextureFromSurface(renderer,loaded_surface);	// stores the red menu
  SDL_FreeSurface(loaded_surface);					// frees the surface used for the creation of the textures
  loaded_surface = NULL;
}

// deconstructor
Stats_Menu::~Stats_Menu(){
// frees all of the textures and fonts if they aren't null already
  if(red_menu!=NULL){
    SDL_DestroyTexture(red_menu);
  }
  if(blue_menu!=NULL){
    SDL_DestroyTexture(blue_menu);
  }
  if(font!=NULL){
    TTF_CloseFont(font);
  }
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
void Stats_Menu::draw(SDL_Renderer* renderer, int y, int map_height, int team, string name, int currHP, int maxHP, int attack, int defence){
  SDL_Surface* loadedText;
  SDL_Color color = {255,255,255};		// sets color to white
  string name_str = "Name: " + name;		// loads the name string with a label
  string attack_str = "Attack: " + to_string(attack);		// loads the attack string with a label (needs c++ 11)
  string defence_str = "Defence: " + to_string(defence);	// loads the defence string with a label (needs c++ 11)
  string hit_points = "Hitpoints: " + to_string(currHP) + "/" + to_string(maxHP);	// loads the hitpoints in the form curr/max.  (c++ 11)
  loadedText = TTF_RenderText_Blended(font, name_str.c_str(), color);	// creates a surface for the name text
  SDL_Texture* nameTexture = SDL_CreateTextureFromSurface(renderer,loadedText);		// creates a nameTexture
  SDL_FreeSurface(loadedText);		// free and ground pointer every time
  loadedText = NULL;
  loadedText = TTF_RenderText_Blended(font,hit_points.c_str(),color);			// creates a surface for the hitpoints 
// Continue this process for the rest of the texts
  SDL_Texture* hitpointsTexture = SDL_CreateTextureFromSurface(renderer,loadedText);	
  SDL_FreeSurface(loadedText);
  loadedText = NULL;
  loadedText = TTF_RenderText_Blended(font, attack_str.c_str(), color);
  SDL_Texture* attackTexture = SDL_CreateTextureFromSurface(renderer,loadedText);
  SDL_FreeSurface(loadedText);
  loadedText = NULL;
  loadedText = TTF_RenderText_Blended(font, defence_str.c_str(), color);
  SDL_Texture* defenceTexture = SDL_CreateTextureFromSurface(renderer,loadedText);
  SDL_FreeSurface(loadedText);
  loadedText = NULL;
  if(team == 1){		// blue team (player 1)
    if(y < map_height/2){	// if the character is currently in the bottom half of the screen
      SDL_Rect dest = {0,map_height*32-96,192,96};				// HARD CODED! WILL NEED TO BE CHANGED IF LEVEL 2 IS ADDED
      SDL_Rect source = {0,0,192,96};     			// gets whole image
      SDL_Rect nameRect = {10,map_height*32-90,100,20};		// size of the name
      SDL_Rect hpRect = {10,map_height*32-70,150,20};		// where to draw the hp string
      SDL_Rect attackRect = {10,map_height*32-50,80,20};	// where to draw the attack
      SDL_Rect defenceRect = {10,map_height*32-30,80,20};	// where to draw the defence 
      SDL_RenderCopy(renderer,blue_menu,NULL,&dest);		// draws the rectangle to the renderer
      SDL_RenderCopy(renderer,nameTexture,NULL,&nameRect);	// draws the name onto the screen
      SDL_RenderCopy(renderer,hitpointsTexture,NULL,&hpRect);	// draws the hitpoints to the screen
      SDL_RenderCopy(renderer,attackTexture,NULL,&attackRect);	// draws the hitpoints to the screen
      SDL_RenderCopy(renderer,defenceTexture,NULL,&defenceRect);// draws the hitpoints to the screen
    }else{			// if the character is in the top half of the screen 
      SDL_Rect dest = {0,0,192,96};				// HARD CODED! WILL NEED TO BE CHANGED IF LEVEL 2 IS ADDED
      SDL_Rect source = {0,0,192,96};     			// gets whole image
      SDL_Rect nameRect = {10,0,100,20};			// destination of the name string
      SDL_Rect hpRect = {10,20,150,20};				// where to draw the hp string
      SDL_Rect attackRect = {10,40,80,20};			// where to draw the attack
      SDL_Rect defenceRect = {10,60,80,20};			// where to draw the defence 
      SDL_RenderCopy(renderer,blue_menu,&source,&dest);		// draws the rectangle to the renderer
      SDL_RenderCopy(renderer,nameTexture,NULL,&nameRect);	// draws the name onto the renderer
      SDL_RenderCopy(renderer,attackTexture,NULL,&attackRect);	// draws the hitpoints to the screen
      SDL_RenderCopy(renderer,defenceTexture,NULL,&defenceRect);// draws the hitpoints to the screen
      SDL_RenderCopy(renderer,hitpointsTexture,NULL,&hpRect);	// draws the hitpoints to the screen
    }
  }else{			// red team (player 2)
    if(y < map_height/2){	// if the character is in the bottom half the screen
      SDL_Rect dest = {0,map_height*32-96,192,96};		// HARD CODED! WILL NEED TO BE CHANGED IF LEVEL 2 IS ADDED
      SDL_Rect source = {0,0,192,96};     			// gets whole image
      SDL_Rect nameRect = {10,map_height*32-90,100,20};		// size of the name
      SDL_Rect hpRect = {10,map_height*32-70,150,20};		// where to draw the hp string
      SDL_Rect attackRect = {10,map_height*32-50,80,20};	// where to draw the attack
      SDL_Rect defenceRect = {10,map_height*32-30,80,20};	// where to draw the defence 
      SDL_RenderCopy(renderer,red_menu,&source,&dest);		// draws the rectangle to the renderer
      SDL_RenderCopy(renderer,nameTexture,NULL,&nameRect);	// draws the name onto the screen
      SDL_RenderCopy(renderer,attackTexture,NULL,&attackRect);	// draws the hitpoints to the screen
      SDL_RenderCopy(renderer,defenceTexture,NULL,&defenceRect);// draws the hitpoints to the screen
      SDL_RenderCopy(renderer,hitpointsTexture,NULL,&hpRect);	// draws the hitpoints to the screen
    }else{			// if the character is in the top hald of the screen
      SDL_Rect dest = {0,0,192,96};				// HARD CODED! WILL NEED TO BE CHANGED IF LEVEL 2 IS ADDED
      SDL_Rect source = {0,0,192,96};     			// gets whole image
      SDL_Rect nameRect = {10,0,100,20};			// size of the name
      SDL_Rect hpRect = {10,20,150,20};				// where to draw the hp string
      SDL_Rect attackRect = {10,40,80,20};			// where to draw the attack
      SDL_Rect defenceRect = {10,60,80,20};			// where to draw the defence 
      SDL_RenderCopy(renderer,red_menu,&source,&dest);		// draws the rectangle to the renderer
      SDL_RenderCopy(renderer,nameTexture,NULL,&nameRect);	// draws the name onto the screen
      SDL_RenderCopy(renderer,attackTexture,NULL,&attackRect);	// draws the hitpoints to the screen
      SDL_RenderCopy(renderer,defenceTexture,NULL,&defenceRect);// draws the hitpoints to the screen
      SDL_RenderCopy(renderer,hitpointsTexture,NULL,&hpRect);	// draws the hitpoints to the screen
    }
  }
// FREE AND GROUND ALL POINTERS THAT WERE USED
  SDL_DestroyTexture(nameTexture);
  nameTexture = NULL;
  SDL_DestroyTexture(attackTexture);
  nameTexture = NULL;
  SDL_DestroyTexture(hitpointsTexture);
  hitpointsTexture = NULL;
  SDL_DestroyTexture(nameTexture);
  nameTexture = NULL;
}
