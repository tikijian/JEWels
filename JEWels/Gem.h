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

	bool forDestruction = false;
	GemType type;
	sf::RectangleShape rect;
	sf::Vector2f getPosition() { return rect.getPosition(); }
	void setPosition(const sf::Vector2f & pos) { rect.setPosition(pos); }
	void setType(GemType t);
	void markForDestruction() { forDestruction = true; }
	bool isEmpty() { return type == GemType::Empty;  }
	void update(sf::Vector2f blockPosition, int offset);
	void destroy();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	bool operator==(GemType t) { return type == t; }
	bool operator!=(GemType t) { return type != t; }
private:
	void setColor(GemType t);

};

