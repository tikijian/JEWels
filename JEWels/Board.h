#pragma once
#include <SFML\Graphics.hpp>
#include "GemTypes.h"
#include "GameStates.h"
#include "Gem.h"
#include "Block.h"
#include "Constants.h"
#include "Score.h"
#include "Helpers.h"
#include "BoardData.h"

using namespace sf;

class Board : public sf::Drawable
{
	int stepTime = 0;
	int stepDuration = 800;
	int lastKnownStepDuration = stepDuration;
	GameState state = GameState::Playing;

	bool canMoveBottom();
	bool canMoveLeft();
	bool canMoveRight();
	void commitBlock();
	void updateScore();

	void playingLogic();
	void destructionLogic();
	void boardUpdateLogic();
	void fallingLogic();

public:
	Board();
	~Board();

	sf::RectangleShape rect;
	Block block;
	Score score;
	BoardData boardData;

	void update(const Time &dt);
	void resetBoard() { boardData.reset(); };
	void processInput(const sf::Event& event);
	void setState(GameState s) { state = s; }
	GameState getState() { return state; }

	virtual void draw(RenderTarget & target, RenderStates states) const;
};

