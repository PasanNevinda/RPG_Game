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

void Player::update(const float& dt, const USER_INPUTS& userInput, const USER_INPUTS& preInput)
{
	int pre_dir_x = preInput.arrowRight ? 1 : preInput.arrowLeft ? -1 : 0;
	int pre_dir_y = preInput.arrowUp ? -1 : 1;

	int dir_x = userInput.arrowRight ? 1 : userInput.arrowLeft ? -1 : 0;
	int dir_y = userInput.arrowDown ? 1 : userInput.arrowUp ? -1 : 0;
	/*std::cout << " dir_x in player " << dir_x << "\n";
	std::cout << " dir_y in player " << dir_y << "\n";*/

	if (userInput.MousePress)
		this->attack(dt,pre_dir_x,pre_dir_y);
	else if ( dir_x || dir_y)
		this->move(dt, dir_x, dir_y);
	else
		animations->run("wait_front",dt);
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

}

void Player::attack(const float& dt, int dir_x, int dir_y)
{

	// attack animation goes here
	animations->run("attack_front",dt);
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

