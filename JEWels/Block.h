#pragma once
#include "SFML\Graphics.hpp"
#include "Gem.h"

class Block
{
public:
	Block();
	~Block();

	Gem gems[3];
	sf::IntRect bounds;
	sf::RectangleShape rect;

	void update(sf::Time* dt);
	void processInput(sf::Event* event);
	void render(sf::RenderWindow* wnd);

	bool isActive = true;
	bool canStep = true;

private: 
	int stepTime = 0;
	int stepDuration = 1000;

	void cycle();
	void updateGems();
};

