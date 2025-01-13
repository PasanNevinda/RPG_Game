#ifndef MAIN_MENU_STATE_H
#define MAIN_MENU_STATE_H

#include "state.h"
#include "Button.h"
#include "Game_State.h"

class MainMenuState : public State
{

private:
	sf::RectangleShape background;
	sf::Font font;
	std::map<std::string, Button*> buttons;

	void setKeyBinds();
	void initFont();
	void initButtons();

public:
	MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys, std::stack<State*>* states);
	virtual ~MainMenuState();


	void render(sf::RenderWindow* target = nullptr);
	void update(const float& dt);
	void endState();
	void updateInputs(const float& dt);

};

#endif
