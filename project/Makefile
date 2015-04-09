all: Map_tester

Map_tester: Map_tester.cpp Map.cpp Character.cpp GamePiece.cpp Hero.cpp Cursor.cpp 
	g++ Map_tester.cpp Map.cpp Hero.cpp Character.cpp GamePiece.cpp Cursor.cpp -lSDL2 -lSDL2_image -o Map_tester

.PHONY: clean

clean:
	-rm Map_tester
