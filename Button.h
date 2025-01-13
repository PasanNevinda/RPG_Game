#ifndef BUTTON_C 
#define BUTTON_C

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Button
{
private:
	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;
	bool pressed = false;

public:
	Button(const sf::RectangleShape& shape,sf::Font* font, std::string textContent, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
	~Button();
	void render(sf::RenderWindow* target= nullptr);
	void update(const sf::Vector2i& mousePosition);
	bool isPressed();
	void setPosition(float x, float y);
	const sf::Vector2f& getSize() const;
};

#endif