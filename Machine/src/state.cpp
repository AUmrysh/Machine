#include "state.hpp"
#include "game.hpp"

State::State(Game *game)
: game_(game)
{
}

State::~State()
{
}

void State::OnEvent(const sf::Event::Event &e)
{
	switch (e.Type)
	{
		case sf::Event::KeyPressed:
			OnKeyPressed(e.Key.Code, e.Key.Alt, e.Key.Control, e.Key.Shift);
			break;

		case sf::Event::KeyReleased:
			OnKeyReleased(e.Key.Code, e.Key.Alt, e.Key.Control, e.Key.Shift);
			break;

		case sf::Event::MouseMoved:
			OnMouseMoved(e.MouseMove.X, e.MouseMove.Y);
			break;

		case sf::Event::MouseButtonPressed:
		{
			int x = e.MouseButton.X;
			int y = e.MouseButton.Y;

			switch (e.MouseButton.Button)
			{
				case sf::Mouse::Left:
					OnMouseLeftDown(x, y);
					buttons_[0] = true;
					break;

				case sf::Mouse::Right:
					OnMouseRightDown(x, y);
					buttons_[1] = true;
					break;

				case sf::Mouse::Middle:
					OnMouseMiddleDown(x, y);
					buttons_[2] = true;
					break;
			}

			break;
		}

		case sf::Event::MouseButtonReleased:
		{
			int x = e.MouseButton.X;
			int y = e.MouseButton.Y;

			switch (e.MouseButton.Button)
			{
				case sf::Mouse::Left:
					OnMouseLeftUp(x, y);

					if (buttons_[0])
					{
						buttons_[0] = false;
						OnMouseLeftClick(x, y);
					}

					break;

				case sf::Mouse::Right:
					OnMouseRightUp(x, y);

					if (buttons_[1])
					{
						buttons_[1] = false;
						OnMouseRightClick(x, y);
					}

					break;

				case sf::Mouse::Middle:
					OnMouseMiddleUp(x, y);

					if (buttons_[2])
					{
						buttons_[2] = false;
						OnMouseMiddleClick(x, y);
					}

					break;
			}

			break;
		}

		case sf::Event::MouseEntered:
			OnMouseEntered();
			break;

		case sf::Event::MouseLeft:
			OnMouseExited();
			break;

		case sf::Event::GainedFocus:
			OnGainedFocus();
			break;

		case sf::Event::LostFocus:
			OnLostFocus();
			break;
	}
}
