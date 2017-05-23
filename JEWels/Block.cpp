#include "stdafx.h"
#include "Block.h"

using namespace sf;
using namespace Constants;

Block::Block()
{
	setOutlineColor(Color(200, 200, 200));
	setOutlineThickness(1.0f);
	setFillColor(Color::Transparent);
	setSize(Vector2f(GEMSIZE, BLOCK_HEIGHT));
}

void Block::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i <= 2; i++) {
		target.draw(gems[i]);
	}
	//target.draw(rect);
}

void Block::resetGems()
{
	for (int i = 0; i <= 2; i++) {
		GemType newType = static_cast<GemType>(rand() % (int)GemType::Magenta);
		gems[i].setType(newType);
	}
}

void Block::update(const Time& dt) 
{
	updateGems();
}

void Block::updateGems()
{
	for (int i = 0; i <= 2; i++) {
		gems[i].update(getPosition(), i);
	}
}

Block::~Block()
{
}
