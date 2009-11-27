#include "game.hpp"

int main(int argc, char **argv)
{
	Game game("Machine", 800, 600, false);
	game.Run();
	return 0;
}
