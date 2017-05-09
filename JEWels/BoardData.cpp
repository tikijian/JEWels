#include "stdafx.h"
#include "BoardData.h"


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

	data[2][5] = GemType::Red;
	data[2][6] = GemType::Red;
	data[2][7] = GemType::Red;
	data[2][8] = GemType::Red;
	data[2][9] = GemType::Red;
	data[2][10] = GemType::Red;
	
	data[7][9] = GemType::Blue;
	data[7][10] = GemType::Blue;
	data[7][11] = GemType::Blue;
	data[7][12] = GemType::Blue;
	data[7][13] = GemType::Blue;
	data[7][14] = GemType::Blue;
}

void BoardData::reset()
{
	for (int row = 0; row < Constants::ROWS; row++)
	{
		for (int col = 0; col < Constants::COLS; col++)
		{
			set(GemType::Empty, row, col);
		}
	}
}

void BoardData::draw(sf::RenderTarget & target, sf::RenderStates states) const
{

}

BoardData::~BoardData()
{
}
