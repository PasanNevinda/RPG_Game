#include "Game_State.h"

Game_State::Game_State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys, std::stack<State*>* states):State(window,available_keys,states)
{
	setKeyBinds();
	initTextures();
	player = new Player(sf::Vector2f(20, 30), sf::Vector2f(200, 50), textures.at("PLAYER"));
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
	player->update(dt,userInputs.MousePress,userInputs.arrowUp,userInputs.arrowDown,userInputs.arrowRight,userInputs.arrowLeft); 
	updateMousePositionWindow(window);
}

void Game_State::render(sf::RenderWindow* target) 
{
	if (!target)
		target = this->window;
	
	player->render(target);
}

void Game_State::endState()
{
}

void Game_State::updateInputs(const float& dt)
{
	//check for quit
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		setQuit(true);

	userInputs.MousePress = sf::Mouse::isButtonPressed(sf::Mouse::Left);

	userInputs.arrowLeft = sf::Keyboard::isKeyPressed(key_binds.at("MOVE_LEFT"));
		
	userInputs.arrowRight = sf::Keyboard::isKeyPressed(key_binds.at("MOVE_RIGHT"));

	userInputs.arrowDown = sf::Keyboard::isKeyPressed(key_binds.at("MOVE_DOWN"));

	userInputs.arrowUp = sf::Keyboard::isKeyPressed(key_binds.at("MOVE_UP"));
}

void Game_State::initTextures()
{
	sf::Texture* t = new sf::Texture();
	if (!t->loadFromFile("Resources/Textures/Player/player.png"))
		throw "error in loading PLAYER_NINJA_TEXTURE";
	textures.emplace("PLAYER", t);
}
