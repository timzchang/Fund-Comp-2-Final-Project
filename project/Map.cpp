// CSE20212 Final Project		March 25, 2015
// Map.cpp				

// Implementation of the Map class. Includes definitions of constructors,
// deconstructors, and member function.


#include "Map.h"
#include <iostream>
#include <fstream>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
using namespace std;
// default constructor 
Map::Map(){
  map_image = NULL;		// sets SDL_Texture to NULL to avoid random pointer
}

// deconstructor
Map::~Map(){
  free();			// function that destroys the texture and sets it to NULL
}

void Map::free(){
  if(map_image!=NULL){
    SDL_DestroyTexture(map_image);	// destroy the texture
  }
  map_image = NULL;			// grounds the pointer
}

// function that takes in a path to a PNG image and the renderer that the image will be renderer to
void Map::loadImage(std::string image_path, SDL_Renderer* renderer){
  free();							// deletes the existing texture
  SDL_Surface* loadedSurface = IMG_Load(image_path.c_str());	// loads the image to a surface
  map_image = SDL_CreateTextureFromSurface(renderer, loadedSurface);		// creates the texture from the surface
  if(map_image == NULL){							// error check - checks to make sure a texture was created
    std::cout << "Texture not created: " << SDL_GetError() << std::endl;
  }
  SDL_FreeSurface(loadedSurface);						// frees the surface
  SDL_QueryTexture(map_image,NULL,NULL,&image_height,&image_width);		// Query texture to store data members image_height and width
}

// function that loads the preset map tile info into the data member tile_properties
void Map::loadVector(std::string level_txt_path){
  int num_tiles_w = image_width/16;				// the number of tiles wide the map is
  int num_tiles_h = image_height/16;				// the number of tiles high the map is
  int tempVar;							// variable to hold read in ints from txt file
  std::vector<int> tempVec;					// temp vector to push back into the second dimension

  std::ifstream infile;					
  infile.open(level_txt_path.c_str());				// open the file that contains the formatted information

  for(int i = 0; i < num_tiles_h; i++){	
    for(int i = 0; i < num_tiles_w; i++){			// for each row
      infile >> tempVar;					// read an int
      tempVec.push_back(tempVar);				// push that int onto a vector
    }

    tile_properties.push_back(tempVec);				// push the vector onto the data member tile_properties
    tempVec.clear();						// clear the temporary vector
  }
}

// function that draws the map onto the passed in renderer
void Map::render_map(SDL_Renderer* renderer){
  //rektangles?
  SDL_RenderCopy(renderer,map_image,NULL,NULL);			// draws the map_image to the screen. Fits whole screen
}

// function that returns the property of the tile. For now:
/*
1 = plain
2 = trees
3 = hills
4 = water
5 = roots
6 = mountain/cliff
*/
int Map::get_tile_info(int x, int y){
  if(x>get_width() || x<0 || y<0 || y>get_height()){			// checks for invalid coordinate
    std::cout << "x=" << x << " y=" << y << " width=" << get_width() << " height=" << get_height() << std::endl;
    std::cout << "Out of bounds in function get_tile_info." << std::endl;	// error message
    return -1;									// error return
  }else{
    return tile_properties[x][y];						// gets the property from the 2d vector
  }
}
// function that returns the number of tiles the map is wide
int Map::get_width(){
  return image_width/16;			// maps are all divided into 16 pixel tiles
}

// function that returns the number of tiles the map is high
int Map::get_height(){
  return image_height/16;			// maps are divided into 16 pixel tiles
}

// returns copy of the 2d int vector tile_properties
std::vector<std::vector <int> > Map::get_tile_prop(){
  std::vector<std::vector <int> > to_return;
  to_return = tile_properties;
  return to_return;
}

// function to print the 2d vector of ints of the map
void Map::print(){
/*  for(int i = 0; i < tile_properties.size(); i++){
    for(int j = 0; j < tile_properties[0].size(); j++){
      cout << tile_properties[i][j] << " ";
    }
cout <<endl;
  }
*/
 cout << tile_properties.size() << endl;
 cout << tile_properties[0].size() << endl;
}
