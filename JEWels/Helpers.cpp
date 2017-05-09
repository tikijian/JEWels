#include "stdafx.h"
#include "Helpers.h"

using namespace Constants;

sf::Vector2i helpers::getBoardIndex(const sf::Vector2f & coords)
{
	int x = (int)((coords.x - TOPLEFT.x) / GEMSIZE);
	int y = (int)((coords.y - TOPLEFT.y) / GEMSIZE);
	return sf::Vector2i(x, y);
}
