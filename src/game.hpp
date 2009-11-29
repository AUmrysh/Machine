#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class State;

class Game
{
	public:
		Game(const std::string &title, unsigned int width, unsigned int height, bool fullscreen);

		~Game();

		void Run();

		void Quit();

		void set_active_state(State *state);

		sf::RenderWindow * get_window() { return &window_; }
		
	private:
		void Initialize();

		void Update();

		void Render();

		bool running_;
		sf::RenderWindow window_;
		State *active_state_;
};

#endif /* GAME_HPP */
