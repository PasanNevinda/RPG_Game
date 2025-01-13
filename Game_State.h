#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "state.h"
class Game_State : public State
{

private:
	Entity player;

	void setKeyBinds();


public:

	Game_State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys, std::stack<State*>* states);
	virtual ~Game_State();


	void render(sf::RenderWindow* target = nullptr);
	void update(const float& dt);
	void endState();
	void updateInputs(const float& dt);

};

#endif