#include "state.h"

State::State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys)
{
	this->window = window;
	this->quit = false;
	this->available_keys = available_keys;
}

State::~State()
{
}

void State::checkQuit()
{
	if (sf::Keyboard::isKeyPressed(key_binds.at("QUIT")))
		quit = true;
}

const bool& State::getQuit()
{
	return quit;
}
