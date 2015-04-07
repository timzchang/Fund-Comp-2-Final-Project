// CSE20212 Final Project		March 25, 2015
// Map.h				

// Map class interface. This class will be used to hold information about the current map's texture and
// the tile properties of that map. Images and tile information are loaded from external files. 
// Implementation can be found in the Map.cpp file.

#ifndef MAP_H
#define MAP_H

#include <string>		// needed for paths
#include <vector>		
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Map{
  public:
    Map();				// constructor
    ~Map();				// deconstructor
    void loadImage(std::string,SDL_Renderer*);	// loads SDL_Texture with path, and SDL_Renderer passed into it
    void loadVector(std::string);	// loads info about the map (text file with intergers to fill tile_properties
    void render_map(SDL_Renderer*);	// renders the map onto the passed in renderer
    void free();			// deallocates the memory (used in deconstructor)
    int get_tile_info(int,int);		// returns the property (int) of the tile at position x,y
    int get_width();			// returns the number of tiles the width of the map is
    int get_height();			// returns the number of tiles the height of the map is
  private:
    SDL_Texture* map_image;		// image texture
    std::vector<std::vector <int> > tile_properties;	// vector for properties of tiles, each int means something different
    int image_width;					// width of texture in pixels
    int image_height;					// height of texture in pixels
};

#endif
