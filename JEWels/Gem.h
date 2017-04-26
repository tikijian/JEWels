#pragma once
#include "SFML\Graphics.hpp"

class Gem : public sf::Drawable
{

public:
	enum class Type { Red, Green, Blue, Yellow, Magenta };
	static const float SIZE;

	Gem();
	Gem(Type t);
	~Gem();

	sf::RectangleShape rect;
	Type type = Type::Red;
	void setType(Type t);
	void update(sf::Vector2f blockPosition, int offset);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
	void setColor(Type t);

};

