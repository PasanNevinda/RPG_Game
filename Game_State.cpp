#include "Game_State.h"

Game_State::Game_State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys, std::stack<State*>* states):State(window,available_keys,states)
{
	setKeyBinds();
}

Game_State::~Game_State()
{
}

void Game_State::setKeyBinds()
{
	std::ifstream file("Config/game_state_keys.ini");
	if (file)
	{
		std::string key_name;
		int key;
		while (file >> key_name >> key)
		{
			key_binds[key_name] = sf::Keyboard::Key(key);
		}
	}
	file.close();
}

void Game_State::update(const float& dt)
{
	updateInputs(dt);
	updateMousePositionWindow(window);

	
}

void Game_State::render(sf::RenderWindow* target) 
{
	if (!target)
		target = this->window;
	
	player.render(target);
}

void Game_State::endState()
{
}

void Game_State::updateInputs(const float& dt)
{
	//check for quit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		setQuit(true);

	if (sf::Keyboard::isKeyPressed(key_binds.at("MOVE_LEFT")))
		player.move(dt, -1, 0);
	if (sf::Keyboard::isKeyPressed(key_binds.at("MOVE_RIGHT")))
		player.move(dt, 1, 0);
	if (sf::Keyboard::isKeyPressed(key_binds.at("MOVE_DOWN")))
		player.move(dt, 0, 1);
	if (sf::Keyboard::isKeyPressed(key_binds.at("MOVE_UP")))
		player.move(dt, 0, -1);
}
