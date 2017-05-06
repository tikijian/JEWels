#include "stdafx.h"
#include "Block.h"

using namespace sf;

Block::Block()
{
	rect.setPosition(Vector2f(390.0f, 65.0f));
	rect.setOutlineColor(Color(200, 200, 200));
	rect.setOutlineThickness(1.0f);
	rect.setFillColor(Color::Transparent);
	rect.setSize(Vector2f(Constants::GEMSIZE, Constants::GEMSIZE * 3));
}

void Block::processInput(const Event& event)
{
	if (!isActive) return;

	if (checkBoardBottom())
		isActive = false;

	switch (event.key.code)
	{
	case Keyboard::Left:
		if (checkBoardLeft())
			rect.move(Vector2f(-Constants::STEP, .0f));
		break;
	case Keyboard::Right:
		if (checkBoardRight())
			rect.move(Vector2f(Constants::STEP, .0f));
		break;
	default:
		break;
	}
}

void Block::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (int i = 0; i <= 2; i++) {
		target.draw(gems[i]);
	}
	target.draw(rect);
}

void Block::update(const Time& dt) 
{
	if (!isActive) return;

	stepTime += dt.asMilliseconds();
	if (stepTime >= stepDuration) {
		rect.move(Vector2f(.0f, 40.0f));
		stepTime = 0;
	}

	updateGems();
}

void Block::updateGems()
{
	for (int i = 0; i <= 2; i++) {
		gems[i].update(rect.getPosition(), i);
	}
}

bool Block::checkBoardBottom()
{
	return (rect.getPosition().y + Constants::GEMSIZE * 3) >= Constants::BOTTOMRIGHT.y;
}

bool Block::checkBoardLeft()
{
	return rect.getPosition().x > Constants::TOPLEFT.x;
}

bool Block::checkBoardRight()
{
	return rect.getPosition().x < (Constants::BOTTOMRIGHT.x - Constants::GEMSIZE);
}

Block::~Block()
{
}
