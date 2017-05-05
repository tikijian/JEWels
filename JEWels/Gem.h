#pragma once
#include "SFML\Graphics.hpp"
#include "GemTypes.h"

class Gem : public sf::Drawable
{

public:
	static const float SIZE;

	Gem();
	Gem(GemType t);
	~Gem();

	GemType type;
	sf::RectangleShape rect;
	void setType(GemType t);
	void update(sf::Vector2f blockPosition, int offset);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	void setColor(GemType t);

};

