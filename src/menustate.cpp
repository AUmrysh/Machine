#include "menustate.hpp"
#include "menuentry.hpp"
#include "gamestate.hpp"

MenuState::MenuState(Game *game)
: State(game)
{
	AddEntry(MenuEntryID::Play, "Play");
	AddEntry(MenuEntryID::Settings, "Settings");
	AddEntry(MenuEntryID::About, "About");
	AddEntry(MenuEntryID::Quit, "Quit");

	entries_[0].set_selected(true);
}

void MenuState::Render()
{
	sf::RenderWindow *rw = game_->get_window();
	rw->Clear(sf::Color(255, 0, 0));
	
	int width = 200;
	int height = 50;
	int padding = 20;
	int center_x = rw->GetWidth() / 2;
	int center_y = rw->GetHeight() / 2;
	int x = center_x - (width / 2);
	int y = center_y - (((entries_.size() * (height + padding)) - padding) / 2);

	for (int i = 0; i < entries_.size(); ++i, y += (height + padding))
	{
		entries_[i].Draw(rw, x, y, width, height);
	}
}

void MenuState::OnEnter()
{
	for (int i = 0; i < 255; i += 5)
	{
		game_->get_window()->Clear(sf::Color(i, 0, 0));
		game_->get_window()->Display();
	}
}

void MenuState::OnExit()
{
	for (int i = 255; i >= 0; i -= 5)
	{
		game_->get_window()->Clear(sf::Color(i, 0, 0));
		game_->get_window()->Display();
	}
}

void MenuState::OnKeyPressed(sf::Key::Code key, bool alt, bool ctrl, bool shift)
{
	if (key == sf::Key::Up)
	{
		MoveSelection(Direction::Up);
	}
	else if (key == sf::Key::Down)
	{
		MoveSelection(Direction::Down);
	}
	else if (key == sf::Key::Return)
	{
		Select(entries_[selection_].get_id());
	}
}

void MenuState::MoveSelection(Direction::Enum direction)
{
	entries_[selection_].set_selected(false);

	if (direction == Direction::Up)
	{
		--selection_;

		if (selection_ == -1)
		{
			selection_ = entries_.size() - 1;
		}
	}
	else if (direction == Direction::Down)
	{
		++selection_;

		if (selection_ == entries_.size())
		{
			selection_ = 0;
		}
	}

	entries_[selection_].set_selected(true);
}

void MenuState::Select(int id)
{
	switch (id)
	{
		case MenuEntryID::Play:
			game_->set_active_state(new GameState(game_));
			break;

		case MenuEntryID::Settings:
			break;

		case MenuEntryID::About:
			break;

		case MenuEntryID::Quit:
			game_->Quit();
			break;
	}
}

void MenuState::AddEntry(int id, std::string text)
{
	entries_.push_back(MenuEntry(id, text));
}
