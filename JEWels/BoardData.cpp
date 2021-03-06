﻿#include "stdafx.h"
#include "BoardData.h"
#include "Helpers.h"
#include <iostream>

using namespace sf;
using namespace Constants;
using namespace helpers;

Direction directions[4] = {
	Direction(1, -1), // ↗
	Direction(1, 0),  // →
	Direction(1, 1),  // ↘
	Direction(0, 1),  // ↓
};

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

void BoardData::moveGem(BoardIndex& gemIndex, int offset)
{
	if (offset < 1) return;

	Gem& gem = at(gemIndex);
	GemType type = gem.type;
	gem.type = GemType::Empty;
	set(type, gemIndex.x, gemIndex.y + offset);
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

bool BoardData::checkMatches()
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			Gem & gem = at(row, col);
			if (gem.isEmpty() || gem.forDestruction) continue;

			BoardIndex index(row, col);

			// for each direction
			for (int di = 0; di < 4; di++)
			{
				checkMatchThree(directions[di], gem, index);
			}
		}
	}

	return forDestroy.size() > 2;
}

bool BoardData::checkMatchThree(Direction & dir, Gem & currentGem, const BoardIndex & currentIndex) {
	// direction and boardIndex is aliases for Vector2i. So we just add direction vector to index vector
	BoardIndex nextIndex = currentIndex + dir.vector;
	BoardIndex secondIndex = nextIndex + dir.vector;

	if (no_needToCheckDirection(dir, currentIndex) || no_needToCheckDirection(dir, nextIndex))
		return false;

	Gem &nextGem = at(nextIndex);
	Gem &secondGem = at(secondIndex);

	if (nextGem.forDestruction || secondGem.forDestruction)
		return false;
	else if (currentGem.type != nextGem.type || currentGem.type != secondGem.type)
		return false;

	// we found 3-gems match!
	forDestroy.push_back(&currentGem);
	forDestroy.push_back(&nextGem);
	forDestroy.push_back(&secondGem);

	currentGem.markForDestruction();
	nextGem.markForDestruction();
	secondGem.markForDestruction();

	checkNextCell(dir, secondGem, secondIndex);
	return true;
}

void BoardData::checkNextCell(Direction & dir, Gem & currentGem, const BoardIndex & currentIndex)
{
	if (no_needToCheckDirection(dir, currentIndex))
		return;

	BoardIndex nextIndex = currentIndex + dir.vector;
	Gem &nextGem = at(nextIndex);

	if (nextGem.forDestruction || currentGem.type != nextGem.type)
		return;

	forDestroy.push_back(&nextGem);
	nextGem.markForDestruction();

	checkNextCell(dir, nextGem, nextIndex);
}


bool BoardData::performDestroy()
{
	int forDestroySize = forDestroy.size();
	bool isDestroyed = false;

	std::vector<Gem*>::iterator it;
	for (it = forDestroy.begin(); it != forDestroy.end(); it++) {
		Gem* gem = *it;
		if (forDestroySize > 2)
			gem->destroy();
		else
			gem->forDestruction = false;

		detectedBlocks++;
	}

	forDestroy.clear();

	if (detectedBlocks > 2)
		isDestroyed = true;
	else
		detectedBlocks = 0;
	
	return isDestroyed;
}

bool BoardData::performFalling()
{
	bool hasFallen = false;
	for (int row = 0; row < ROWS; row++)
	{
		int emptyBlocks = 0, blocks = 0;
		int startIndex, endIndex;

		// going from bottom to top this time
		for (int col = COLS-1; col > 0; col--)
		{
			Gem& currentGem = at(row, col);
			Gem& nextGem = at(row, col-1); // block ABOVE current

			// skip, if this is not empty block but it should not fall
			if (emptyBlocks == 0 && !currentGem.isEmpty())
				continue;

			if (!currentGem.isEmpty()) {
				blocks++;
				if (blocks == 1) {
					startIndex = col;
				}
			}
			else {
				emptyBlocks++;
			}

			if (nextGem.isEmpty() && blocks > 0) {
				endIndex = col;
				break;
			}
		}

		if (blocks == 0) continue;

		for (int i = 0; i < blocks; i++) {
			moveGem(BoardIndex(row, startIndex - i), emptyBlocks);
		}
		hasFallen = true;
	}
	return hasFallen;
}

bool BoardData::no_needToCheckDirection(const Direction & dir, const BoardIndex & gemIndex) {
	return
		gemIndex.x == 0 && dir.vector.x < 0 ||
		gemIndex.x == (ROWS - 1) && dir.vector.x > 0 ||
		gemIndex.y == (COLS - 1) && dir.vector.y > 0 ||
		gemIndex.y == 0 && dir.vector.y < 0;
}

BoardData::~BoardData()
{
}


