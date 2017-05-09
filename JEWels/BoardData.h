#pragma once
#include "Constants.h"
#include "GemTypes.h"
#include "SFML\Graphics.hpp"

class BoardData : sf::Drawable {
	GemType data[Constants::ROWS][Constants::COLS];
public:
	BoardData();
	BoardData(bool debug = false);
	~BoardData();

	GemType at(int x, int y) { return data[x][y]; }
	GemType at(sf::Vector2i index) { return data[index.x][index.y]; }
	void set(GemType t, int x, int y) { data[x][y] = t; }
	void set(GemType t, sf::Vector2i index) { data[index.x][index.y] = t; }
	void reset();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;
};
