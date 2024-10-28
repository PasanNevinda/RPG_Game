#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "state.h"
class Game_State : public State
{

private:
	Entity player;

public:

	Game_State(sf::RenderWindow* window);
	virtual ~Game_State();

	void render(sf::RenderWindow* target = nullptr);
	void update(const float& dt);
	void endState();
	void updateKeybinds(const float& dt);

};

#endif