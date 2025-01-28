#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "state.h"
#include "Player.h"

typedef struct {
	bool MousePress;
	bool arrowUp;
	bool arrowDown;
	bool arrowLeft;
	bool arrowRight;
} USER_INPUTS;

class Game_State : public State
{

private:
	Player* player; // player shoud have sprite, animationComponent, MovementComponent <- pass player sprite to them for update and render
	void setKeyBinds();
	std::map<std::string, sf::Texture*> textures;
	USER_INPUTS userInputs;

public:

	Game_State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys, std::stack<State*>* states);
	virtual ~Game_State();


	void render(sf::RenderWindow* target = nullptr);
	void update(const float& dt);
	void endState();
	void updateInputs(const float& dt);
	void initTextures();

};

#endif