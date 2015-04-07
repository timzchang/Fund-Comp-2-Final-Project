#include "Character.h"

Character::Character():Game_Piece(){
  direction = 0;
  phase = 0;
  character_texture = NULL;
}

Character::Character(string path,int x, int y, SDL_Renderer* renderer):Game_Piece(x,y){
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());
  character_texture = SDL_CreateTextureFromSurface(renderer,loadedSurface);
  direction = 0;
  phase = 0;
  SDL_FreeSurface(loadedSurface);
  loadedSurface = NULL;
}

Character::~Character(){
  if(character_texture!=NULL){
    SDL_DestroyTexture(character_texture);
    character_texture = NULL;
  }
  direction = 0;
  phase = 0;
}
