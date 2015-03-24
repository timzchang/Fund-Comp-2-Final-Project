// Tester for Map class



#include "Map.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//const int SCREEN_WIDTH = 240;
//const int SCREEN_HEIGHT = 240;

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;

int main(){
  Map level1;
  SDL_Init(SDL_INIT_VIDEO);
//  window = SDL_CreateWindow("Maps",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,level1.getWidth(),level1.getHeight());
  window = SDL_CreateWindow("Fire Emblem",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,240,240,SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  SDL_SetRenderDrawColor(renderer,255,255,255,255);
/*  level1.setRenderer(renderer);
  int imgFlags = IMG_INIT_PNG;
  if(!(IMG_Init(imgFlags) & imgFlags)){
    std::cout << "SDL_image couldn't initialize!\n";
  }

  level1.loadImage("../maps/small_map.png");


  bool quit = false;
  SDL_Event e;

  while(!quit){
    while(SDL_PollEvent(&e) != 0){
      if(e.type==SDL_QUIT)
	quit = true;
    }
    SDL_RenderClear(renderer);
    level1.render_map();

    SDL_RenderPresent(renderer);
  }

*/
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  window = NULL;
  renderer = NULL;

  IMG_Quit();
  SDL_Quit();

  return 0;
}
