#ifndef STATE_H 
#define STATE_H

#include "Entity.h"

class State
{

private:
	// array or something to hold resources for a state
	bool quit;

	// to set keybinds for each state
	virtual void setKeyBinds() = 0;


protected:
	sf::RenderWindow* window;
	std::map<std::string, sf::Keyboard::Key>* available_keys;
	std::map<std::string, sf::Keyboard::Key> key_binds;

public:
	
	State(sf::RenderWindow* window,std::map<std::string, sf::Keyboard::Key>* available_keys);
	
	virtual ~State();

	virtual	void checkQuit();
	const bool& getQuit();
	

	virtual void render(sf::RenderWindow* target = nullptr ) = 0;
	virtual void update(const float& dt) = 0;

	// SAVE STATE
	virtual void endState() = 0;

	virtual void updateInputs(const float& dt) = 0;

};

#endif