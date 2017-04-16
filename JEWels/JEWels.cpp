#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "TextureManager.h"
#include "Board.h"
#include "Score.h"

using namespace std;

int main()
{
	sf::Image icon;
	icon.loadFromFile("graphics/icon.png");
	int windowStyle = !sf::Style::Resize | sf::Style::Titlebar | sf::Style::Close;
	sf::RenderWindow window(sf::VideoMode(800, 800), "JEWels", windowStyle);
	window.setFramerateLimit(30);
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	TextureManager tm;
	tm.initialize();
	
	sf::Sprite sprJew;
	sprJew.setTexture(tm.textures["jew.png"]); //TODO: why not tm.get()
	sprJew.setPosition(35, 50);
	sprJew.setScale(0.3f, 0.3f);

	sf::RectangleShape rect;
	rect.setFillColor(sf::Color::Red);
	rect.setSize(sf::Vector2f(40.0f, 40.0f));
	rect.setPosition(300, 300);

	Board board(&window);
	Score score;

	sf::Clock clock;
	int stepTime = 0;
	int stepDuration = 1000;
 
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

		/*---------*/
		// Updates
		/*---------*/
		sf::Time dt = clock.restart();

		stepTime += dt.asMilliseconds();
		if (stepTime >= stepDuration) {
			// TODO: move down
			rect.setPosition(rect.getPosition() + sf::Vector2f(.0f, 40.0f));
			stepTime = 0;
		}

		//-----------


		/*---------*/
		// Rendering
		/*---------*/	
		window.clear(sf::Color::Black);

		window.draw(sprJew);
		board.render();
		window.draw(rect); 
		window.draw(score.formatted());

		window.display();
		//-----------
	}

    return 0;
}

