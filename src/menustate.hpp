#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <vector>
#include <string>
#include "state.hpp"

class MenuEntry;

namespace Direction
{
	enum Enum
	{
		Up,
		Down
	};
}

namespace MenuEntryID
{
	enum Enum
	{
		Play,
		Settings,
		About,
		Quit
	};
}

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

		void MoveSelection(Direction::Enum direction);

		void Select(int id);

	private:
		void AddEntry(int id, std::string title);

		int selection_;
		std::vector<MenuEntry> entries_;
};

#endif /* MENUSTATE_HPP */
