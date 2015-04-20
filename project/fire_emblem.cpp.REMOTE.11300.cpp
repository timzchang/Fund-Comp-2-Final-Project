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
  Cursor cursor_ptr("../media/Cursor1.png","../media/Cursor2.png",renderer,0,0); //cursor_ptr changed to object from GamePiece ptr. Necessary for check_select()
  vector<int> moves; //vector of moves
  moves.push_back(0);
  moves.push_back(0);
  moves.push_back(0);
  moves.push_back(0);
  moves.push_back(0);
  //init hero
  players.push_back(new Hero("../media/Hero.png","Chris",0,0,renderer,level1.get_tile_prop()));
  players.push_back(new Hero("../media/Hero.png","Mason",2,8,renderer,level1.get_tile_prop()));
  players.push_back(new Hero("../media/Hero.png","Lucas",8,12,renderer,level1.get_tile_prop()));
  players.push_back(new Angel("../media/Angel2.png","Tim",10,5,renderer,level1.get_tile_prop())); //added stuff
  //cursor_ptr = new Cursor("../media/Cursor1.png","../media/Cursor2.png",renderer,0,0);
  bool quit = false;
  SDL_Event e;

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
	  players[1]->process_move_vector(moves,level1.get_width(),level1.get_height()); //for some reason this makes the character jump upwards to their max movement. SOLVED. We have a moves vector instantiated up top with 4 up moves.
	  break;
	case SDLK_DOWN:
	  cursor_ptr.move(2,level1.get_width(),level1.get_height());
	  players[1]->move(2,level1.get_width(),level1.get_height());
	  break;
	case SDLK_UP:
	  cursor_ptr.move(0,level1.get_width(),level1.get_height());
	  players[1]->move(0,level1.get_width(),level1.get_height());
	  break;
        case SDLK_LEFT:
	  cursor_ptr.move(3,level1.get_width(),level1.get_height());
	  players[1]->move(3,level1.get_width(),level1.get_height());
	  break;
        case SDLK_RIGHT:
	  cursor_ptr.move(1,level1.get_width(),level1.get_height());
	  players[1]->move(1,level1.get_width(),level1.get_height());
	  break;
        case SDLK_RETURN:
	  //do select stuff
	  cursor_ptr.check_select(&players,&level1,moves); //managed to encompass everything in one function. This could come in handy.
	  break;
        }
      }
    }
    players[0]->update();
    players[1]->update();
    players[2]->update();
    players[3]->update(); //added Angel
    cursor_ptr.update();
    SDL_RenderClear(renderer);
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
