#pragma once
#include <SFML\Graphics.hpp>

class Board
{
public:
	Board(sf::RenderWindow* wnd);
	~Board();

	sf::RenderWindow* window;
	sf::RectangleShape rect;
	void render();
};

