#include "Hero.h"

Hero::Hero(){
  attack = 10;
  defence = 7;
  attack_range = 1;
  mobility = 6;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
}

Hero::Hero(string path, int x, int y, SDL_Renderer* renderer):Character(path,x,y,renderer){
  attack = 10;
  defence = 7;
  attack_range = 1;
  mobility = 6;
  terrain_effect.push_back(0);
  terrain_effect.push_back(1);
  terrain_effect.push_back(1);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
  terrain_effect.push_back(2);
  terrain_effect.push_back(0);
}

void Hero::check_valid_move(Map &current_map, int x, int y, int movement_remaining,vector<vector<int>>* valid_map){
  if(movement_remaining <= 0) return;
  if(x < 0 || x > current_map.get_width()) return;
  if(y < 0 || y > current_map.get_height()) return;
  if(terrain_effect(current_map.get_tile_info(x,y))==0) return;
  *valid_map[x][y] = 1;
  check_valid_move(current_map,x,y-1,movement_remaining-current_map.get_tile_info(x,y-1),valid_map);
  check_valid_move(current_map,x+1,y,movement_remaining-current_map.get_tile_info(x+1,y),valid_map);
  check_valid_move(current_map,x,y+1,movement_remaining-current_map.get_tile_info(x,y+1),valid_map);
  check_valid_move(current_map,x-1,y,movement_remaining-current_map.get_tile_info(x-1,y),valid_map);
}
