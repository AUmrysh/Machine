#include "menustate.hpp"

MenuState::MenuState(Game *game)
: State(game)
{
}

void MenuState::Render()
{
	game_->get_window()->Clear(sf::Color(255, 0, 0));
}

void MenuState::OnEnter()
{
}

void MenuState::OnExit()
{
}

void MenuState::OnKeyPressed(sf::Key::Code key, bool alt, bool ctrl, bool shift)
{
	if (key == sf::Key::Escape)
	{
		game_->Quit();
	}
}
