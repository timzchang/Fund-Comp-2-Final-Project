/* Mason Prosser		3/24/15
ball.cpp
Implementation of ball class for testing out SDL */

#include "ball.h"

Ball::Ball(){
  image = NULL;
}

Ball::~Ball(){
  SDL_FreeSurface(image);
  image = NULL;
}

void Ball::loadImage(std::string path, SDL_Surface* screen){
  SDL_Surface* optimizedSurface = NULL;
  std::cout << "a" << std::endl;
  SDL_Surface* ball_image = IMG_Load(path.c_str());
  std::cout << "b" << std::endl;
  if(ball_image == NULL){
    std::cout << "Unable to load image!" << std::endl;
  }else{
    optimizedSurface = SDL_ConvertSurface(ball_image, screen->format, 0);
    std::cout << "c" << std::endl;
    if(optimizedSurface == NULL){
      std::cout << "Unable to optimize image!" << SDL_GetError() << std::endl;
    }
    std::cout << "d" << std::endl;
    SDL_FreeSurface(ball_image);
  }

  image = optimizedSurface;
}
