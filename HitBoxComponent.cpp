#include "HitBoxComponent.h"

HitBoxComponent::HitBoxComponent(sf::Sprite* sprite, float x_offset, float y_offset, sf::Color color, float width, float height):hitBox(sf::Vector2f(width,height)),
position(sprite->getPosition().x + x_offset,sprite->getPosition().y + y_offset), sprite(sprite)
{
	hitBox.setOutlineColor(color);
	hitBox.setOutlineThickness(1);
	hitBox.setFillColor(sf::Color::Transparent);
	hitBox.setPosition(position);
}

void HitBoxComponent::update(sf::Vector2f movement)
{
	hitBox.move(movement);
}

void HitBoxComponent::render(sf::RenderTarget* target)
{
	target->draw(hitBox);
}

