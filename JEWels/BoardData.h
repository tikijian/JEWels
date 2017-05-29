#pragma once
#include "Constants.h"
#include "GemTypes.h"
#include "SFML/Graphics.hpp"
#include "Gem.h"

class BoardData : public sf::Drawable {
	Gem data[Constants::ROWS][Constants::COLS];
public:
	BoardData();
	BoardData(bool debug = false);
	~BoardData();

	Gem & at(int x, int y) { return data[x][y]; }
	Gem & at(const sf::Vector2i &index) { return data[index.x][index.y]; }
	void set(GemType t, int x, int y);
	void set(GemType t, const sf::Vector2i & index);
	void reset();

	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;
};
