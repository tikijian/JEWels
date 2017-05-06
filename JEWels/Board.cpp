#include "stdafx.h"
#include "Board.h"

using namespace sf;

void Board::resetBoard()
{
	for (int row = 0; row < Constants::ROWS; row++)
	{
		for (int col = 0; col < Constants::COLS; col++)
		{
			board[row][col] = GemType::Empty;
		}
	}
}

Vector2i Board::getBoardIndex(const Vector2f & coords)
{
	int x = (int)((coords.x - Constants::TOPLEFT.x) / Constants::GEMSIZE);
	int y = (int)((coords.y - Constants::TOPLEFT.y) / Constants::GEMSIZE);
	return Vector2i(x, y);
}

Board::Board()
{
	rect.setFillColor(Color::Transparent);
	rect.setSize(Constants::BOARDSIZE);
	rect.setOutlineColor(Color(233, 233, 233));
	rect.setOutlineThickness(2.0f);
	rect.setPosition(Constants::TOPLEFT);

	resetBoard();
}

Board::~Board()
{
}

void Board::update(const Time & dt)
{
}

void Board::commitBlock(Block & block)
{
	Gem * gems = &block.gems[0];
	for (int i = 0; i < 3; i++)
	{
		Vector2f gemPosition = gems[i].getPosition();
		Vector2i boardCoords = getBoardIndex(gemPosition);
		board[boardCoords.x][boardCoords.y] = gems[i].type;
	}
}

void Board::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(rect);
}
