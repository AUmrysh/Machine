#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "state.hpp"

class GameState : public State
{
	public:
		GameState(Game *game);

		void Update() { }

		void Render();

		void OnEnter();

		void OnExit();

	protected:
		void OnKeyPressed(sf::Key::Code key, bool alt, bool ctrl, bool shift);
};

#endif /* GAMESTATE_HPP */
