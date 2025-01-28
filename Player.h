#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "MovementComponent.h"
#include "AnimationComponent.h"

enum STATE { IDLE = 0, WALKING_LEFT, WALKING_RIGHT, RUNNIG_LEFT, RUNNING_RIGHT, JUMPING, ATTACK, HURT, DEAD };

class Player : public Entity
{
private:
	MovementComponent* movement;
	AnimationComponent* animations;
	STATE state;

public:
	Player(sf::Vector2f position,sf::Vector2f maxVelocity, sf::Texture* texture);
	~Player();
	void render(sf::RenderTarget* target);
	void update(const float& dt,bool mousePressed, bool Up, bool Down, bool Right, bool Left);
	void move(const float& dt, int dir_x, int dir_y);
	void attack(const float& dt, int dir_x, int dir_y);
	void setMovementComponent(sf::Sprite* sprite, sf::Vector2f maxVelocity);
	void setAnimationComponent(sf::Sprite* sprite, sf::Texture* texture);
	void initAnimations();
};

#endif

