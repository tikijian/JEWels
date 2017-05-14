#include "stdafx.h"
#include "Block.h"

using namespace sf;
using namespace Constants;
using namespace helpers;

const Vector2f startPosition(390.0f, 65.0f);

Block::Block(BoardData &boardData)
{
	board = &boardData;
	rect.setPosition(startPosition);
	rect.setOutlineColor(Color(200, 200, 200));
	rect.setOutlineThickness(1.0f);
	rect.setFillColor(Color::Transparent);
	rect.setSize(Vector2f(GEMSIZE, HEIGHT));
}

void Block::processInput(const Event& event)
{
	switch (event.key.code)
	{
	case Keyboard::Left:
		if (canMoveLeft())
			rect.move(Vector2f(-STEP, .0f));
		break;
	case Keyboard::Right:
		if (canMoveRight())
			rect.move(Vector2f(STEP, .0f));
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
	//target.draw(rect);
}

void Block::update(const Time& dt) 
{
	stepTime += dt.asMilliseconds();
	if (stepTime >= stepDuration) {
		if (canMoveBottom()) {
			rect.move(Vector2f(.0f, GEMSIZE));
		} else {
			commitBlock();
			reset();
		}
			
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

void Block::reset()
{
	rect.setPosition(startPosition);

	for (int i = 0; i <= 2; i++) {
		GemType newType = static_cast<GemType>(rand() % (int)GemType::Magenta);
		gems[i].setType(newType);
	}
}

void Block::commitBlock()
{
	for (int i = 0; i <= 2; i++) {
		Vector2i index = getBoardIndex(gems[i].getPosition());
		board->set(gems[i].type, index);
	}
}

bool Block::canMoveBottom()
{
	float xPos = rect.getPosition().x;
	float offsetYPos = (rect.getPosition().y + HEIGHT);
	if (offsetYPos >= BOTTOMRIGHT.y)
		return false;
	
	Vector2i bottomCell = getBoardIndex(Vector2f(xPos, offsetYPos));
	if (board->at(bottomCell) == GemType::Empty) {
		return true;
	}
	else {
		return false;
	}
}

bool Block::canMoveLeft()
{
	float xPos = rect.getPosition().x;
	float yPos = rect.getPosition().y;
	if (xPos <= TOPLEFT.x)
		return false;

	bool canMove = true;
	// get left cell X + offset
	float leftCellX = xPos - GEMSIZE;
	// iterate through 3 cells on the left side
	for (int offsetY = 0; offsetY < 3; offsetY++)
	{
		float leftCellY = yPos + (offsetY * GEMSIZE);
		Vector2i targetCell = getBoardIndex(Vector2f(leftCellX, leftCellY));
		if (board->at(targetCell) != GemType::Empty) {
			canMove = false;
			break;
		}
	}
	
	return canMove;
}

bool Block::canMoveRight()
{
	float xPos = rect.getPosition().x;
	float yPos = rect.getPosition().y;
	if (xPos >= (BOTTOMRIGHT.x - GEMSIZE))
		return false;

	bool canMove = true;
	// get left cell X + offset
	float rightCellX = xPos + GEMSIZE;
	// iterate through 3 cells on the right side
	for (int offsetY = 0; offsetY < 3; offsetY++)
	{
		float rightCellY = yPos + (offsetY * GEMSIZE);
		Vector2i targetCell = getBoardIndex(Vector2f(rightCellX, rightCellY));
		if (board->at(targetCell) != GemType::Empty) {
			canMove = false;
			break;
		}
	}
	
	return canMove;
}

Block::~Block()
{
}
