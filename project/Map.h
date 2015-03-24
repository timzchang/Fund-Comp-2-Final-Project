// Map class interface

#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Map{
  public:
    Map();				// constructor
    ~Map();				// de
    void loadImage(std::string,SDL_Renderer*);	// loads SDL_Texture with path
    void loadVector(std::string);	// loads info about the map
    void render_map(SDL_Renderer*);
    void free();
  private:
    SDL_Texture* map_image;		// image
    std::vector<std::vector <int> > tile_properties;		// vector for properties of tiles
    int image_width;
    int image_height;
 //   SDL_Surface* screen_surface; Possibly need this
};

#endif
