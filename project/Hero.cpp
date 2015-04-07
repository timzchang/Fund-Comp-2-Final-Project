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
  if(terrain_effect(current_map.get_tile_info(x,y-1))==0) return;  //what if we have something like:
  if(terrain_effect(current_map.get_tile_info(x+1,y))==0) return;  //|  xx| The x's are invalid locations. I want to check the farthest up I can go. 
  if(terrain_effect(current_map.get_tile_info(x,y+1))==0) return;  //| xxx| Clearly if my mobility is sufficient I can go to the top of the screen
  if(terrain_effect(current_map.get_tile_info(x-1,y))==0) return;  //|o xx| but once I hit the second layer of x's, won't the function kick out due to 2nd check?
  *valid_map[x][y] = 1;                                            //       since the valid map is updated after the return checks, why not just have
  check_valid_move(current_map,x,y-1,movement_remaining-current_map.get_tile_info(x,y-1),valid_map); // one if(terrain_effect()) check on the current tile?
  check_valid_move(current_map,x+1,y,movement_remaining-current_map.get_tile_info(x+1,y),valid_map);
  check_valid_move(current_map,x,y+1,movement_remaining-current_map.get_tile_info(x,y+1),valid_map);
  check_valid_move(current_map,x-1,y,movement_remaining-current_map.get_tile_info(x-1,y),valid_map);
}
