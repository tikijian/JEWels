#include "stdafx.h"
#include "Helpers.h"

using namespace Constants;

sf::Vector2i helpers::getBoardIndex(const sf::Vector2f & coords)
{
	int x = (int)((coords.x - TOPLEFT.x) / GEMSIZE);
	int y = (int)((coords.y - TOPLEFT.y) / GEMSIZE);
	return sf::Vector2i(x, y);
}

sf::Vector2f helpers::getScreenCoords(const sf::Vector2i & index)
{
	float x = TOPLEFT.x + (index.x * GEMSIZE);
	float y = TOPLEFT.y + (index.y * GEMSIZE);
	return sf::Vector2f(x, y);
}
