#ifndef CHARACTER_H
#define CHARACTER_H
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "Game_Piece.h"
using namespace std;
class Character: public Game_Piece {
	public:
		Character();
		Character(string, int, int, SDL_Renderer*);
		~Character();
		void draw(SDL_Renderer*);
		void change_direction(int);
		int get_phase();
		void set_phase(int)
	protected:
		int direction;
		int phase;
		SDL_Texture* character_texture;
};
#endif
