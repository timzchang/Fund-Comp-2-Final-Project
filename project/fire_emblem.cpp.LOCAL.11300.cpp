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
#include <iostream>
//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <vector>
//#include <SDL2/SDL_ttf.h>
//const int SCREEN_WIDTH = 240;
//const int SCREEN_HEIGHT = 240;

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;

int main(){
  Map level1;

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

  //load map image
  level1.loadImage("../maps/small_map.png",renderer);

  //load map info
  level1.loadVector("../maps/small_map_info.txt");

  /* Just for now, student machines don't have ttf
  //initialize SDL_ttf
  if( TTF_Init() == -1){
    cout << "SDL TTF couln't initialize!\n";
  }
  TTF_Font* Sans = TTF_OpenFont("../media/sans.ttf",48);
  SDL_Color White = {255,255,255,0};
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans,"Test for text",White);
  SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer,surfaceMessage);
  SDL_Rect Message_rect = {100,100,100,25};
  SDL_Surface* stat_box = IMG_Load("../media/stat_box.png");
  if(stat_box == NULL) cout << "hello" << endl;
  SDL_Texture* stat_tex = SDL_CreateTextureFromSurface(renderer,stat_box);
 // SDL_Rect destRect_stat = {0,0,192,96};
  SDL_Rect source_rect = {288,384,196,92};
  SDL_FreeSurface(stat_box);
  SDL_FreeSurface(surfaceMessage);
  */

  vector<Character*> players; //vector of characters
  //GamePiece *cursor_ptr = NULL; //initialize the cursor
  Cursor cursor_ptr("../media/Cursor1.png","../media/Cursor2.png",renderer,0,0); //cursor_ptr changed to object of GamePiece from ptr. Necessary for check_select()
  //init heroes
  players.push_back(new Hero("../media/Hero.png",0,0,renderer,level1.get_tile_prop()));
  players.push_back(new Hero("../media/Hero.png",2,8,renderer,level1.get_tile_prop()));
  players.push_back(new Hero("../media/Hero.png",8,12,renderer,level1.get_tile_prop()));
  players.push_back(new Angel("../media/Angel2.png",10,5,renderer,level1.get_tile_prop())); //added stuff
  //cursor_ptr = new Cursor("../media/Cursor1.png","../media/Cursor2.png",renderer,0,0);
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
          players[0]->setHitpoints(players[0]->getHitpoints()-5);
          break;
        case SDLK_s:
          players[2]->select();
          players[2]->check_valid_move(players[2]->getx(),players[2]->gety(),players[2]->getMobility());
          break;
        case SDLK_u:
          players[2]->unselect();
          break;
        case SDLK_DOWN:
          cursor_ptr.move_select(&players,2);
          cursor_ptr.move(2,level1.get_width(),level1.get_height());
          break;
        case SDLK_UP:
          cursor_ptr.move_select(&players,0);
          cursor_ptr.move(0,level1.get_width(),level1.get_height());
          break;
        case SDLK_LEFT:
          cursor_ptr.move_select(&players,3);
          cursor_ptr.move(3,level1.get_width(),level1.get_height());
          break;
        case SDLK_RIGHT:
          cursor_ptr.move_select(&players,1);
          cursor_ptr.move(1,level1.get_width(),level1.get_height());
          break;
        case SDLK_RETURN:
	  //do select stuff
	  cursor_ptr.toggle_select(&players,&level1); //managed to encompass everything in one function. Selects or deselects players. moves players. Will need to modify when we implement a popup menu.
	  break;
        }
      }
    }
    //update players/cursor
    players[0]->update();
    players[1]->update();
    players[2]->update();
    players[3]->update(); //added Angel
    cursor_ptr.update();
    //clear
    SDL_RenderClear(renderer);
    //draw stuff
    level1.render_map(renderer);
    players[0]->draw(renderer);   
    players[1]->draw(renderer);   
    players[2]->draw(renderer);
    players[3]->draw(renderer); //added Angel
    cursor_ptr.draw(renderer);
    //SDL_RenderCopy(renderer,Message,NULL,&Message_rect);
    //SDL_RenderCopy(renderer,stat_tex,/*&destRect_stat*/NULL,&source_rect); //Just for now, student machines don't have ttf
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  window = NULL;
  renderer = NULL;

  IMG_Quit();
  SDL_Quit();

  return 0;
}