#include "stdafx.h"
#include "Board.h"

using namespace sf;

const sf::Vector2f Board::TOPLEFT = Vector2f(230, 65);
const Vector2f Board::SIZE = Vector2f(520, 680);
const sf::Vector2f Board::BOTTOMRIGHT = TOPLEFT + SIZE;
const int ROWS = 13;
const int COLS = 17;

void Board::resetBoard()
{
	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			board[row][col] = GemType::Empty;
		}
	}
}

Board::Board()
{
	rect.setFillColor(Color::Transparent);
	rect.setSize(SIZE);
	rect.setOutlineColor(Color(233, 233, 233));
	rect.setOutlineThickness(2.0f);
	rect.setPosition(TOPLEFT);

	resetBoard();
}

Board::~Board()
{
}

void Board::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(rect);
}
