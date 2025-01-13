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
	std::map<std::string, sf::Keyboard::Key>* available_keys;
	std::map<std::string, sf::Keyboard::Key> key_binds;
	sf::Vector2i mousePositionWindow;
	std::stack<State*>* states;

	// to set keybinds for each state
	virtual void setKeyBinds() = 0;
	virtual void updateMousePositionWindow(sf::RenderWindow* CurrentWindow);

public:
	
	State(sf::RenderWindow* window,std::map<std::string, sf::Keyboard::Key>* available_keys, std::stack<State*>* states);
	
	virtual ~State();

	void setQuit(bool state);
	const bool& getQuit();

	virtual void render(sf::RenderWindow* target = nullptr ) = 0;
	virtual void update(const float& dt) = 0;

	// SAVE STATE
	virtual void endState() = 0;

	virtual void updateInputs(const float& dt) = 0;

};

#endif