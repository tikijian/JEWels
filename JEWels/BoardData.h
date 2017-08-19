#pragma once
#include <vector>
#include <algorithm>
#include "Constants.h"
#include "GemTypes.h"
#include "SFML\Graphics.hpp"
#include "Gem.h"

typedef sf::Vector2i BoardIndex;

struct Direction {
	Direction(int x, int y) { vector.x = x; vector.y = y; }
	sf::Vector2i vector;
};

class BoardData : public sf::Drawable {
	Gem data[Constants::ROWS][Constants::COLS];
	std::vector<Gem*> forDestroy; // COLS * ROWS = 221
	int detectedBlocks = 0;

	void checkNextCell(Direction&, Gem&, const BoardIndex&);
	bool checkMatchThree(Direction&, Gem&, const BoardIndex&);
	void performDestroy();

	static bool no_needToCheckDirection(const Direction&, const BoardIndex&);
public:
	BoardData();
	BoardData(bool debug = false);
	~BoardData();

	Gem & at(int x, int y) { return data[x][y]; }
	Gem & at(const BoardIndex & index) { return data[index.x][index.y]; }
	void set(GemType t, int x, int y);
	void set(GemType t, const BoardIndex & index);
	void reset();
	void update();
	void checkMatches();
	void performFalling();
	void resetDetectedCounter() { detectedBlocks = 0; }
	int getDetectedBlocks() { return detectedBlocks; }
	void moveGem(BoardIndex&, int offset);

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};
