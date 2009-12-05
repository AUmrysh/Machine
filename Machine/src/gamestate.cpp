#include "gamestate.hpp"

GameState::GameState(Game *game)
: State(game)
{
}

//The image loader, should only be required once according to docs
sf::Image Image;
sf::Clock Clock;
float alien_x = 0.0f;
float alien_y = 0.0f;
float alien_velx = 2.3f;
float alien_vely = 2.3f;

void GameState::Render()
{
	game_->get_window()->Clear(sf::Color(0, 30, 255));
	game_->get_window()->Draw(sf::String("Hit ESC to quit"));

	//DRAW THE REDDIT ALIEN!!!!!
	{
		if (!Image.LoadFromFile("img/alien.png"))
		{
            game_->get_window()->Draw(sf::String("\nalien.png not loading!"));
		}
		sf::Sprite alien(Image);
		alien.SetScale(0.5f,0.5f);
		alien_x += alien_velx;
		alien_y += alien_vely;
		if (alien_x + alien.GetSize().x > game_->get_window()->GetWidth() || alien_x < 0)
		{
		    alien_velx *= -1;
		}
		if (alien_y + alien.GetSize().y > game_->get_window()->GetHeight() || alien_y < 0)
		{
		    alien_vely *= -1;
		}
		alien.SetPosition(alien_x, alien_y);
		game_->get_window()->Draw(sf::Sprite(alien));
	}
}

//This happens when the window "opens"
void GameState::OnEnter()
{
	for (int i = 0; i < 255; i += 5)
	{
		game_->get_window()->Clear(sf::Color(0, i/(8.5f), i));
		game_->get_window()->Display();
	}
}

//This happens when the window is "closed"
void GameState::OnExit()
{
	for (int i = 255; i >= 0; i -= 5)
	{
		game_->get_window()->Clear(sf::Color(0, i/(8.5f), i));
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
