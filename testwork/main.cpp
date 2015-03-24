#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

SDL_Texture* LoadTexture(std::string path, SDL_Renderer* renderer){

  SDL_Texture *texture = NULL;
  SDL_Surface* surface = IMG_Load(path.c_str());
  texture = SDL_CreateTextureFromSurface(renderer,surface);
  SDL_FreeSurface(surface);
  return texture;

}

class Sprite{
  public:
    Sprite();
    ~Sprite();
    void render(SDL_Renderer*);
    bool load(std::string, SDL_Renderer*);
    void free();
    int getHeight();
    int getWidth();
    void moveRight();
    void moveUp();
    void moveLeft();
    void moveDown();
  private:
    SDL_Texture* sprite_texture;
    int tot_height;
    int tot_width;
    int clip_height;
    int clip_width;
  public:
    int state;			// 0 for first clip, 1 for second, 2 for third
  private:
    int direction;		// 0 for down, 1 for left, 2 for right, and 3 for up
    int xpos;
    int ypos;
}; 

void Sprite::moveRight(){
  direction = 2;
  xpos += 32;
  if(xpos >= 640) xpos -= 32;
}
void Sprite::moveUp(){
  direction = 3;
  ypos -= 32;
  if(ypos < 0) ypos = 0;
}

void Sprite::moveLeft(){
  direction = 1;
  xpos -= 32;
  if(xpos < 0) xpos = 0;
}
void Sprite::moveDown(){
  direction = 0;
  ypos += 32;
  if(ypos >= 480) ypos -= 32;
}


Sprite::Sprite(){
  sprite_texture = NULL;
  tot_height = 0;
  tot_width = 0;
  clip_height = 0;
  clip_width = 0;
  state = -1;
  direction = -1;
  xpos = 0;
  ypos = 0;
}

Sprite::~Sprite(){
  free();
}

void Sprite::free(){
  if(sprite_texture != NULL){
    SDL_DestroyTexture(sprite_texture);
    sprite_texture = NULL;
    tot_height = 0;
    tot_width = 0;
    clip_height = 0;
    clip_width = 0;
    state = -1;
    direction = -1;
    xpos = 0;
    ypos = 0;
  }
  
}

bool Sprite::load(std::string path, SDL_Renderer* renderer){
  free();
  SDL_Surface* loadedSurface = IMG_Load(path.c_str());
  sprite_texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
  tot_height = loadedSurface->h;
  tot_width = loadedSurface->w;
  SDL_FreeSurface(loadedSurface);
  clip_height = tot_height / 4;			// hard coded
  clip_width = tot_width / 3;			// hard coded 
  state = 0;
  direction = 0;
  xpos = 0;
  ypos = 0;
  return true;
}

void Sprite::render(SDL_Renderer* renderer){
  SDL_Rect renderRect = {xpos,ypos,32,32};
  SDL_Rect clipRect = {state*clip_width,direction*clip_height,clip_width,clip_height};
  SDL_RenderCopy(renderer,sprite_texture,&clipRect,&renderRect);
}

int Sprite::getWidth(){
  return tot_width;
}

int Sprite::getHeight(){
  return tot_height;
}

int main(){
  SDL_Event ev;
  bool isRunning = true;
  SDL_Window* window = NULL;
  SDL_Renderer* renderer = NULL;
  SDL_Texture* background = NULL;
  int counter = 0;
  SDL_Init(SDL_INIT_VIDEO);
  int imgFlags = IMG_INIT_PNG;
  if(!(IMG_Init(imgFlags) & imgFlags)){
    std::cout << "Error: " << IMG_GetError() << std::endl;
  }
  window = SDL_CreateWindow("Sprite Class", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  background = LoadTexture("Grass.png",renderer);
  Sprite character;
  Sprite char2;
  character.load("image.png",renderer);
  char2.load("image1.png",renderer);
  while(isRunning){
    while(SDL_PollEvent(&ev)!=0){
      if(ev.type==SDL_QUIT){
        isRunning = false;
      }else if(ev.type==SDL_KEYDOWN){
        switch(ev.key.keysym.sym){
          case SDLK_UP:
	    character.moveUp();
            break;
          case SDLK_DOWN:
	    character.moveDown();
            break;
          case SDLK_LEFT:
	    character.moveLeft();
            break;
          case SDLK_RIGHT:
  	    character.moveRight();
            break;
          case SDLK_a:
	    char2.moveLeft();
            break;
	  case SDLK_s:
	    char2.moveDown();
	    break;
          case SDLK_d:
	    char2.moveRight();
	    break;
          case SDLK_w:
	    char2.moveUp();
	    break;
        }
      }
    }
    counter++;
    if(counter == 15){
      counter = 0;
      character.state++;
      if(character.state >= 3) character.state = 0;
      char2.state++;
      if(char2.state >= 3) char2.state = 0;
    }
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,background,NULL,NULL);
    character.render(renderer);
    char2.render(renderer);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyTexture(background);
  character.free();
  window = NULL;
  renderer = NULL;
  background = NULL;
  SDL_Quit();
  return 0;
}
