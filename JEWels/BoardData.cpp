#include "stdafx.h"
#include "BoardData.h"
#include "Helpers.h"
#include <iostream>

using namespace sf;
using namespace Constants;
using namespace helpers;

typedef Vector2i Direction;
Direction directions[8] = {
	Direction(0, -1), // ↑
	Direction(1, -1), // ↗
	Direction(1, 0),  // →
	Direction(1, 1),  // ↘
	Direction(0, 1),  // ↓
	Direction(-1, 1), // ↙ 
	Direction(-1, 0), // ←
	Direction(-1, -1),// ↖ 
};

bool no_needToCheckDirection(const Direction&, const Vector2i&);
void checkNextCell(const Direction&, const Vector2i&);

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
			Vector2f position = getScreenCoords(Vector2i(row, col));
			at(row, col).setPosition(position);
		}
	}
}

void BoardData::set(GemType type, int x, int y)
{
	at(x, y).setType(type);
}

void BoardData::set(GemType type, const Vector2i & index)
{
	at(index).setType(type);
}

void BoardData::draw(RenderTarget & target, RenderStates states) const
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			target.draw(data[row][col]);
		}
	}
}

void BoardData::checkMatches()
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			Gem & gem = at(row, col);
			if (gem.isEmpty()) continue;

			Vector2i index(row, col);

			//std::cout << "Cheking optimization - ----------- ---" << std::endl;
			for (int di = 0; di < 8; di++)
			{
				//std::cout << "Position " << index.x << ":" << index.y << " no need? = " << no_needToCheckDirection(directions[di], index) << std::endl;
				if (no_needToCheckDirection(directions[di], index))
					continue;


			}

		}
	}
}

BoardData::~BoardData()
{
}


// Some helper functions for decomposition

bool no_needToCheckDirection(const Direction& dir, const Vector2i& gemIndex) {
	return
		gemIndex.x == 0 && dir.x < 0 ||
		gemIndex.x == (ROWS - 1) && dir.x > 0 ||
		gemIndex.y == 0 && dir.y < 0 ||
		gemIndex.y == (COLS - 1) && dir.y > 0;
}

void checkNextCell(const Direction& dir, const Vector2i& gemIndex)
{

}