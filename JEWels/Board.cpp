#include "stdafx.h"
#include "Board.h"


Board::Board(sf::RenderWindow* wnd)
{
	this->window = wnd;
	rect.setFillColor(sf::Color::Transparent);
	rect.setSize(sf::Vector2f(520, 680));
	rect.setOutlineColor(sf::Color(233, 233, 233));
	rect.setOutlineThickness(2.0f);
	rect.setPosition(230, 65);
}

Board::~Board()
{
}

void Board::render()
{
	window->draw(rect);
}
