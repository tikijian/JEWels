#pragma once
#include "SFML\Graphics.hpp"
#include "Gem.h"
#include "Constants.h"
#include "Helpers.h"
#include "GemTypes.h"
#include "BoardData.h"

class Block : public sf::Drawable
{
public:
	Block(BoardData &boardData);
	~Block();

	sf::IntRect bounds;
	sf::RectangleShape rect;
	Gem gems[3];

	void update(const sf::Time& dt);
	void processInput(const sf::Event& event);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool isActive = true;
private: 
	int stepTime = 0;
	int stepDuration = 1000;
	const float HEIGHT = 120.0f;
	bool canStep = true;
	BoardData *board;

	void cycle();
	void updateGems();
	bool canMoveBottom();
	bool canMoveLeft();
	bool canMoveRight();
};

