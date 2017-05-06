#pragma once
#include "SFML\Graphics.hpp"
#include "GemTypes.h"
#include "Constants.h"

class Gem : public sf::Drawable
{

public:
	Gem();
	Gem(GemType t);
	~Gem();

	GemType type;
	sf::RectangleShape rect;
	sf::Vector2f getPosition() { return rect.getPosition(); }
	void setType(GemType t);
	void update(sf::Vector2f blockPosition, int offset);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	void setColor(GemType t);

};

