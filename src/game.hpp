#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "state.hpp"

class Game
{
	public:
		Game(const std::string &title, unsigned int width, unsigned int height, bool fullscreen);

		~Game();

		void Run();

		void set_active_state(State *state);
		
	private:
		void Initialize();

		void Update();

		void Render();

		bool running_;
		sf::RenderWindow window_;
		State *active_state_;
};

#endif /* GAME_HPP */
