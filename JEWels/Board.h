#pragma once
#include <SFML\Graphics.hpp>
#include "GemTypes.h"
#include "Gem.h"
#include "Block.h"
#include "Constants.h"
#include "Score.h"
#include "Helpers.h"
#include "BoardData.h"

using namespace sf;

class Board : public sf::Drawable
{
public:
	Board();
	~Board();

	sf::RectangleShape rect;
	Block block;
	Score score;
	BoardData board;

	void update(const Time &dt);
	void resetBoard() { board.reset(); };
	virtual void draw(RenderTarget & target, RenderStates states) const;
};

