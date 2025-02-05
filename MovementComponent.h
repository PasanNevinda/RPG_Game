#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class MovementComponent
{
private:
	sf::Sprite* sprite;
	sf::Vector2f maxVelocity; 
	sf::Vector2f velocity;
	sf::Vector2f velocityGoal;

public:
	MovementComponent(sf::Sprite* sprite, sf::Vector2f maxVelocity);
	const sf::Vector2f& updateMovement(sf::Vector2f& position, float dt,float dir_x, float dir_y); // set velocity goal and update position
	float approachVelocity(float current, float goal, float update_factor);
};

#endif
