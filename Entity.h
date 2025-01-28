#ifndef ENTITY_H
#define	ENTITY_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Entity
{
private:

protected:
	//sf::RectangleShape shape;
	//float movement_speed;
	sf::Sprite sprite;
	sf::Vector2f position;

public:

	Entity(sf::Vector2f position);
	virtual ~Entity();

	virtual void render(sf::RenderTarget* target) = 0;
	virtual void update(const float& dt);
	virtual void move(const float& dt, int dir_x, int dir_y) = 0;
};

#endif;