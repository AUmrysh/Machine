#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "game.hpp"

class State
{
	public:
		State(Game *game);

		virtual ~State();

		void OnEvent(const sf::Event &e);

		virtual void Update() = 0;

		virtual void Render() = 0;

		virtual void OnEnter() = 0;

		virtual void OnExit() = 0;

	protected:
		virtual void OnKeyPressed(sf::Key::Code key, bool alt, bool ctrl, bool shift) { }

		virtual void OnKeyReleased(sf::Key::Code key, bool alt, bool ctrl, bool shift) { }

		virtual void OnMouseMoved(int x, int y) { }

		virtual void OnMouseLeftDown(int x, int y) { }

		virtual void OnMouseLeftUp(int x, int y) { }

		virtual void OnMouseRightDown(int x, int y) { }

		virtual void OnMouseRightUp(int x, int y) { }

		virtual void OnMouseMiddleDown(int x, int y) { }

		virtual void OnMouseMiddleUp(int x, int y) { }

		virtual void OnMouseLeftClick(int x, int y) { }

		virtual void OnMouseRightClick(int x, int y) { }

		virtual void OnMouseMiddleClick(int x, int y) { }

		virtual void OnMouseEntered() { }

		virtual void OnMouseExited() { }

		virtual void OnGainedFocus() { }

		virtual void OnLostFocus() { }

		Game *game_;
		
	private:
		bool buttons_[3];
};

#endif /* STATE_HPP */
