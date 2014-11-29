CXX = clang++

default: main

main: main.cpp
	$(CXX) -W -std=c++11 main.cpp coordinate.cpp baseai.cpp tile.cpp mappable.cpp unit.cpp ai.cpp -o run

clean:
	rm run