#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite* sprite, sf::Vector2f maxVelocity):sprite(sprite),maxVelocity(maxVelocity)
{
	velocity = { 0,0 };
}

const sf::Vector2f& MovementComponent::updateMovement(sf::Vector2f& position, float dt,float dir_x, float dir_y)
{
	if (dir_x == 1)
	{
		velocityGoal.x = maxVelocity.x;
		if (velocity.x < 0)
			velocity.x = dt;
	}

	if (dir_x == -1)
	{
		velocityGoal.x = -maxVelocity.x;
		if (velocity.x > 0)
			velocity.x = -dt;
	}

	if (dir_x == 0)
		velocity.x = 0;
	else
		velocity.x = approachVelocity(velocity.x, velocityGoal.x, dt * 1000);
	//std::cout << "velocity = " << velocity.x << "velocity_goal = " << velocityGoal.x << "\n";
	//position.x = position.x + velocity.x * dt;
	
	//sprite->setPosition(position);

	sprite->move(velocity * dt);
	return velocity * dt;
}

float MovementComponent::approachVelocity(float current, float goal, float update_factor)
{
	float difference = goal - current;
	if (difference > update_factor)
		return current + update_factor;

	if (difference < (-update_factor))
		return current - update_factor;
	return current;
}
