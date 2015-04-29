#ifndef MENU_H
#define MENU_H
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
using namespace std;

class Menu {
  public:
    Menu(string, string, SDL_Renderer*);
    ~Menu();
    int display_menu(SDL_Renderer*);
    int display_instruction(SDL_Renderer*);
  private:
    SDL_Texture* menu_text;
    SDL_Texture* cursor_text;
    int phase;
    
};
#endif

Menu::Menu(string menu_path, string cursor_path, SDL_Renderer* renderer){
  phase=0;
  SDL_Surface* menu_surface = IMG_Load(menu_path.c_str());
  SDL_Surface* cursor_surface = IMG_Load(cursor_path.c_str());
  menu_text = SDL_CreateTextureFromSurface(renderer, menu_surface);
  cursor_text = SDL_CreateTextureFromSurface(renderer, cursor_surface);
  SDL_FreeSurface(menu_surface);
  SDL_FreeSurface(cursor_surface);
  menu_surface = NULL;
  cursor_surface = NULL;
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
}

int Menu::display_menu(SDL_Renderer* renderer){
  SDL_RenderCopy(renderer, menu_text, NULL, NULL);
  SDL_Rect Rect = {50, 50, 216, 72};
  SDL_RenderCopy(renderer, cursor_text, NULL, &Rect);
  return 1;
}

int Menu::display_instruction(SDL_Renderer* renderer){

}
