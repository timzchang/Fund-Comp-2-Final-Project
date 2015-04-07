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

void Character::draw(SDL_Renderer* renderer){
  SDL_Rect destRect = {xpos*32, ypos*32, 32, 32};
  SDL_Rect clipRect = {state*32, direction*32, 32, 32};
  SDL_RenderCopy(renderer, character_texture, &clipRect, &destRect);
}

void Character::move(int move_direction){
  switch(move_direction){
    case 0:
      ypos-=1;
      break;
    case 1:
      xpos+=1;
      break;
    case 2:
      ypos+=1;
      break;
    case 3:
      xpos-=1;
      break;
  }
}

void Character::change_direction(int face_direction){
  switch(face_direction){
    case 0:
      direction=3;
      break;
    case 1:
      direction=2;
      break;
    case 2:
      direction=0;
      break;
    case 3:
      direction=1;
      break;
  }
}

void Character::set_phase(int new_phase){
	phase=new_phase;
}

int Character::get_phase(){
	return phase;
}
