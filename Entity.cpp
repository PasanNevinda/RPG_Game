#include "Entity.h"

Entity::Entity()
{
	shape = sf::RectangleShape(sf::Vector2f(100, 100));
	shape.setFillColor(sf::Color::White);
	movement_speed = 100.f;
}

Entity::~Entity()
{
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(shape);
}

void Entity::update(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		move(dt, -1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		move(dt, 1, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		move(dt, 0, 1);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		move(dt,0,-1);
	
}

void Entity::move(const float& dt, int x, int y)
{
	shape.move(x * movement_speed * dt, y *movement_speed* dt);
}
