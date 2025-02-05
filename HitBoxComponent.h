#ifndef HIT_BOX_COMPONENT_H
#define HIT_BOX_COMPONENT_H

#include <SFML/Graphics.hpp>

class HitBoxComponent
{
private:
	sf::RectangleShape hitBox;
	sf::Vector2f position;
	sf::Sprite* sprite;

public:
	HitBoxComponent(sf::Sprite* sprite,float x_offset, float y_offset, sf::Color color,float width, float height);
	void update(sf::Vector2f movement);
	void render(sf::RenderTarget* target);
	//bool checkInterSection();
};

#endif