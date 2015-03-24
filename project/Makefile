all: Map_tester

Map_tester: Map_tester.cpp Map.cpp
	g++ Map_tester.cpp Map.cpp -lSDL2 -lSDL2_image -o Map_tester

.PHONY: clean

clean:
	-rm Map_tester
