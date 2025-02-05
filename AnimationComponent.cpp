#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(sf::Sprite* sprite, sf::Texture* texture):sprite(sprite), texture(texture)
{
	sprite->setTexture(*texture);
}

AnimationComponent::~AnimationComponent()
{
	for (auto& animation : animations)
		delete animation.second;
}

void AnimationComponent::createAnimation(const std::string& name, int startFrame, int endFrame, int row, int width, int height, float updateTimeBound, int priority)
{
	animations.emplace(name, new Animation(startFrame, endFrame, row, width, height, updateTimeBound,priority));
}

void AnimationComponent::run(const std::string& name, const float& dt)
{
	animations.at(name)->run(dt, this->sprite);
}

void AnimationComponent::reset(const std::string& name)
{
	animations.at(name)->setCurrentFrame(0);
}

void AnimationComponent::initializeAnimation(std::string name, sf::Sprite* sprite)
{
	animations.at(name)->initializeAnimation(sprite);
}


// Animation Class

AnimationComponent::Animation::Animation(int startFrame, int endFrame, int row, int width, int height, float updateTimeBound, int priority):
startFrame(startFrame), endFrame(endFrame), row(row), width(width),height(height),updateTimeBound(updateTimeBound), priority(priority)
{
	animationTime = 0.f;
	currentFrame = startFrame;
}

AnimationComponent::Animation::~Animation()
{
}


void AnimationComponent::Animation::initializeAnimation(sf::Sprite* sprite)
{
	sprite->setTextureRect(sf::IntRect(0, row * height, width, height));
}

void AnimationComponent::Animation::run(const float& dt,sf::Sprite* sprite)
{
	this->animationTime += dt * 1000;
	std::cout << "animation time = " << animationTime << "\n";
	//std::cout << "Delta time = " << dt << "\n";
	//std::cout << "current frame = " << currentFrame << "\n";
	if (animationTime >= 100)
	{
		animationTime = 0;
		sprite->setTextureRect(sf::IntRect(currentFrame * width, row * height, width, height));
		currentFrame++;
		if (currentFrame == endFrame + 1)
			currentFrame = startFrame;
		//std::cout << "current frame = " << currentFrame << "\n";
		std::cout << "position = " << sprite->getPosition().x << "  " << sprite->getPosition().y << "\n";
	}
}


int AnimationComponent::Animation::getCurrentFrame() const
{
	return currentFrame;
}

void AnimationComponent::Animation::setCurrentFrame(int frame)
{
	currentFrame = frame;
}

const int& AnimationComponent::Animation::getPrority() const
{
	return this->priority;
}

const bool AnimationComponent::Animation::isFinished() const
{
	return currentFrame == endFrame;
}
