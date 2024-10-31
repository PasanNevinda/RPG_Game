#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "state.h"

class MainMenuState : public State
{

private:

	sf::RectangleShape newgame;

	void setKeyBinds();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys);
	virtual ~MainMenuState();


	void render(sf::RenderWindow* target = nullptr);
	void update(const float& dt);
	void endState();
	void updateInputs(const float& dt);

};

#endif
