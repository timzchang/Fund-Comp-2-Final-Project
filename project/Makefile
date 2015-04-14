FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
EXEC = fire_emblem
OBJECTS = GamePiece.o Map.o Character.o Hero.o Cursor.o Valid_board.o


all: fire_emblem

fire_emblem: fire_emblem.cpp $(OBJECTS)
	g++ fire_emblem.cpp $(OBJECTS) $(FLAGS) -o fire_emblem

GamePiece.o: GamePiece.cpp
	g++ -c GamePiece.cpp

Character.o: Character.cpp GamePiece.h
	g++ -c Character.cpp

Hero.o: Hero.cpp Character.h
	g++ -c Hero.cpp

Cursor.o: Cursor.cpp GamePiece.h
	g++ -c Cursor.cpp

Map.o: Map.cpp
	g++ -c Map.cpp

Valid_board.o: Valid_board.cpp
	g++ -c Valid_board.cpp
.PHONY: clean

clean:
	-rm fire_emblem *.o
