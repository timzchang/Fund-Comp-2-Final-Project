#ifndef CHARACTER_H
#define CHARACTER_H
#include<string>
using namespace std;
class Character: public Game_Piece {
	public:
		Character();
		Character(string, int, int, SDL_Renderer*);
		~Character();
		void draw(SDL_Renderer*);
		void move(int);
		void change_direction(int);
	private:
		int direction;
		int phase;
		SDL_Texture* character_texture;
};
#endif
