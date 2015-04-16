#Ignore the $(#MACFLAGS) variable. I need this to compile locally on my mac. It's a pain. Please comment out when compiling on Linux

MACFLAGS = `sdl2-config --cflags --libs` 
FLAGS = -lSDL2 -lSDL2_image $(MACFLAGS) #-lSDL2_ttf #-lSDL2_image  
EXEC = fire_emblem
OBJECTS = GamePiece.o Map.o Character.o Hero.o Cursor.o Valid_board.o


all: fire_emblem

fire_emblem: fire_emblem.cpp $(OBJECTS)
	g++ fire_emblem.cpp $(OBJECTS) -o fire_emblem $(FLAGS) 

GamePiece.o: GamePiece.cpp
	g++ -c GamePiece.cpp $(MACFLAGS)

Character.o: Character.cpp GamePiece.h
	g++ -c Character.cpp $(MACFLAGS)

Hero.o: Hero.cpp Character.h
	g++ -c Hero.cpp $(MACFLAGS)

Cursor.o: Cursor.cpp GamePiece.h
	g++ -c Cursor.cpp $(MACFLAGS)

Map.o: Map.cpp
	g++ -c Map.cpp $(MACFLAGS)

Valid_board.o: Valid_board.cpp
	g++ -c Valid_board.cpp $(MACFLAGS)


.PHONY: clean

clean:
	-rm fire_emblem *.o *~
