all: bin/main

bin/main: src/main.cpp src/Composition.cpp src/Line.cpp src/Poem.cpp src/RNG.cpp
	g++ src/main.cpp src/Composition.cpp src/Line.cpp src/Poem.cpp src/RNG.cpp -o bin/main

clean:
	rm bin/main
