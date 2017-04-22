#pragma once
#include "SFML\Graphics.hpp"

class Gem
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
	void render(sf::RenderWindow* wnd);

private:
	void setColor(Type t);

};

