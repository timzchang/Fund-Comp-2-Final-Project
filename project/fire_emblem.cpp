/*Christopher Syers, Tim Chang, Lucas Unruh, Mason Prosser
  Fund Comp II Project: Fire Emblem
  fire_emblem.cpp

  The driver program for the game. All functionality will be implemented here.
 */

#include "Map.h"
#include "Character.h"
#include "Hero.h"
#include "Archer.h"
#include "Angel.h"
#include "Mage.h"
#include "Pirate.h"
#include "Soldier.h"
#include "Sorcerer.h"
#include "Cursor.h"
#include "GamePiece.h"
#include "Valid_board.h"
#include "Choice_Menu.h"
#include <iostream>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <vector>
//#include <SDL2/SDL_ttf.h>
#include "Stats_Menu.h"
SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;

int main(){
  Map level1;
  int player_turn = 1;
  //initialize SDL
  SDL_Init(SDL_INIT_VIDEO);

  //Create window
  window = SDL_CreateWindow("Fire Emblem",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,480,480,SDL_WINDOW_SHOWN);

  //initialize/create Renderer
  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(!renderer){
    std::cout<<"INVALID RENDER CREATION"<< std::endl;
    return 1;
  }
  SDL_SetRenderDrawColor(renderer,255,255,255,255);

  //initializing SDL_Image
  int imgFlags = IMG_INIT_PNG;
  if(!(IMG_Init(imgFlags) & imgFlags)){
    std::cout << "SDL_image couldn't initialize!\n";
    return 1;
  }

// Menu loop (with "instructions" loop inside) will go here most likely (and exit when "play" is chosen - We could add a large while loop if we want the game to return to the menu after it finishes
/* menu() menu
 selection=menu
 while(selection!=play)
    if (menu)
            selection=menu.display()
    if (instruction)
            selection=instruction()
    else if quit
            return
*/

  //initialize SDL_ttf
  if( TTF_Init() == -1){
    cout << "SDL TTF couln't initialize!\n";
  }
  Stats_Menu stat_menu("../media/blue_stats.png","../media/red_stats.png","../media/sans.ttf",renderer);
  //load map image
  level1.loadImage("../maps/small_map.png",renderer);

  // LOAD PLAYER TURN NOTIFICATIONS
  SDL_Surface* loadedImage = IMG_Load("../media/player1turn.png");
  SDL_Texture* player1turn = SDL_CreateTextureFromSurface(renderer,loadedImage);
  loadedImage = IMG_Load("../media/player2turn.png");
  SDL_Texture* player2turn = SDL_CreateTextureFromSurface(renderer,loadedImage);
  SDL_FreeSurface(loadedImage);
  loadedImage = NULL;
  SDL_Rect turnDestRect = {80,100,300,100};
  // LOAD WINNER MESSAGES
  loadedImage = IMG_Load("../media/PlayerOneWins.png");
  SDL_Texture* player1win = SDL_CreateTextureFromSurface(renderer,loadedImage);
  loadedImage = IMG_Load("../media/PlayerTwoWins.png");
  SDL_Texture* player2win = SDL_CreateTextureFromSurface(renderer,loadedImage);
  SDL_FreeSurface(loadedImage);
  loadedImage = NULL;
  //load map info
  level1.loadVector("../maps/small_map_info.txt");
  Choice_Menu choices(renderer,"../media/choice_menu_attack.png","../media/choice_menu_wait.png");

  vector<Character*> players; //vector of characters
  //GamePiece *cursor_ptr = NULL; //initialize the cursor
  Cursor cursor_ptr("../media/Cursor1.png","../media/Cursor2.png",renderer,0,0); //cursor_ptr changed to object of GamePiece from ptr. Necessary for check_select()
  //init Characters
  players.push_back(new Hero("../media/Hero.png","Chris",0,0,1,renderer,level1.get_tile_prop()));
  players.push_back(new Archer("../media/Archer.png","Billy",2,0,1,renderer,level1.get_tile_prop()));
//  players.push_back(new Mage("../media/Mage.png","Messi",0,2,1,renderer,level1.get_tile_prop()));
//  players.push_back(new Soldier("../media/Soldier.png","Ronaldo",1,1,1,renderer,level1.get_tile_prop()));
  players.push_back(new Hero("../media/Hero2.png","Lucas",14,14,2,renderer,level1.get_tile_prop()));
//  players.push_back(new Sorcerer("../media/Sorcerer2.png","Mason",12,14,2,renderer,level1.get_tile_prop()));
  players.push_back(new Angel("../media/Angel2.png","Tim",14,12,2,renderer,level1.get_tile_prop()));
//  players.push_back(new Pirate("../media/Pirate2.png","Bob",13,13,2,renderer,level1.get_tile_prop()));
  bool quit = false;
  SDL_Event e;

    //Key:
    //0 = up
    //1 = right
    //2 = down
    //3 = left
  while(!quit){
    while(SDL_PollEvent(&e) != 0){
      if(e.type==SDL_QUIT){
        quit = true;
      }else if(e.type==SDL_KEYDOWN){
        switch(e.key.keysym.sym){
        case SDLK_a:
          players[1]->setCurrentHitpoints(players[1]->getCurrentHitpoints()-5);
          break;
        case SDLK_s:
//          players[2]->select();
//          players[2]->check_valid_move(players[2]->getx(),players[2]->gety(),players[2]->getMobility(), &players);
          break;
        case SDLK_u:
//          players[2]->unselect();
          break;
        case SDLK_DOWN:
          //cursor_ptr.test_move(2,level1.get_width(),level1.get_height());  //TEST FUNCTION PLEASE IGNORE.
          cursor_ptr.move_select(&players,2,&level1); //if any players are selected, modify move vector
          //cursor_ptr.move(2,level1.get_width(),level1.get_height());
          break;
        case SDLK_UP:
          cursor_ptr.move_select(&players,0,&level1);
          //cursor_ptr.test_move(0,level1.get_width(),level1.get_height());  //TEST FUNCTION PLEASE IGNORE.
          //cursor_ptr.move(0,level1.get_width(),level1.get_height());
          break;
        case SDLK_LEFT:
          cursor_ptr.move_select(&players,3,&level1);
          //cursor_ptr.test_move(3,level1.get_width(),level1.get_height());  //TEST FUNCTION PLEASE IGNORE.
          //cursor_ptr.move(3,level1.get_width(),level1.get_height());
          break;
        case SDLK_RIGHT:
          cursor_ptr.move_select(&players,1,&level1);
          //cursor_ptr.test_move(1,level1.get_width(),level1.get_height());  //TEST FUNCTION PLEASE IGNORE.
          //cursor_ptr.move(1,level1.get_width(),level1.get_height());
          break;
        case SDLK_RETURN:
	  //do select stuff
          cursor_ptr.toggle_select(&players,&level1); //managed to encompass everything in one function. Selects or deselects players. moves players. Will need to modify when we implement a popup menu.
	  break;
        }
      }
    }
    cursor_ptr.update();
    //clear
    SDL_RenderClear(renderer);
    //draw stuff
    level1.render_map(renderer);

// LOOPS THROUGHT PLAYERS AND DRAWS THEIR STATS MENU IF ONE IS HOVERED OVER. ALSO DRAWS AND UPDATES EACH CHARACTER
    int moves_left = 0;
    for(int i = 0; i < players.size(); i++){
      players[i]->update();
      players[i]->draw(renderer);
      if(players[i]->getPlayer() == player_turn){
        moves_left += players[i]->getMove();
      }
    }
// DRAWS CURSOR
    cursor_ptr.draw(renderer);

// PROCESS MOVES
    if(moves_left == 0){
      if(player_turn == 1){
        player_turn = 2;
        SDL_RenderCopy(renderer,player2turn,NULL,&turnDestRect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
      }else if(player_turn == 2){
        player_turn = 1;
        SDL_RenderCopy(renderer,player1turn,NULL,&turnDestRect);
        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
      }
      for(int i = 0; i < players.size(); i++){
        players[i]->setMove();
      }
    }
// END PROCESS MOVES

// DELETES CHARACTERS WHO HAVE DIED
    for(int i = 0; i < players.size(); i++){
      if(players[i]->isAlive() == 0){
        players.erase(players.begin()+i);
        i--;
      }
    }
// ENDS DELETING CHARACTER WHO HAVE DIED
    for(int i = 0; i < players.size(); i++){
      if(players[i]->getx() == cursor_ptr.getx() && players[i]->gety() == cursor_ptr.gety()){
        stat_menu.draw(renderer,players[i]->gety(),level1.get_height(),players[i]->getPlayer(),players[i]->getName(),players[i]->getCurrentHitpoints(),players[i]->getMaxHitpoints(),players[i]->getAttack(),players[i]->getDefence());
      }
    }
    int player1_alive = 0;
    int player2_alive = 0;
    for(int i = 0; i < players.size(); i++){
      if(players[i]->getPlayer() == 1){
        player1_alive++;
      }else{
        player2_alive++;
      }
    } 
    if(player1_alive == 0){
      SDL_RenderCopy(renderer,player2win,NULL,&turnDestRect);
      SDL_RenderPresent(renderer);
      SDL_Delay(5000);
      quit = true;
    }
    if(player2_alive == 0){
      SDL_RenderCopy(renderer,player1win,NULL,&turnDestRect);
      SDL_RenderPresent(renderer);
      SDL_Delay(5000);
      quit = true;
    }
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  window = NULL;
  renderer = NULL;

//  IMG_Quit();
//  SDL_Quit();
//  TTF_Quit();
  return 0;
}
