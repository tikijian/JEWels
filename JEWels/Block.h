#pragma once
#include "SFML\Graphics.hpp"
#include "Gem.h"
#include "Constants.h"
#include "GemTypes.h"

class Block : public sf::RectangleShape
{
	void updateGems();
	void resetGems();
public:
	Block();
	~Block();

	Gem gems[3];
	bool isHidden = false;
	void hide();
	void update(const sf::Time& dt);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void cycle();
	void reset();
};

