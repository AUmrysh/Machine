builddir = ../build
bindir = ../bin
program = $(bindir)/machine

cxx = g++
srcs = main.cpp game.cpp state.cpp menustate.cpp menuentry.cpp gamestate.cpp
objs = $(srcs:%.cpp=$(builddir)/%.o)
flgs = -Wall
libs = -lsfml-graphics -lsfml-window -lsfml-system

all: compile $(program)

run: compile $(program)
	./$(program)

clean:
	rm $(builddir)/*.o $(program)

compile:
	mkdir -p $(builddir)
	mkdir -p $(bindir)

$(program): $(objs)
	$(cxx) -o $(program) $(objs) $(libs)

$(builddir)/main.o: main.cpp
	$(cxx) $(flgs) -c $< -o $@

$(builddir)/%.o: %.cpp %.hpp
	$(cxx) $(flgs) -c $< -o $(builddir)/$@
