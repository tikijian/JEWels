#include "stdafx.h"
#include "BoardData.h"
#include "Helpers.h"

using namespace Constants;
using namespace helpers;

BoardData::BoardData()
{
	reset();
}

BoardData::BoardData(bool debug)
{
	reset();
	if (!debug) {
		return;
	}

	set(GemType::Red, 1, 16);
	set(GemType::Blue, 1, 15);
	set(GemType::Yellow, 1, 14);
	set(GemType::Red, 1, 13);
	set(GemType::Red, 2, 16);
	set(GemType::Green, 2, 15);
	set(GemType::Yellow, 2, 14);
	set(GemType::Blue, 3, 16);
	set(GemType::Magenta, 3, 15);
	set(GemType::Yellow, 4, 16);
	set(GemType::Green, 8, 10);
}

void BoardData::reset()
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			set(GemType::Empty, row, col);
			sf::Vector2f position = getScreenCoords(sf::Vector2i(row, col));
			at(row, col).setPosition(position);
		}
	}
}

void BoardData::set(GemType type, int x, int y)
{
	at(x, y).setType(type);
}

void BoardData::set(GemType type, const sf::Vector2i & index)
{
	at(index).setType(type);
}

void BoardData::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			target.draw(data[row][col]);
		}
	}
}

BoardData::~BoardData()
{
}
