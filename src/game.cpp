#include "game.hpp"
#include "state.hpp"
#include "menustate.hpp"

Game::Game(const std::string &title, unsigned int width, unsigned int height, bool fullscreen)
: running_(false), active_state_(0)
{
	unsigned long style = sf::Style::Close;

	if (fullscreen)
	{
		style |= sf::Style::Fullscreen;
	}

	window_.Create(sf::VideoMode(width, height), title, style);
}

Game::~Game()
{
	set_active_state(0);
}

void Game::Run()
{
	Initialize();

	running_ = true;

	while (running_)
	{
		Update();
		Render();
	}
}

void Game::Quit()
{
	running_ = false;
}

void Game::set_active_state(State *state)
{
	if (active_state_)
	{
		active_state_->OnExit();
		delete active_state_;
	}

	active_state_ = state;

	if (active_state_)
	{
		active_state_->OnEnter();
	}
}

void Game::Initialize()
{
	window_.UseVerticalSync(false);
	window_.SetFramerateLimit(60);
	set_active_state(new MenuState(this));
}

void Game::Update()
{
	sf::Event e;

	while (window_.GetEvent(e))
	{
		if (e.Type == sf::Event::Closed)
		{
			running_ = false;
		}
		else if (active_state_)
		{
			active_state_->OnEvent(e);
		}
	}

	if (active_state_)
	{
		active_state_->Update();
	}
}

void Game::Render()
{
	window_.Clear(sf::Color(0, 0, 0));

	if (active_state_)
	{
		active_state_->Render();
	}

	window_.Display();
}
