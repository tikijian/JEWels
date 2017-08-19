#include "stdafx.h"
#include "Board.h"

using namespace sf;
using namespace Constants;
using namespace helpers;

const int FALL_SPEED = 30;
const int SCORE_PER_GEM = 10;

Board::Board():
	boardData(false) // add (true) for debug fill
{
	rect.setFillColor(Color::Transparent);
	rect.setSize(BOARDSIZE);
	rect.setOutlineColor(Color(233, 233, 233));
	rect.setOutlineThickness(2.0f);
	rect.setPosition(TOPLEFT);

	block.reset();
}

Board::~Board()
{
}

void Board::processInput(const Event& event)
{
	if (state != GameState::Playing) return;

	switch (event.key.code)
	{
	case Keyboard::Left:
		if (canMoveLeft())
			block.move(Vector2f(-STEP, .0f));
		break;
	case Keyboard::Right:
		if (canMoveRight())
			block.move(Vector2f(STEP, .0f));
		break;
	case Keyboard::Down:
		// speed up falling speed on DOWN
		if (state == GameState::Falling) break;
		setState(GameState::Falling);
		lastKnownStepDuration = stepDuration;
		stepDuration = FALL_SPEED;
		break;
	case Keyboard::Space:
	case Keyboard::Up:
		block.cycle();
		break;
	default:
		break;
	}
}

void Board::update(const Time & dt)
{
	stepTime += dt.asMilliseconds();
	if (stepTime >= stepDuration) {
		if (canMoveBottom()) {
			block.move(Vector2f(.0f, GEMSIZE));
		} else {
			commitBlock();
			block.reset();
			boardData.update();
		}
		stepTime = 0;
	}

	updateScore();
	block.update(dt);
}

void Board::draw(RenderTarget & target, RenderStates states) const
{
	target.draw(rect);
	target.draw(score);
	target.draw(boardData);
	target.draw(block);
}

void Board::commitBlock()
{
	Gem* const gems = block.gems;
	for (int i = 0; i <= 2; i++) {
		Vector2i index = getBoardIndex(gems[i].getPosition());
		boardData.set(gems[i].type, index);
	}

	if (state == GameState::Falling) {
		stepDuration = lastKnownStepDuration; // restore falling speed when fall process is ended
		setState(GameState::Playing);
	}
}

void Board::updateScore() {
	int detectedBlocks = boardData.getDetectedBlocks();
	if (detectedBlocks > 0) {
		score += detectedBlocks * SCORE_PER_GEM;
		boardData.resetDetectedCounter();
	}
}

bool Board::canMoveBottom()
{
	float xPos = block.getPosition().x;
	float offsetYPos = (block.getPosition().y + BLOCK_HEIGHT);
	if (offsetYPos >= BOTTOMRIGHT.y)
		return false;
	
	Vector2i bottomCell = getBoardIndex(Vector2f(xPos, offsetYPos));
	return boardData.at(bottomCell) == GemType::Empty;
}

bool Board::canMoveLeft()
{
	float xPos = block.getPosition().x;
	float yPos = block.getPosition().y;
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
		if (boardData.at(targetCell) != GemType::Empty) {
			canMove = false;
			break;
		}
	}
	
	return canMove;
}

bool Board::canMoveRight()
{
	float xPos = block.getPosition().x;
	float yPos = block.getPosition().y;
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
		if (boardData.at(targetCell) != GemType::Empty) {
			canMove = false;
			break;
		}
	}
	
	return canMove;
}
