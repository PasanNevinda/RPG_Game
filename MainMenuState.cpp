#include "MainMenuState.h"


MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* available_keys, std::stack<State*>* states) :State(window, available_keys,states)
{

	setKeyBinds();
	initFont();
	initButtons();
	background.setSize(static_cast<const sf::Vector2f>(window->getSize()));
	background.setFillColor(sf::Color(255, 255, 255, 100));
	background.setPosition(0, 0); 
} 

MainMenuState::~MainMenuState()
{
	for (auto& pair : buttons)
	{
		delete pair.second;
	}
}

void MainMenuState::setKeyBinds()
{
	//key_binds["QUIT"] = sf::Keyboard::Key::Escape;
	
}

void MainMenuState::initFont()
{
	if (!font.loadFromFile("Fonts/JungleAdventurer.ttf"))
	{
		std::cout << "error in loading fonts\n";
	}
}

void MainMenuState::initButtons()
{
	Button* newGame =  new Button(sf::RectangleShape(sf::Vector2f(400, 40)), &font, "New Game", sf::Color::Green, sf::Color::Red, sf::Color::Blue);
	Button* exitGame = new Button(sf::RectangleShape(sf::Vector2f(400, 40)), &font, "Quit", sf::Color::Green, sf::Color::Red, sf::Color::Blue);
	newGame->setPosition(window->getSize().x*0.5 - newGame->getSize().x*0.5, window->getSize().y*0.3);
	exitGame->setPosition(window->getSize().x * 0.5 - newGame->getSize().x * 0.5, window->getSize().y * 0.3 + newGame->getSize().y + 20);
	buttons.emplace("New Game",newGame);
	buttons.emplace("Quit", exitGame);
}

void MainMenuState::update(const float& dt)
{
	updateMousePositionWindow(window);
	updateInputs(dt);	

}

void MainMenuState::render(sf::RenderWindow* target)
{
	if (!target)
		target = this->window;

	target->draw(background);
	for (auto& pair : buttons)
	{
		pair.second->render(target);
	}
}

void MainMenuState::endState()
{
}

void MainMenuState::updateInputs(const float& dt) // this may not need dt
{
	// update buttons and manage states
	for (auto& pair : buttons)
	{
		pair.second->update(mousePositionWindow);
	}
	if (buttons.at("New Game")->isPressed())
		states->push(new Game_State(window, available_keys, states));

	if (buttons.at("Quit")->isPressed())
		setQuit(true);
	else
		setQuit(false);
}
