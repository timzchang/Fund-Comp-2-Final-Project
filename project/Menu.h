#ifndef MENU_H
#define MENU_H
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
using namespace std;

class Menu {
  public:
    Menu(string, string, SDL);
    int display();
    int instruction();
  private:
    SDL_Texture* menu_text;
    SDL_Texture* cursor_text;
    
};
#endif

Menu::Menu(string menu_path, string cursor_path, SDL_Renderer* renderer){
  SDL_Surface* menu_surface = IMG_Load(menu_path.c_str());
  SDL_Surface* cursor_surface = IMG_Load(cursor_path.c_str());
  menu_text = SDL_CreateTextureFromSurface(renderer, menu_surface);
  cursor_text = SDL_CreateTextureFromSurface(renderer, cursor_surface);
  SDL_FreeSurface(menu_surface);
  SDL_FreeSurface(cursor_surface);
}

int Menu::display(){
  SDL_RenderCopy(renderer, menu_text);
  SDL_Rect Rect = {50, 50, 216, 72};
  SDL_RenderCopy(renderer, cursor_text, Rect);
  return 1;
}

int Menu::instruction(){

}
