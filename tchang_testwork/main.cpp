//
//  main.cpp
//  moving_sprite
//
//  Created by Tim Chang on 3/18/15.
//  Copyright (c) 2015 Tim Chang. All rights reserved.
//

#include <iostream>
#include"LTexture.h"
#include<stdio.h>

#include<SDL2_image/SDL_image.h>
#include<SDL2/SDL.h>
//#include<SDL.h>
//#include<SDL_image.h>
using namespace std;

bool init();
bool loadMedia();
void close();

SDL_Window * gWindow = NULL;
SDL_Renderer * gRenderer = NULL;

//on second thought, we should initialize this in main
//I wish, but because we use loadMedia
LTexture link(240,320);
LTexture background(0,0);
SDL_Rect spriteClips[4];

bool init(){ //init SDL, window, renderer, png loading
    bool success = true;
    
    //init sdl
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //texture filtering
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        {
            printf( "Warning: Linear texture filtering not enabled!" );
        }
        
        //create window
        gWindow = SDL_CreateWindow("Moving Sprite!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //init renderer
            gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if(gRenderer == NULL)
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;

            }
            else
            {
                //initialize render color
                SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                link.setRenderer(gRenderer);
                background.setRenderer(gRenderer);
                
                //init png loading. I still don't really understand what this does.
                int imgFlags = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlags) & imgFlags))
                {
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
                    success = false;
                }
            }
        }
    }
    
    return success;
}

bool loadMedia(){
    bool success = true;
    
    if(!link.loadFromFile("Nilssprite.png"))
    {
        printf("couldn't load link!\n");
        success = false;
    }
    
    if(!background.loadFromFile("background.png"))
    {
        printf("couldn't load background!\n");
        success = false;
    }
    
    //walking down
    spriteClips[0].x = 190;
    spriteClips[0].y = 223;
    spriteClips[0].w = 18;
    spriteClips[0].h = 18;
    
    spriteClips[1].x = 208;
    spriteClips[1].y = 223;
    spriteClips[1].w = 17;
    spriteClips[1].h = 18;
    
    spriteClips[2].x = 225;
    spriteClips[2].y = 223;
    spriteClips[2].w = 18;
    spriteClips[2].h = 18;
    
    
    //walking right / left
    spriteClips[3].x = 191;
    spriteClips[3].y = 241;
    spriteClips[3].w = 18;
    spriteClips[3].h = 18;
    
    spriteClips[4].x = 209;
    spriteClips[4].y = 241;
    spriteClips[4].w = 18;
    spriteClips[4].h = 18;
    
    spriteClips[5].x = 226;
    spriteClips[5].y = 241;
    spriteClips[5].w = 18;
    spriteClips[5].h = 18;
    
    //walking up
    spriteClips[6].x = 190;
    spriteClips[6].y = 259;
    spriteClips[6].w = 17;
    spriteClips[6].h = 18;
    
    spriteClips[7].x = 207;
    spriteClips[7].y = 259;
    spriteClips[7].w = 17;
    spriteClips[7].h = 18;
    
    spriteClips[8].x = 223;
    spriteClips[8].y = 259;
    spriteClips[8].w = 17;
    spriteClips[8].h = 18;
    
    /*
    spriteClips[3].x = 0;
    spriteClips[3].y = 105;
    spriteClips[3].w = 26;
    spriteClips[3].h = 26;
    */

    return success;
}

void close(){
    link.free();
    background.free();
    
    SDL_DestroyWindow(gWindow);
    SDL_DestroyRenderer(gRenderer);
    gWindow = NULL;
    gRenderer = NULL;
    
    IMG_Quit();
    SDL_Quit();
}


int main(int argc, const char * argv[]) {
    
    if(!init())
    {
        printf( "Failed to initialize!\n" );

    }
    else
        if ( !loadMedia())
            printf("Failed to load media\n");
        else
        {
            bool quit = false;
            
            SDL_Event e;
            
            int linkpos=0;
            int frame = 0;
            SDL_RendererFlip fliptype = SDL_FLIP_NONE;
            
            SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            SDL_RenderClear(gRenderer);
            
            while(!quit){
                while (SDL_PollEvent(&e) != 0) {
                    if(e.type == SDL_QUIT)
                        quit = true;
                    else if(e.type == SDL_KEYDOWN)
                    {
                        switch (e.key.keysym.sym)
                        {
                            case SDLK_DOWN:
                            {
                                link.move(0, 10);
                                linkpos = 0;
                                fliptype = SDL_FLIP_NONE;
                            }
                                break;
                            case SDLK_UP:
                            {
                                link.move(0, -10);
                                linkpos = 36;
                                fliptype = SDL_FLIP_NONE;
                            }
                                break;
                            case SDLK_LEFT:
                            {
                                link.move(-10,0);
                                linkpos = 18;
                                fliptype = SDL_FLIP_HORIZONTAL;
                            }
                                break;
                            case SDLK_RIGHT:
                            {
                                link.move(10,0);
                                linkpos = 18;
                                fliptype = SDL_FLIP_NONE;
                            }
                                break;
                            default:
                            {
                                link.move(0,0);
                                linkpos = 0;
                            }
                                break;
                        }
                    }
                }
                
                background.render(NULL,SDL_FLIP_NONE);
                link.render(&spriteClips[(linkpos+frame)/6],fliptype);
                
                SDL_RenderPresent(gRenderer);
                
                ++frame;
                if(frame/6 >= 3){
                    frame = 0;
                }
            }
            
            
        }
    
    close();
    return 0;
}
