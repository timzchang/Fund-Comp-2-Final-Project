#include "Menu.h"

Menu::Menu(string menu_path, string cursor_path, string instruction_path, SDL_Renderer* renderer){
  phase=0;
  SDL_Surface* menu_surface = IMG_Load(menu_path.c_str());
  SDL_Surface* cursor_surface = IMG_Load(cursor_path.c_str());
  SDL_Surface* instruction_surface = IMG_Load(instruction_path.c_str());
  menu_text = SDL_CreateTextureFromSurface(renderer, menu_surface);
  cursor_text = SDL_CreateTextureFromSurface(renderer, cursor_surface);
  instruction_text = SDL_CreateTextureFromSurface(renderer, instruction_surface);
  SDL_FreeSurface(menu_surface);
  SDL_FreeSurface(cursor_surface);
  SDL_FreeSurface(instruction_surface);
  menu_surface = NULL;
  cursor_surface = NULL;
  instruction_surface = NULL;
}

Menu::~Menu(){
  if(menu_text != NULL){
    SDL_DestroyTexture(menu_text);
    menu_text=NULL;
  }
  if(cursor_text != NULL){
    SDL_DestroyTexture(cursor_text);
    cursor_text=NULL;
  }
  if(instruction_text != NULL){
    SDL_DestroyTexture(instruction_text);
    instruction_text=NULL;
  }
}

void Menu::display_menu(SDL_Renderer* renderer){
  SDL_RenderCopy(renderer, menu_text, NULL, NULL);
  SDL_Rect Rect = {50, 195 +32*phase, 150, 50};
  SDL_RenderCopy(renderer, cursor_text, NULL, &Rect);
}

void Menu::display_instruction(SDL_Renderer* renderer){
  SDL_RenderCopy(renderer, instruction_text, NULL, NULL);
}

void Menu::cursor_up(){
  phase--;
  if(phase < 0) phase = 3;
}

void Menu::cursor_down(){
  phase++;
  if(phase > 3) phase = 0;
}

int Menu::get_phase(){
  return phase;
}
