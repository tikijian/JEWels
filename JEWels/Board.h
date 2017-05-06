#pragma once
#include <SFML\Graphics.hpp>
#include "GemTypes.h"
#include "Gem.h"
#include "Block.h"
#include "Constants.h"

using namespace sf;

class Board : public sf::Drawable
{
	void resetBoard();

public:
	static Vector2i getBoardIndex(const Vector2f & coords);

	Board();
	~Board();

	sf::RectangleShape rect;
	GemType board[13][17];

	void update(const Time &dt);
	void commitBlock(Block &block);
	virtual void draw(RenderTarget & target, RenderStates states) const;
};

