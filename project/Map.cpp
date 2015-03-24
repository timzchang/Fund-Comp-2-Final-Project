// implementation of Map class


#include "Map.h"
#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
Map::Map(){
  map_image = NULL;
}

Map::~Map(){
  free();
}

void Map::free(){
  SDL_DestroyTexture(map_image);
  map_image = NULL;
}

void Map::loadImage(std::string image_path, SDL_Renderer* renderer){
  free();
  SDL_Surface* loadedSurface = IMG_Load(image_path.c_str());
  map_image = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  if(map_image == NULL){
    std::cout << "Texture not created: " << SDL_GetError() << std::endl;
  }else{
    image_width = loadedSurface->w;
    image_height = loadedSurface->h;
  }
  SDL_FreeSurface(loadedSurface);
  int w;
  int h;
  SDL_QueryTexture(map_image,NULL,NULL,&w,&h);
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

void Map::render_map(SDL_Renderer* renderer){
  //rektangles?
  SDL_RenderCopy(renderer,map_image,NULL,NULL);
}

int Map::get_tile_info(int x, int y){
  if(x>image_width/16 || x<0 || y<0 || y>image_height/16){
    std::cout << "Out of bounds in function get_tile_info." << std::endl;
    return -1;
  }else{
    return tile_properties[x][y];
  }
}
