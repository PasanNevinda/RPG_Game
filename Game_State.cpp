#include "Game_State.h"

Game_State::Game_State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys, std::stack<State*>* states) :
	State(window, available_keys, states),
	test1(sf::Vector2f(50, 50)), test2(sf::Vector2f(400, 400)), test3(sf::Vector2f(20, 20))
{
	setKeyBinds();
	initTextures();
	initPauseMenu();
	player = new Player(sf::Vector2f(400,400), sf::Vector2f(300,300), textures.at("PLAYER"));



	// Tests
	text.setPosition(1000, 50);
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::Cyan);

	if (!font.loadFromFile("Fonts/JungleAdventurer.ttf"))
	{
		std::cout << "error in loading fonts\n";
	}
	text.setFont(font);

	//test1.setPosition(400, 400);
	test2.setPosition(20, 30);
	test2.setOutlineColor(sf::Color::Blue);
	test2.setOutlineThickness(5);
	//test1.setFillColor(sf::Color::Blue);
	test2.setFillColor(sf::Color::Transparent);
	////test2.setScale(2, 2);
	//test1.setSize(sf::Vector2f(test2.getLocalBounds().width, 50));
	//test3.setFillColor(sf::Color::Red);
	//test3.setPosition(test1.getPosition());
}

Game_State::~Game_State()
{
	for (auto& texture : textures)
		delete texture.second;
}

void Game_State::setKeyBinds()
{
	std::ifstream file("Config/game_state_keys.ini");
	if (file)
	{
		std::string key_name;
		int key;
		while (file >> key_name >> key)
		{
			key_binds[key_name] = sf::Keyboard::Key(key);
		}
	}
	file.close();
}

void Game_State::update(const float& dt)
{
	updatePause(dt);
	updateInputs(dt);
	player->update(dt);
	updateMousePositionWindow(window);
}

void Game_State::render(sf::RenderWindow* target) 
{
	if (!target)
		target = this->window;
	
	player->render(target);

	if (this->pause)
		pausemenu->render(target);

	// Tests
	target->draw(test2);

	std::stringstream ss;
	ss << "Mouse Position = " << mousePositionWindow.x << ", " << mousePositionWindow.y;
	text.setString(ss.str());
	target->draw(text);
	//target->draw(test1);
	//target->draw(test3);

}

void Game_State::endState()
{
}

void Game_State::updateInputs(const float& dt)
{
	if(!this->pause)
		updatePlayerInputs(dt);

}

void Game_State::updatePlayerInputs(const float& dt)
{
	static previousDirection preDir = previousDirection::front;
	bool nokeyPressed = true;


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		player->attack(dt, preDir);
	}


	else
	{
		if (sf::Keyboard::isKeyPressed(key_binds.at("MOVE_LEFT")))
		{
			player->move(dt, -1, 0);
			nokeyPressed = false;
			preDir = previousDirection::left;
		}

		if (sf::Keyboard::isKeyPressed(key_binds.at("MOVE_RIGHT")))
		{
			player->move(dt, 1, 0);
			nokeyPressed = false;
			preDir = previousDirection::right;
		}

		if (sf::Keyboard::isKeyPressed(key_binds.at("MOVE_DOWN")))
		{
			player->move(dt, 0, 1);
			nokeyPressed = false;
			preDir = previousDirection::front;
		}

		if (sf::Keyboard::isKeyPressed(key_binds.at("MOVE_UP")))
		{
			player->move(dt, 0, -1);
			nokeyPressed = false;
			preDir = previousDirection::up;
		}

		if (nokeyPressed)
			player->wait(dt, preDir);
	}
	player->update(dt);
}

void Game_State::initTextures()
{
	sf::Texture* t = new sf::Texture();
	if (!t->loadFromFile("Resources/Textures/Player/player.png"))
		throw "error in loading PLAYER_NINJA_TEXTURE";
	textures.emplace("PLAYER", t);
}

void Game_State::initPauseMenu()
{
	pausemenu = new PauseMenu(sf::RectangleShape(sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y)), sf::Color::Magenta,
		sf::Vector2f(this->window->getSize().x / 4, 0), 100);
}

void Game_State::updatePause(float dt)
{
	this->pause = pausemenu->getShouldPause(dt);
}



