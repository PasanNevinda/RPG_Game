#include "Game.h"

// Test
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
// End Test

int main()
{
	
	Game game;

	game.run();
	
	/*
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "View Test");
	sf::RectangleShape player(sf::Vector2f(100, 100));
	player.setPosition(960,540);
	sf::CircleShape enemy(40);
	sf::View playerView;
	playerView.setCenter(player.getPosition());
	playerView.setSize(static_cast<sf::Vector2f>(window.getSize()));
	sf::RectangleShape ui(sf::Vector2f(1920, 50));
	ui.setFillColor(sf::Color::Cyan);
	sf::RectangleShape background(sf::Vector2f(1920, 1080));
	sf::Texture texture;

	if (!texture.loadFromFile("test_texture.jpg"))
		std::cout << "error";
	background.setTexture(&texture);

	player.setFillColor(sf::Color::Green);
	enemy.setFillColor(sf::Color::Red);
	

	while (window.isOpen())
	{
		sf::Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		// update
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			player.move(-0.5, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			player.move(0.5, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			player.move(0, 0.5);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			player.move(0, -0.5);
		playerView.setCenter(player.getPosition());

		// render

		window.setView(playerView);
		window.draw(background);
		window.draw(player);
		window.draw(enemy);

		window.setView(window.getDefaultView());
		window.draw(ui);

		window.display();

	}
	*/
}
