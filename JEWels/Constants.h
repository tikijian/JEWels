#pragma once
#include "SFML\Graphics.hpp"


namespace Constants
{
	const sf::Vector2f TOPLEFT(230, 65);
	const sf::Vector2f BOARDSIZE(520, 680);
	const sf::Vector2f BOTTOMRIGHT = TOPLEFT + BOARDSIZE;
	const float GEMSIZE = 40;
	const int ROWS = 13;
	const int COLS = 17;
	const float STEP = 40.0f;
	const float BLOCK_HEIGHT = 120.0f;
};
