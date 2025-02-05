#ifndef ANIMATION_COMPONENT_H
#define ANIMATION_COMPONENT_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

class AnimationComponent
{
private:
	sf::Sprite* sprite;
	sf::Texture* texture;
	class Animation;
	std::map<std::string, Animation*> animations;
	

public:
	AnimationComponent(sf::Sprite* sprite, sf::Texture* texture);
	~AnimationComponent();

	void createAnimation(const std::string& name, int startFrame, int endFrame, int row, int width, int height, float updateTimeBound, int priority);
	void run(const std::string& name,const float& dt);
	void reset(const std::string& name);
	void initializeAnimation(std::string name, sf::Sprite* sprite);
	
};



class AnimationComponent::Animation
{
private:
	const int startFrame, endFrame, row, width, height;
	int currentFrame;
	float animationTime;  // spend time 
	float updateTimeBound;  // time required to update animation
	int priority;

public:
	Animation(int startFrame, int endFrame, int row, int width, int height, float updateTimeBound, int priority);
	~Animation();

	void initializeAnimation(sf::Sprite* sprite);
	void run(const float& dt, sf::Sprite* sprite);
	int getCurrentFrame() const;
	void setCurrentFrame(int frame);
	const int& getPrority() const;
	const bool isFinished() const;
};

#endif