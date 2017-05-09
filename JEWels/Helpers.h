#pragma once
#include "SFML\Graphics.hpp"
#include "Constants.h"

namespace helpers
{
	sf::Vector2i getBoardIndex(const sf::Vector2f & coords);
}