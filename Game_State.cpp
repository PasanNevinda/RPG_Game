#include "Game_State.h"

Game_State::Game_State(sf::RenderWindow* window):State(window)
{
}

Game_State::~Game_State()
{
}

void Game_State::update(const float& dt)
{
	updateKeybinds(dt);
	player.update(dt);

}

void Game_State::render(sf::RenderWindow* target) 
{
	if (target)
	{

	}
	else
	{
		player.render(this->window);
	}
}

void Game_State::endState()
{
}

void Game_State::updateKeybinds(const float& dt)
{
	checkForQuit();
}
