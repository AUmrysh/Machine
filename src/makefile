program = machine

cxx = g++
srcs = main.cpp game.cpp state.cpp menustate.cpp menuentry.cpp gamestate.cpp
objs = $(srcs:.cpp=.o)
libs = -lsfml-graphics -lsfml-window -lsfml-system

all: $(program)

run: $(program)
	./$(program)

clean:
	rm *.o $(program)

$(program): $(objs)
	$(cxx) -o $(program) $(objs) $(libs)

main.o: main.cpp
	$(cxx) -c $<

%.o: %.cpp %.hpp
	$(cxx) -c $<
