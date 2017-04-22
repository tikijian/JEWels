#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include "TextureManager.h"
#include "Board.h"
#include "Score.h"
#include "Gem.h"
#include "Block.h"

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
	//sprJew.setTexture(tm.get("jew.png"));
	sprJew.setPosition(35, 50);
	sprJew.setScale(0.3f, 0.3f);

	Board board(&window);	
	Score score;

	Block block;

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

		block.update(&dt);
		//-----------


		/*---------*/
		// Rendering
		/*---------*/	
		window.clear(sf::Color::Black);

		window.draw(sprJew);
		board.render();
		window.draw(score.formatted());
		block.render(&window);
		window.display();
		//-----------
	}

    return 0;
}

