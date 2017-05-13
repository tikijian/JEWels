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

	set(GemType::Red, 3, 5);
	set(GemType::Blue, 3, 6);
	set(GemType::Yellow, 3, 7);
	set(GemType::Red, 3, 8);
	set(GemType::Red, 3, 9);
	set(GemType::Red, 6, 10);
	set(GemType::Red, 6, 11);
	set(GemType::Blue, 6, 12);
	set(GemType::Magenta, 6, 13);
	set(GemType::Yellow, 6, 14);
	set(GemType::Green, 6, 15);
}

void BoardData::reset()
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			set(GemType::Empty, row, col);
		}
	}
}

void BoardData::set(GemType type, int x, int y)
{
	Gem gem(type);
	gem.rect.setPosition( getScreenCoords(sf::Vector2i(x, y)) );
	data[x][y] = gem;
}

void BoardData::set(GemType type, sf::Vector2i index)
{
	Gem gem(type);
	gem.rect.setPosition( getScreenCoords(index) );
	data[index.x][index.y] = gem;
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
