#ifndef GAME_H
#define GAME_H

#include "Game_State.h"
#include "MainMenuState.h"

class Game
{
private:
	
	//variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock deltaClock;
	float deltaTime;
	std::stack<State*> states;
	std::map<std::string, sf::Keyboard::Key> available_keys;

	// initailization
	void initializeWindow();
	void initializeKeys();
	void initialState();

public:

	Game();
	~Game();


	//game functions
	void updateSFEvent();
	void updateDeltaTime();
	void update();
	void render();
	void run();


};

#endif
