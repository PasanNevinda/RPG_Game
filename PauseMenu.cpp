#include "PauseMenu.h"

PauseMenu::PauseMenu(sf::RectangleShape rectangle, sf::Color bgcolor, sf::Vector2f position, float refreshTime) :
    background(rectangle), refreshTime(refreshTime)
{
    background.setFillColor(bgcolor);
    background.setPosition(position);
    initFont();
}

PauseMenu::~PauseMenu()
{
    for (auto& val : buttons)
        delete val.second;
}

void PauseMenu::render(sf::RenderWindow* window)
{
    window->draw(background);
    for (auto& val : buttons)
        val.second->render(window);
}

void PauseMenu::initFont()
{
    if (!font.loadFromFile("Fonts/JungleAdventurer.ttf"))
    {
        std::cout << "error in loading fonts in PAUSE_MENU\n";
    }
}

void PauseMenu::setButton(std::string btnName, const sf::RectangleShape& shape, sf::Font* font, std::string textContent, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{

}

bool PauseMenu::getShouldPause(float dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && this->elapsedTime >= refreshTime)
    {
        this->shouldPauses = (!this->shouldPauses);
        this->elapsedTime = 0;
    }
    this->elapsedTime += dt * 1000;

    return shouldPauses;
}

bool PauseMenu::getButtonPressed(std::string btnName)
{
    return buttons.at(btnName)->isPressed();
}
