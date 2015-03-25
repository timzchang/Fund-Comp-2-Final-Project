/* Mason Prosser		3/24/15
ball.h
Class to hold a ball and its movement across a screen to get started with the SDL2 and
SDL2_image libraries */

#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Ball{
  public:
    Ball();		// Default constructor
    ~Ball();		// Deconstructor
    void loadImage(std::string, SDL_Surface*); // Load the image for the ball
  private:
    SDL_Surface* image;	// Image of ball
};

#endif
