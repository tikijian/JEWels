#pragma once
#include "SFML\Graphics.hpp"
#include "Gem.h"
#include "Board.h"

class Block : public sf::Drawable
{
public:
	static const float STEP;
	Block();
	~Block();

	sf::IntRect bounds;
	sf::RectangleShape rect;

	void update(const sf::Time& dt);
	void processInput(const sf::Event& event);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool isActive = true;
private: 
	int stepTime = 0;
	int stepDuration = 1000;
	bool canStep = true;
	Gem gems[3];

	void cycle();
	void updateGems();
	bool checkBoardBottom();
	bool checkBoardLeft();
	bool checkBoardRight();
};

