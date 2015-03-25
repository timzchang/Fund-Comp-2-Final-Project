//
//  Header.h
//  moving_sprite
//
//  Created by Tim Chang on 3/18/15.
//  Copyright (c) 2015 Tim Chang. All rights reserved.
//

#ifndef LTEXTURE_H
#define LTEXTURE_H

#include<stdio.h>
#include<iostream> 

#include<SDL2/SDL.h>
#include<SDL2_image/SDL_image.h>
//#include<SDL.h>
//#include<SDL_image.h>
using namespace std;

const int SCREEN_HEIGHT = 640;
const int SCREEN_WIDTH = 640;

class LTexture {
public:
    LTexture(int, int); //constructor. takes in x and y positions of screen to be rendered to
    ~LTexture();
    
    bool loadFromFile(string path); //load surface from path, color key the background color, convert to texture
    void free();
    void render(SDL_Rect * clip = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE); //need to render from multiple parts of the texture. clip is the rect of the sprite sheet we want to render.
    void setRenderer(SDL_Renderer *); //set the renderer
    void move(int x, int y);  //modify the x and y pos
    //void optimize(SDL_Surface *);
    int getWidth();
    int getHeight();
private:
    SDL_Texture * mTexture;
    SDL_Renderer * gRenderer;
    int mWidth; //width and height of the texture
    int mHeight;
    
    int xpos; //the (x,y) on the screen to render to
    int ypos;
    
    //int optflag; //won't optimize if 0, will optimize for everything else
};

LTexture::LTexture(int x, int y){
    gRenderer = NULL;
    mTexture = NULL;
    
    mWidth = 0;
    mHeight = 0;
    
    xpos = x;
    ypos = y;
}

LTexture::~LTexture(){
    free();
    SDL_DestroyRenderer(gRenderer);
    gRenderer = NULL;
}

int LTexture::getWidth()
{
    return mWidth;
}

int LTexture::getHeight()
{
    return mHeight;
}

void LTexture::free(){
    SDL_DestroyTexture(mTexture);
    mTexture = NULL;
}

void LTexture::render(SDL_Rect * clip, SDL_RendererFlip flip){
    SDL_Rect renderQuad = {xpos, ypos, mWidth, mHeight};
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    
    SDL_RenderCopyEx(gRenderer, mTexture, clip, &renderQuad, 0, NULL, flip);
}

void LTexture::setRenderer(SDL_Renderer * gRenderers){
    gRenderer = gRenderers;
}

void LTexture::move(int x, int y){
    xpos += x;
    ypos += y;
}

bool LTexture::loadFromFile(string path){
    SDL_Texture * loadedTexture = NULL;
    
    SDL_Surface * loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL)
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
    }
    else
    {

        //I HAVE NO IDEA WHAT THE BACKGROUND COLOR IS
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 13, 0, 65));
        //SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0xFF, 0xFF, 0xFF));
        
        loadedTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if(loadedTexture == NULL)
        {
             printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        else
        {
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }
        
        SDL_FreeSurface(loadedSurface);
    }
    
    mTexture = loadedTexture;
    
    return mTexture != NULL; //if it is null, returns 0, if it is not null, returns 1
}



#endif
