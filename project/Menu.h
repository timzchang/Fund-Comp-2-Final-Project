#ifndef MENU_H
#define MENU_H
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
using namespace std;

class Menu {
  public:
    Menu(string, string, string, SDL_Renderer*);
    ~Menu();
    void display_menu(SDL_Renderer*);
    void display_instruction(SDL_Renderer*);
    void cursor_up();
    void cursor_down();
    int get_phase();
  private:
    SDL_Texture* menu_text;
    SDL_Texture* cursor_text;
    SDL_Texture* instruction_text;
    int phase;
    
};
#endif
