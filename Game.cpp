#include "Game.h"


// initailization
void Game::initializeWindow()
{
	window = new sf::RenderWindow();
	std::string title = "None";
	sf::VideoMode video_mode(1200, 800);
	unsigned framerate = 120;
	bool vertical_synced = false;

	//open the file and read data
	std::fstream file("Config/window.ini");
	if (file)
	{
		std::getline(file, title);
		file >> video_mode.width >> video_mode.height;
		file >> framerate;
		file >> vertical_synced;
	}

	window->create(video_mode, title);
	window->setFramerateLimit(framerate);
	window->setVerticalSyncEnabled(vertical_synced);

}

void Game::initialState()
{
	states.push(new Game_State(window));
}

Game::Game()
{
	initializeWindow();
	initialState();
}

Game::~Game()
{
	delete window;
	while (!states.empty())
	{
		delete states.top();
		states.pop();
	}
}



// game functions

//  to handle sf event: call it in update
void Game::updateSFEvent()
{

}

// to mesure time per frame
void Game::updateDeltaTime()
{
	deltaTime = deltaClock.restart().asSeconds();
}

// update the game
void Game::update()
{
	updateSFEvent();

	if (!states.empty())
	{
		states.top()->update(deltaTime);

		if (states.top()->getQuit())
		{
			states.top()->endState(); // to save state
			delete states.top();
			states.pop();
		}
	}

	// end the game if no states quit the game
	else
	{
		window->close();
	}
	
}


// render the game
void Game::render()
{
	window->clear();

	// do drawings
	if (!states.empty())
	{
		states.top()->render();
	}
	

	window->display();
}

void Game::run()
{
	event = {};
	while (window->isOpen())
	{
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		updateDeltaTime();

		update();

		render();
	}
}
