#include "stdafx.h"
#include "Board.h"

using namespace sf;

const sf::Vector2f Board::TOPLEFT = Vector2f(230.0f, 65.0f);
const Vector2f Board::SIZE = Vector2f(520, 680);
const sf::Vector2f Board::BOTTOMRIGHT = TOPLEFT + SIZE;

Board::Board()
{
	rect.setFillColor(Color::Transparent);
	rect.setSize(SIZE);
	rect.setOutlineColor(Color(233, 233, 233));
	rect.setOutlineThickness(2.0f);
	rect.setPosition(TOPLEFT);
}

Board::~Board()
{
}

void Board::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(rect);
}
