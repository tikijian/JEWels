#include "stdafx.h"
#include "Board.h"

using namespace sf;
using namespace Constants;
using namespace helpers;

Board::Board():
	board(true), // add (true) for debug fill
	block(board)
{
	rect.setFillColor(Color::Transparent);
	rect.setSize(BOARDSIZE);
	rect.setOutlineColor(Color(233, 233, 233));
	rect.setOutlineThickness(2.0f);
	rect.setPosition(TOPLEFT);
}

Board::~Board()
{
}

void Board::update(const Time & dt)
{
	block.update(dt);
}

void Board::commitBlock(Block & block)
{
	Gem * gems = &block.gems[0];
	for (int i = 0; i < 3; i++)
	{
		Vector2f gemPosition = gems[i].getPosition();
		Vector2i boardCoords = getBoardIndex(gemPosition);
		board.set(
			gems[i].type,
			boardCoords.x,
			boardCoords.y
		);
	}
}

void Board::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(rect);
	target.draw(score);
	target.draw(board);
	target.draw(block);
}
