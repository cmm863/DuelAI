CXX = clang++

default: main

main: main.cpp
	$(CXX) -W -std=c++11 main.cpp protohandler.cpp gamestatehandler.cpp coordinate.cpp baseai.cpp tile.cpp mappable.cpp unit.cpp ai.cpp gamestate.pb.cc -o run -lprotobuf

clean:
	rm run