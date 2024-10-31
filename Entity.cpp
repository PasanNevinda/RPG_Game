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
	
}

void Entity::move(const float& dt, int x, int y)
{
	shape.move(x * movement_speed * dt, y *movement_speed* dt);
}
