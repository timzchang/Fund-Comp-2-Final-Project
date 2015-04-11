// Christopher Syers, Tim Chang, Lucas Unruh, Mason Prosser
// April 10, 2015		Fund Comp II Project: Fire Emblem
// Valid_board.cpp

// Implementation of the Valid_board class.

#include "Valid_board.h"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
// default constructor with fallback values
Valid_board::Valid_board(int width, int height){
  vector<int> temp;
// creates a 2d array of size (widthxheight) filled with 0s
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      temp.push_back(0);
    }
    valid_tiles.push_back(temp);
    temp.clear();
  }
  blue_highlight = NULL;
}

// constructor that will actually be used
Valid_board::Valid_board(int width, int height, string path, SDL_Renderer* renderer){
  vector<int> temp;
// creates a 2d array of size (widthxheight) filled with 0s
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      temp.push_back(0);
    }
    valid_tiles.push_back(temp);
    temp.clear();
  }
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());
  blue_highlight = SDL_CreateTextureFromSurface(renderer,loadedSurface);
  SDL_FreeSurface(loadedSurface);
  loadedSurface = NULL;
}

// deconstructor
Valid_board::~Valid_board(){
  SDL_DestroyTexture(blue_highlight);
  blue_highlight = NULL;
}
// function to set all elements of the 2d array to 0s
void Valid_board::to_zeros(){
  for(int i = 0; i < valid_tiles.size(); i++){
    for(int j = 0; j < valid_tiles[0].size(); j++){
      valid_tiles[i][j] = 0;
    }
  }
}

// resizes valid_tiles and sets all elements to 0
void Valid_board::resize(int width, int height){
  valid_tiles.clear();
  vector<int> temp;
// creates a 2d array of size (widthxheight) filled with 0s
  for(int i = 0; i < height; i++){
    for(int j = 0; j < width; j++){
      temp.push_back(0);
    }
    valid_tiles.push_back(temp);
    temp.clear();
  }
}

// function that prints. For testing purposes
void Valid_board::print(){
  for(int i = 0; i < valid_tiles.size(); i++){
    for(int j = 0; j < valid_tiles[0].size(); j++){
      cout << valid_tiles[i][j];
    }
    cout << endl;
  }
}

// sets tile (int x, int y) to 1
void Valid_board::set_tile(int x, int y){
  if(x<0||y<0||x>=valid_tiles[0].size()||y>=valid_tiles.size()) return;
  valid_tiles[x][y] = 1;
}

// returns the number of rows
int Valid_board::get_num_rows(){
  return valid_tiles.size();
}

// returns the number of column
int Valid_board::get_num_cols(){
  return valid_tiles[0].size();
}

// function to draw blue highlights where the character can move.
void Valid_board::draw(SDL_Renderer* renderer){
  for(int i = 0; i < valid_tiles.size(); i++){
    for(int j = 0; j < valid_tiles[0].size(); j++){
      if(valid_tiles[i][j]==1){
        SDL_Rect destRect = {j*32,i*32,32,32};
        SDL_RenderCopy(renderer,blue_highlight,NULL,&destRect);
      }
    }
  }
}
