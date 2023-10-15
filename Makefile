all: main

main: main.cpp src/Composition.cpp src/Line.cpp src/Poem.cpp src/RNG.cpp
	g++ main.cpp src/Composition.cpp src/Line.cpp src/Poem.cpp src/RNG.cpp -o main

clean:
	rm main
