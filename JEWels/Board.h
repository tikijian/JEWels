#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Board : public sf::Drawable
{
public:
	static const Vector2f TOPLEFT;
	static const Vector2f BOTTOMRIGHT;
	static const Vector2f SIZE;

	Board();
	~Board();

	sf::RectangleShape rect;

	virtual void draw(RenderTarget & target, RenderStates states) const override;
};

