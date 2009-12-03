program = machine

cxx = g++
srcs = main.cpp game.cpp state.cpp menustate.cpp menuentry.cpp gamestate.cpp
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

main.o: main.cpp
	$(cxx) $(flgs) -c main.cpp -o main.o

game.o: game.cpp 
	$(cxx) $(flgs) -c game.cpp -o game.o

state.o: state.cpp
	$(cxx) $(flgs) -c state.cpp -o state.o

menustate.o: menustate.cpp
	$(cxx) $(flgs) -c menustate.cpp -o menustate.o

menuentry.o: menuentry.cpp
	$(cxx) $(flgs) -c menuentry.cpp -o menuentry.o

gamestate.o: gamestate.cpp
	$(cxx) $(flgs) -c gamestate.cpp -o gamestate.o
