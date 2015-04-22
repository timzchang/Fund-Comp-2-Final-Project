#Ignore the $(#MACFLAGS) variable. I need this to compile locally on my mac. It's a pain. Please comment out when compiling on Linux

MACFLAGS = `sdl2-config --cflags --libs` -std=c++11 -static-libstdc++
FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf $(MACFLAGS) #-lSDL2_ttf #-lSDL2_image  
EXEC = fire_emblem
OBJECTS = GamePiece.o Map.o Character.o Hero.o Cursor.o Valid_board.o Angel.o Archer.o Mage.o Pirate.o Soldier.o Sorcerer.o Stats_Menu.o


all: fire_emblem

fire_emblem: fire_emblem.cpp $(OBJECTS)
	g++ fire_emblem.cpp $(OBJECTS) -o fire_emblem $(FLAGS) 

GamePiece.o: GamePiece.cpp
	g++ -c GamePiece.cpp $(MACFLAGS)

Character.o: Character.cpp GamePiece.h
	g++ -c Character.cpp $(MACFLAGS)

Angel.o: Angel.cpp Angel.h
	g++ -c Angel.cpp $(MACFLAGS)

Archer.o: Archer.cpp Archer.h
	g++ -c Archer.cpp $(MACFLAGS)

Mage.o: Mage.cpp Mage.h
	g++ -c Mage.cpp $(MACFLAGS)

Pirate.o: Pirate.cpp Pirate.h
	g++ -c Pirate.cpp $(MACFLAGS)

Soldier.o: Soldier.cpp Soldier.h
	g++ -c Soldier.cpp $(MACFLAGS)

Sorcerer.o: Sorcerer.cpp Sorcerer.h
	g++ -c Sorcerer.cpp $(MACFLAGS)

Hero.o: Hero.cpp Character.h
	g++ -c Hero.cpp $(MACFLAGS)

Cursor.o: Cursor.cpp GamePiece.h
	g++ -c Cursor.cpp $(MACFLAGS)

Map.o: Map.cpp
	g++ -c Map.cpp $(MACFLAGS)

Valid_board.o: Valid_board.cpp
	g++ -c Valid_board.cpp $(MACFLAGS)

Stats_Menu.o: Stats_Menu.cpp
	g++ -c Stats_Menu.cpp $(MACFLAGS)

.PHONY: clean

clean:
	-rm fire_emblem *.o *~
