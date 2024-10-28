#ifndef GAME_H
#define GAME_H

#include "Game_State.h"

class Game
{
private:
	
	//variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock deltaClock;
	float deltaTime;
	std::stack<State*> states;


	// initailization
	void initializeWindow();
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
