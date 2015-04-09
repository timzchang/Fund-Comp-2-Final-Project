// Character.h
// Interface of the Character class. Derives from GamePiece, and so has inherentented a xpos and ypos. 
// This is the parent class of a variety of characters in the game, including Hero, Archer... etc.
// Has functionality to draw to a renderer, and check a map for valid move locaions. Has data of 
// character stats.

#ifndef CHARACTER_H
#define CHARACTER_H
#include<string>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include "GamePiece.h"
#include "Map.h"
using namespace std;
class Character: public GamePiece {
	public:
		Character();						// default constructor
		Character(string, int, int, SDL_Renderer*);		// non-default constructor
		~Character();						// deconstructor
		virtual void draw(SDL_Renderer*);				// draw function
		void change_direction(int);				// changes the direction of the sprite. 0 up, 1 right... 3 left
		int get_phase();					// returns the current phase of the sprite
		void next_phase();					// changes the phase of the sprite
		void check_valid_move(Map &, int, int, int, vector< vector<int> >);	// modifies a vector of vectors to contain valid move
		void update();
	protected:	
		int direction;						// direction the sprite is facing
		int phase;						// what foot the sprite is on
		SDL_Texture* character_texture;				// the image .png file of the sprite sheet
		int attack;						// attack stat
		int defence;						// defence stat
		int hitpoints;						// hitpoints
		int mobility;						// max tiles the Character can move
		vector<int> terrain_effect;				// effect each terrain has on mobility
		int attack_range;					// range of attack
		int counter;						// variable to count clock cycles
};
#endif
