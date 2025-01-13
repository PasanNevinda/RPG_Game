#include "Button.h"
#include <iostream>

Button::Button(const sf::RectangleShape& shape, sf::Font* font, std::string textContent, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor):
	shape(shape),font(font),idleColor(idleColor),hoverColor(hoverColor),activeColor(activeColor)
{
	text.setFont(*font);
	text.setString(textContent);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	this->shape.setFillColor(idleColor);
}

Button::~Button()
{
	//delete font; no need  to delete font, because it is a instance of MainMenuState
}

void Button::render(sf::RenderWindow* target)
{
	target->draw(shape);
	target ->draw(text);
}

void Button::update(const sf::Vector2i& mousePosition)
{
	// check button presses
	if (shape.getGlobalBounds().contains(static_cast<const sf::Vector2f>(mousePosition)))
	{
		shape.setFillColor(hoverColor);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			shape.setFillColor(activeColor);
			pressed = true;
		}
		else
			pressed = false;
	}
	else
	{
		shape.setFillColor(idleColor);
		pressed = false;
	}
}

bool Button::isPressed()
{
	return pressed;
}

void Button::setPosition(float x, float y)
{
	shape.setPosition(x, y);
	std::cout << "text size local = " << text.getLocalBounds().width << "  " << text.getLocalBounds().height << "\n";
	std::cout << "text size global = " << text.getGlobalBounds().width << "  " << text.getGlobalBounds().height << "\n";
	text.setPosition(x + 0.5*(shape.getSize().x - text.getLocalBounds().width), y+ 0.5*(shape.getSize().y - 2*text.getLocalBounds().height));
}

const sf::Vector2f& Button::getSize() const
{
	return shape.getSize();
}

