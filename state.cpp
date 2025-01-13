#include "state.h"

void State::updateMousePositionWindow(sf::RenderWindow* CurrentWindow)
{
	mousePositionWindow = sf::Mouse::getPosition(*CurrentWindow);
}

State::State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys, std::stack<State*>* states)
{
	this->window = window;
	this->quit = false;
	this->available_keys = available_keys;
	this->states = states;
}

State::~State()
{
}


void State::setQuit(bool state)
{
	quit = state;
}

const bool& State::getQuit()
{
	return quit;
}

