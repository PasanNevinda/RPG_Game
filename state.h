#ifndef STATE_H 
#define STATE_H

#include "Entity.h"

class State
{

private:
	// array or something to hold resources for a state
	bool quit;

protected:
	sf::RenderWindow* window;

public:
	
	State(sf::RenderWindow* window);
	
	virtual ~State();

	virtual	void checkForQuit();
	const bool& getQuit();

	virtual void render(sf::RenderWindow* target = nullptr ) = 0;
	virtual void update(const float& dt) = 0;

	// SAVE STATE
	virtual void endState() = 0;

	virtual void updateKeybinds(const float& dt) = 0;

};

#endif