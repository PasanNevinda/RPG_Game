#ifndef PAUSE_MENU_H
#define PAUSE_MENU_H

#include "SFML/Graphics.hpp"
#include <map>
#include "Button.h"
#include <iostream>

class PauseMenu
{
private:
	sf::RectangleShape background;
	std::map<std::string, Button*> buttons;
	float refreshTime;
	float elapsedTime;
	bool shouldPauses;
	sf::Font font;

public:
	PauseMenu(sf::RectangleShape rectangle, sf::Color bgcolor, sf::Vector2f position, float refreshTime);
	~PauseMenu();

	void render(sf::RenderWindow* window);

	void initFont();
	void setButton(std::string btnName, const sf::RectangleShape& shape, sf::Font* font, std::string textContent,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

	bool getShouldPause(float dt);

	bool getButtonPressed(std::string btnName);


};

#endif