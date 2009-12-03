#include "gamestate.hpp"

GameState::GameState(Game *game)
: State(game)
{
}

void GameState::Render()
{
	game_->get_window()->Clear(sf::Color(0, 255, 0));
}

void GameState::OnEnter()
{
	for (int i = 0; i < 255; i += 5)
	{
		game_->get_window()->Clear(sf::Color(0, i, 0));
		game_->get_window()->Display();
	}
}

void GameState::OnExit()
{
	for (int i = 255; i >= 0; i -= 5)
	{
		game_->get_window()->Clear(sf::Color(0, i, 0));
		game_->get_window()->Display();
	}
}

void GameState::OnKeyPressed(sf::Key::Code key, bool alt, bool ctrl, bool shift)
{
	if (key == sf::Key::Escape)
	{
		game_->Quit();
	}
}
