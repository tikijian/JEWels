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
	int detectedBlocks = 0;
};

class BoardData : public sf::Drawable {
	Gem data[Constants::ROWS][Constants::COLS];
	std::vector<Gem*> forDestroy; // COLS * ROWS = 221
	int detectedBlocks = 1;

	void checkNextCell(Direction&, Gem&, const BoardIndex&);
	void performDestroy();
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

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};
