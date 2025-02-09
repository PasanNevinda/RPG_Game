#include "Player.h"

Player::Player(sf::Vector2f position, sf::Vector2f maxVelocity, sf::Texture* texture):Entity(position)
{
	this->setMovementComponent(&this->sprite, maxVelocity);
	this->setAnimationComponent(&this->sprite, texture);
	initAnimations();
	animations->initializeAnimation("run_right", &this->sprite);
	state = IDLE;
	this->hitbox = new HitBoxComponent(&this->sprite,94,109,sf::Color::Red,59,105);
	this->sprite.setScale(5,5);

}

Player::~Player()
{
	delete movement;
	delete animations;
	delete hitbox;
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
	hitbox->render(target);
}

void Player::update(const float& dt)
{
	// TODO:
	/*
		* remove all userInput from here
		* do it in game state, by attack, move, wait functions
		* use update for do things like health update after attack etc
	*/
}

void Player::move(const float& dt, int dir_x, int dir_y)
{
	const sf::Vector2f& change_of_move = movement->updateMovement(this->position, dt, dir_x, dir_y);
	hitbox->update(change_of_move);
	// movement animation goes here

	if (dir_x == 1)
	{
		sprite.setOrigin(0, 0);
		sprite.setScale(5, 5);
		animations->run("run_right", dt);
	}
	else if (dir_x == -1)
	{
		sprite.setOrigin(sprite.getLocalBounds().width, 0);
		sprite.setScale(-5, 5);
		animations->run("run_right", dt);
	}
	else if (dir_y == 1)
	{
		sprite.setOrigin(0, 0);
		sprite.setScale(5, 5);
		animations->run("run_down", dt);
	}
	else if (dir_y == -1)
	{
		sprite.setOrigin(0, 0);
		sprite.setScale(5, 5);
		animations->run("run_up", dt);
	}

}

void Player::attack(const float& dt, const previousDirection& pDir)
{
	if (pDir == previousDirection::left || pDir == previousDirection::right)
		animations->run("attack_right", dt);
	else if (pDir == previousDirection::front)
		animations->run("attack_front", dt);
	else if (pDir == previousDirection::up)
		animations->run("attack_up", dt);
}

void Player::wait(const float& dt, const previousDirection& pDir)
{
	if (pDir == previousDirection::front)
		animations->run("wait_front", dt);
	else if (pDir == previousDirection::left || pDir == previousDirection::right)
		animations->run("wait_right", dt);
	else if (pDir == previousDirection::up)
		animations->run("wait_up", dt);
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
	animations->createAnimation("wait_front", 0, 5, 0, 48, 48, 10, 1);
	animations->createAnimation("wait_right", 0, 5, 1, 48, 48, 10, 1);
	animations->createAnimation("wait_up", 0, 5, 2, 48, 48, 10, 1);
	animations->createAnimation("run_down", 0, 5, 3, 48, 48, 10, 1);
	animations->createAnimation("run_right", 0, 5, 4, 48, 48, 10, 1);
	animations->createAnimation("run_up", 0, 5, 5, 48, 48, 10, 1);
	animations->createAnimation("attack_front", 0, 3, 6, 48, 48, 10, 1);
	animations->createAnimation("attack_right", 0, 3, 7, 48, 48, 10, 1);
	animations->createAnimation("attack_up", 0, 3, 8, 48, 48, 10, 1);
	animations->createAnimation("die", 0, 2, 9, 48, 48, 10, 1);
}

