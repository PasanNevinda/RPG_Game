#include "MainMenuState.h"


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys) :State(window, available_keys)
{
	newgame.setFillColor(sf::Color::Green);
	newgame.setSize(sf::Vector2f(300, 100));
	newgame.setPosition(250, 250);
	setKeyBinds();
} 

MainMenuState::~MainMenuState()
{
}

void MainMenuState::setKeyBinds()
{
	key_binds["QUIT"] = sf::Keyboard::Key::Escape;
	/*std::ifstream file("Config/game_state_keys.ini");
	if (file)
	{
		std::string key_name;
		int key;
		while (file >> key_name >> key)
		{
			key_binds[key_name] = sf::Keyboard::Key(key);
		}
	}
	file.close();*/
}

void MainMenuState::update(const float& dt)
{
	updateInputs(dt);

}

void MainMenuState::render(sf::RenderWindow* target)
{
	if (!target)
		target = this->window;

	target->draw(newgame);
}

void MainMenuState::endState()
{
}

void MainMenuState::updateInputs(const float& dt)
{
	checkQuit();
}
