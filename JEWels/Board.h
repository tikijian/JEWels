#pragma once
#include <SFML\Graphics.hpp>
#include "GemTypes.h"

using namespace sf;

class Board : public sf::Drawable
{
	void resetBoard();

public:
	static const Vector2f TOPLEFT;
	static const Vector2f BOTTOMRIGHT;
	static const Vector2f SIZE;

	Board();
	~Board();

	sf::RectangleShape rect;
	GemType board[13][17];

	virtual void draw(RenderTarget & target, RenderStates states) const;
};

