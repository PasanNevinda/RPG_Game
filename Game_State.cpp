#include "Game_State.h"

Game_State::Game_State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys, std::stack<State*>* states):State(window,available_keys,states),
	test1(sf::Vector2f(50, 50)), test2(sf::Vector2f(400, 400)), test3(sf::Vector2f(20, 20))
{
	setKeyBinds();
	initTextures();
	player = new Player(sf::Vector2f(400,400), sf::Vector2f(300,300), textures.at("PLAYER"));
	this->priviousInputs = { 0,0,0,0,0 };



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
	updateInputs(dt);
	player->update(dt,userInputs,priviousInputs); 
	updateMousePositionWindow(window);
}

void Game_State::render(sf::RenderWindow* target) 
{
	if (!target)
		target = this->window;
	
	player->render(target);

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
	//check for quit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		setQuit(true);

	USER_INPUTS temp = this->userInputs;

	userInputs.MousePress = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	userInputs.arrowLeft = sf::Keyboard::isKeyPressed(key_binds.at("MOVE_LEFT"));

	userInputs.arrowRight = sf::Keyboard::isKeyPressed(key_binds.at("MOVE_RIGHT"));

	userInputs.arrowDown = sf::Keyboard::isKeyPressed(key_binds.at("MOVE_DOWN"));

	userInputs.arrowUp = sf::Keyboard::isKeyPressed(key_binds.at("MOVE_UP"));

	if (userInputs.MousePress || userInputs.arrowLeft || userInputs.arrowRight || userInputs.arrowDown || userInputs.arrowUp)
		this->priviousInputs = temp;
}

void Game_State::initTextures()
{
	sf::Texture* t = new sf::Texture();
	if (!t->loadFromFile("Resources/Textures/Player/player.png"))
		throw "error in loading PLAYER_NINJA_TEXTURE";
	textures.emplace("PLAYER", t);
}
