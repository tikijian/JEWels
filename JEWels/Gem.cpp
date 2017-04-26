#include "stdafx.h"
#include "Gem.h"

const float Gem::SIZE = 40.0f;

Gem::Gem()
{
	Type t = static_cast<Type>(rand() % (int)Type::Magenta);
	rect.setSize(sf::Vector2f(Gem::SIZE, Gem::SIZE));
	setType(t);
}

Gem::Gem(Type t)
{
	rect.setSize(sf::Vector2f(Gem::SIZE, Gem::SIZE));
	setType(t);
}

Gem::~Gem()
{
}

void Gem::setType(Type t)
{
	this->type = t;
	setColor(t);
}

void Gem::update(sf::Vector2f blockPosition, int offset)
{
	rect.setPosition(blockPosition.x, blockPosition.y + (offset * SIZE));
}

void Gem::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(rect);
}

// TODO: refactor to template?
void Gem::setColor(Type t)
{
	switch (t)
	{
	case Type::Red:
		rect.setFillColor(sf::Color::Red);
		break;
	case Type::Blue:
		rect.setFillColor(sf::Color::Blue);
		break;
	case Type::Green:
		rect.setFillColor(sf::Color::Green);
		break;
	case Type::Yellow:
		rect.setFillColor(sf::Color::Yellow);
		break;
	case Type::Magenta:
		rect.setFillColor(sf::Color::Magenta);
		break;
	default:
		break;
	}

}
