#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "state.hpp"

class MenuState : public State
{
	public:
		MenuState(Game *game);

		void Update() { }

		void Render();

		void OnEnter();

		void OnExit();

	protected:
		void OnKeyPressed(sf::Key::Code key, bool alt, bool ctrl, bool shift);
};

#endif /* MENUSTATE_HPP */
