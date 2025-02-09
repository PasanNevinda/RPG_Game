#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "state.h"
#include "Player.h"
#include "GameStateData.h"

class Game_State : public State
{

private:
	Player* player; // player shoud have sprite, animationComponent, MovementComponent <- pass player sprite to them for update and render
	void setKeyBinds();
	std::map<std::string, sf::Texture*> textures;


	// Tests
	sf::Text text;
	sf::Font font;
	sf::RectangleShape test1;
	sf::RectangleShape test2;
	sf::RectangleShape test3;

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