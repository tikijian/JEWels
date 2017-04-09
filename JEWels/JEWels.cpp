#include "stdafx.h"
#include <SFML\Graphics.hpp>

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 800), "JEWels");
	window.setFramerateLimit(30);

	sf::Texture texJew;
	texJew.loadFromFile("graphics/jew.png");
	sf::Sprite sprJew;
	sprJew.setTexture(texJew);
	sprJew.setPosition(0, 0);
	sprJew.setScale(0.3f, 0.3f);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}

		window.clear(sf::Color::Black);

		window.draw(sprJew);

		window.display();
	}

    return 0;
}

