#ifndef ENTITY_H
#define	ENTITY_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Entity
{
private:

protected:
	sf::RectangleShape shape;
	float movement_speed;

public:

	Entity();
	virtual ~Entity();

	virtual void render(sf::RenderTarget* target);
	virtual void update(const float& dt);
	virtual void move(const float& dt, int x, int y);
};

#endif;