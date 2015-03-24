// implementation of Map class


#include "Map.h"
#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
Map::Map(){
  map_image = NULL;
  renderer = NULL;
  std::cout << "Hello\n";
}

Map::Map(SDL_Renderer* new_renderer){
  renderer = new_renderer;
  map_image = NULL;
}

Map::~Map(){
  SDL_DestroyTexture(map_image);
  map_image = NULL;
  SDL_DestroyRenderer(renderer);
  renderer = NULL;
  std::cout << "Bye\n";
}

void Map::loadImage(std::string image_path){
  SDL_Texture* loadedTexture = NULL;
  SDL_Surface* loadedSurface = IMG_Load(image_path.c_str());
  // optimize?
  loadedTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  if(loadedTexture == NULL){
    std::cout << "Texture not created: " << SDL_GetError() << std::endl;
  }else{
    image_width = loadedSurface->w;
    image_height = loadedSurface->h;
  }
  SDL_FreeSurface(loadedSurface);
  map_image = loadedTexture;
  SDL_DestroyTexture(loadedTexture);
}

void Map::loadVector(std::string level_txt_path){
  int num_tiles_w;
  int num_tiles_h;
  num_tiles_w = image_width/16;
  num_tiles_h = image_height/16;

  int tempVar;
  std::vector<int> tempVec;

  std::ifstream infile;
  infile.open(level_txt_path.c_str());

  while(!infile.eof()){

    for(int i = 0; i < num_tiles_w; i++){
      infile >> tempVar;
      tempVec.push_back(tempVar);
    }

    tile_properties.push_back(tempVec);
    tempVec.clear();
  }
}

void Map::render_map(){
  //rektangles?
  SDL_RenderCopy(renderer,map_image,NULL,NULL);
}

void Map::setRenderer(SDL_Renderer* new_renderer)
{
  renderer = new_renderer;
}
