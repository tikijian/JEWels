#include "stdafx.h"
#include "BoardData.h"
#include "Helpers.h"
#include <iostream>

using namespace sf;
using namespace Constants;
using namespace helpers;

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

bool no_needToCheckDirection(const Direction&, const BoardIndex&);

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

void BoardData::set(GemType type, const BoardIndex& index)
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
			if (gem.isEmpty() || gem.forDestruction) continue;

			BoardIndex index(row, col);

			//std::cout << "Cheking optimization - ----------- ---" << std::endl;
			// for each direction
			for (int di = 0; di < 8; di++)
			{
				//std::cout << "Position " << index.x << ":" << index.y << " no need? = " << no_needToCheckDirection(directions[di], index) << std::endl;
				// check if it is not necessary to call check procedure
				Direction & dir = directions[di];
				if (no_needToCheckDirection(dir, index))
					continue;

				checkNextCell(dir, gem, index);
				dir,detectedBlocks = 0;
			}
		}
	}
}

void BoardData::checkNextCell(Direction & dir, Gem & currentGem, const BoardIndex & currentIndex)
{
	// direction and boardIndex is aliases for Vector2i. So we just add direction vector to index vector
	BoardIndex nextIndex = currentIndex + dir.vector;
	Gem &nextGem = at(nextIndex);

	if (no_needToCheckDirection(dir, nextIndex))
		return;

	if (currentGem.type != nextGem.type || nextGem.forDestruction)
		return;

	dir.detectedBlocks += 1;

	if (dir.detectedBlocks == 3) {
		BoardIndex prevIndex = (currentIndex + (-dir.vector));
		Gem &prevGem = at(prevIndex);
		// TODO: Create new Match and match.push_back;
		forDestroy.push_back(&currentGem);
		forDestroy.push_back(&prevGem);
		forDestroy.push_back(&nextGem);

		currentGem.markForDestruction();
		prevGem.markForDestruction();
		nextGem.markForDestruction();
	} 
	else if (dir.detectedBlocks > 3) {
		forDestroy.push_back(&nextGem);
		nextGem.markForDestruction();
	}

	checkNextCell(dir, nextGem, nextIndex);
}

void BoardData::performDestroy()
{
	int forDestroySize = forDestroy.size();
	std::cout << "forDestroy size  = " << forDestroySize << std::endl;

	std::vector<Gem*>::iterator it;
	for (it = forDestroy.begin(); it != forDestroy.end(); it++) {
		Gem* gem = *it;
		if (forDestroySize > 2)
			gem->destroy();
		else
			gem->forDestruction = false;
	}

	forDestroy.clear();

	//for (int row = 0; row < ROWS; row++)
	//{
	//	for (int col = 0; col < COLS; col++)
	//	{
	//		Gem & gem = at(row, col);
	//		if (gem.forDestruction) {
	//			std::cout << "calling destroy on gem " << (int)gem.type << std::endl;
	//			gem.destroy();
	//		}
	//	}
	//}
}

void BoardData::update()
{
	checkMatches();
	performDestroy();
}

// Some helper functions for decomposition
bool no_needToCheckDirection(const Direction & dir, const BoardIndex & gemIndex) {
	return
		gemIndex.x == 0 && dir.vector.x < 0 ||
		gemIndex.x == (ROWS - 1) && dir.vector.x > 0 ||
		gemIndex.y == 0 && dir.vector.y < 0 ||
		gemIndex.y == (COLS - 1) && dir.vector.y > 0;
}

BoardData::~BoardData()
{
}


