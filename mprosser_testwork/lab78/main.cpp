/* Mason Prosser		3/24/15
main.cpp
Driver to test placing a Ball object in a window */

#include "ball.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void init(std::string, SDL_Surface*);	// Initialize SDL2 and SDL2_image
//void loadTex(std::string);	// Loads image as texture
void blit();	// Draw background and ball to window, then update
void end();	// Free memory

SDL_Window* window = NULL;
SDL_Surface* screen = NULL;
SDL_Surface* background = NULL;
//SDL_Texture* bgtexture = NULL;
SDL_Surface* image = NULL;
SDL_Renderer* renderer = NULL;

int main(){
  Ball ball_1;	// Instantiate Ball object
  std::cout << "0" << std::endl;
  init("background.png", screen);
  std::cout << "1" << std::endl;
//  loadTex("background.png");
  std::cout << "1.5" << std::endl;
  ball_1.loadImage("ball.png", screen);
  std::cout << "2" << std::endl;

  blit();
  std::cout << "3" << std::endl;
  SDL_Delay(2000);
  end();
  std::cout << "4" << std::endl;
}

void init(std::string path, SDL_Surface* screen){
  // Initialize SDL
  std::cout << "a" << std::endl;
  if(SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cout << "SDL couldn't initialize!" << std::endl;
  }
  std::cout << "b" << std::endl;
  window = SDL_CreateWindow("Lab 7/8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN);
  std::cout << "c" << std::endl;
  // Initialize SDL_image
  int imgFlags = IMG_INIT_PNG;
  if(!(IMG_Init(imgFlags) & imgFlags)){
    std::cout << "SDL_image couldn't initialize!" << std::endl;
  }else{
    screen = SDL_GetWindowSurface(window);
  }
  std::cout << "d" << std::endl;
/*
  // Create renderer for window
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(renderer == NULL){
    std::cout << "Renderer not created!" << SDL_GetError() << std::endl;
  }else{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  }*/

  // Create background
  SDL_Surface* loadedSurface = NULL;
  loadedSurface = IMG_Load(path.c_str());
  background = SDL_ConvertSurface(loadedSurface, screen->format, 0);
  if(background == NULL){
    std::cout << "Couldn't optimize background!" << std::endl;
  }
  SDL_FreeSurface(loadedSurface);
}
/*
void loadTex(std::string path){
  background = IMG_Load(path.c_str());
  bgtexture = SDL_CreateTextureFromSurface(renderer, background);
  if(bgtexture == NULL){
    std::cout << "Couldn't create texture!" << SDL_GetError() << std::endl;
  }

  SDL_FreeSurface(background);
}*/

void blit(){
  std::cout << "a" << std::endl;
//  SDL_RenderClear(renderer);
  SDL_BlitSurface(background, NULL, screen, NULL);
  std::cout << "b" << std::endl;
//  SDL_RenderCopy(renderer, bgtexture, NULL, NULL);
  std::cout << "c" << std::endl;
//  SDL_RenderPresent(renderer);
  SDL_UpdateWindowSurface(window);
  std::cout << "d" << std::endl;

  SDL_BlitSurface(image, NULL, screen, NULL);
  std::cout << "e" << std::endl;
  SDL_UpdateWindowSurface(window);
  std::cout << "f" << std::endl;
}

void end(){
  SDL_DestroyWindow(window);
  window = NULL;

  screen = NULL;

//  SDL_DestroyTexture(bgtexture);
  background = NULL;

  SDL_Quit();
  IMG_Quit();
}
