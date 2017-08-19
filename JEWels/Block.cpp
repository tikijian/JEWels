#include "stdafx.h"
#include "Block.h"

using namespace sf;
using namespace Constants;

const Vector2f startPosition(390.0f, 65.0f);

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
}

void Block::cycle()
{
	Gem temp = gems[2];
	gems[2] = gems[1];
	gems[1] = gems[0];
	gems[0] = temp;
}

void Block::resetGems()
{
	for (int i = 0; i <= 2; i++) {
		GemType newType = static_cast<GemType>(rand() % (int)GemType::Magenta);
		gems[i].setType(newType);
	}
}

void Block::reset()
{
	setPosition(startPosition);
	resetGems();
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
