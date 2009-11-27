program = machine

cxx = g++
srcs = main.cpp game.cpp state.cpp
objs = $(srcs:.cpp=.o)
flgs = 
libs = -lsfml-graphics -lsfml-window -lsfml-system

all: $(program)

run: $(program)
	./$(program)

clean:
	rm *.o $(program)

$(program): $(objs)
	$(cxx) -o $(program) $(objs) $(libs)

main.o: main.cpp game.hpp
	$(cxx) $(flgs) -c main.cpp -o main.o

game.o: game.cpp state.hpp
	$(cxx) $(flgs) -c game.cpp -o game.o

state.o: state.cpp
	$(cxx) $(flgs) -c state.cpp -o state.o
