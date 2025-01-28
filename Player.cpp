#include "Player.h"

Player::Player(sf::Vector2f position, sf::Vector2f maxVelocity, sf::Texture* texture):Entity(position)
{
	this->setMovementComponent(&this->sprite, maxVelocity);
	this->setAnimationComponent(&this->sprite, texture);
	initAnimations();
	animations->initializeAnimation("row1", &this->sprite);
	state = IDLE;
	this->sprite.setScale(5, 5);
	
}

Player::~Player()
{
	delete movement;
	delete animations;
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

void Player::update(const float& dt, bool mousePressed, bool Up, bool Down, bool Right, bool Left)
{
	int dir_x = Right ? 1 : Left ? -1 : 0;
	int dir_y = Down ? 1 : Up ? -1 : 0;
	
	/*std::cout << " dir_x in player " << dir_x << "\n";
	std::cout << " dir_y in player " << dir_y << "\n";*/

	if (mousePressed)
		this->attack(dt,dir_x,dir_y);

	this->move(dt, dir_x, dir_y);

}

void Player::move(const float& dt, int dir_x, int dir_y)
{
	movement->updateMovement(this->position, dt, dir_x, dir_y);
	// movement animation goes here
	
	if(dir_x)
		animations->run("row1", dt);

}

void Player::attack(const float& dt, int dir_x, int dir_y)
{
	// attack animation goes here
}

void Player::setMovementComponent(sf::Sprite* sprite, sf::Vector2f maxVelocity)
{
	this->movement = new MovementComponent(sprite, maxVelocity);
}

void Player::setAnimationComponent(sf::Sprite* sprite, sf::Texture* texture)
{
	this->animations = new AnimationComponent(sprite, texture);
}

void Player::initAnimations()
{
	animations->createAnimation("row0", 0, 5, 0, 48, 48, 10, 1);
	animations->createAnimation("row1", 0, 5, 1, 48, 48, 10, 1);
	animations->createAnimation("row2", 0, 5, 2, 48, 48, 100, 1);
	animations->createAnimation("row3", 0, 5, 3, 48, 48, 100, 1);
	animations->createAnimation("row4", 0, 5, 4, 48, 48, 100, 1);
	animations->createAnimation("row5", 0, 5, 5, 48, 48, 100, 1);
	animations->createAnimation("row6", 0, 3, 6, 48, 48, 100, 1);
	animations->createAnimation("row7", 0, 3, 7, 48, 48, 100, 1);
	animations->createAnimation("row8", 0, 3, 8, 48, 48, 100, 1);
	animations->createAnimation("row9", 0, 2, 9, 48, 48, 100, 1);
}

