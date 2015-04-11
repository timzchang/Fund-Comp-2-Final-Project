// Tester for Map class



#include "Map.h"
#include "Character.h"
#include "Hero.h"
#include "Cursor.h"
#include "GamePiece.h"
#include "Valid_board.h"
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
//const int SCREEN_WIDTH = 240;
//const int SCREEN_HEIGHT = 240;

SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;

int main(){
/*  Valid_board test(10,10);
  test.print();
cout << endl;
  test.resize(10,15);
  test.print();
cout << endl;
  test.resize(15,10);
  test.print();
  test.set_tile(0,0);
  test.set_tile(5,5);
  test.set_tile(-1,-1);
  test.set_tile(15,10);
cout << endl;
  test.print();
  test.to_zeros();
cout << endl;
  test.print();*/
  int counter = 0;
  Map level1;
  SDL_Init(SDL_INIT_VIDEO);
//  window = SDL_CreateWindow("Maps",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,level1.getWidth(),level1.getHeight());
  window = SDL_CreateWindow("Fire Emblem",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,480,480,SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if(!renderer){
    std::cout<<"INVALID RENDER CREATION" << std::endl;
  }
  SDL_SetRenderDrawColor(renderer,255,255,255,255);
  int imgFlags = IMG_INIT_PNG;
  if(!(IMG_Init(imgFlags) & imgFlags)){
    std::cout << "SDL_image couldn't initialize!\n";
  }

  level1.loadImage("../maps/small_map.png",renderer);
  level1.loadVector("../maps/small_map_info.txt");
  Valid_board vb(level1.get_width(),level1.get_height());
  vb.print();
  vector<Character*> players;
  GamePiece *cursor_ptr = NULL;
  players.push_back(new Hero("../media/Hero.png",0,0,renderer));
  players.push_back(new Hero("../media/Hero.png",1,0,renderer));
  players.push_back(new Hero("../media/Hero.png",2,0,renderer));
  cursor_ptr = new Cursor("../media/Cursor1.png","../media/Cursor2.png",renderer,0,0);
  cout << players[1]->getx() << endl;
  cout << players[1]->gety() << endl;
  players[1]->check_valid_move(&level1,players[1]->getx(),players[1]->gety(),players[1]->getMobility(),&vb);
  vb.print();
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
	  case SDLK_DOWN:
	    cursor_ptr->move(2,level1.get_width(),level1.get_height());
	    break;
          case SDLK_UP:
	    cursor_ptr->move(0,level1.get_width(),level1.get_height());
	    break;
	  case SDLK_LEFT:
	    cursor_ptr->move(3,level1.get_width(),level1.get_height());
	    break;
	  case SDLK_RIGHT:
	    cursor_ptr->move(1,level1.get_width(),level1.get_height());
	    break;
        }
      }
    }
    players[0]->update();
    players[1]->update();
    players[2]->update();
    cursor_ptr->update();
    SDL_RenderClear(renderer);
    level1.render_map(renderer);
    players[0]->draw(renderer);   
    players[1]->draw(renderer);   
    players[2]->draw(renderer);   
    cursor_ptr->draw(renderer);
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
