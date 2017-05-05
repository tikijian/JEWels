#include "stdafx.h"
#include "Gem.h"

const float Gem::SIZE = 40.0f;

Gem::Gem()
{
	GemType t = static_cast<GemType>(rand() % (int)GemType::Magenta);
	rect.setSize(sf::Vector2f(Gem::SIZE, Gem::SIZE));
	setType(t);
}

Gem::Gem(GemType t)
{
	rect.setSize(sf::Vector2f(Gem::SIZE, Gem::SIZE));
	setType(t);
}

Gem::~Gem()
{
}

void Gem::setType(GemType t)
{
	type = t;
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
void Gem::setColor(GemType t)
{
	switch (t)
	{
	case GemType::Red:
		rect.setFillColor(sf::Color::Red);
		break;
	case GemType::Blue:
		rect.setFillColor(sf::Color::Blue);
		break;
	case GemType::Green:
		rect.setFillColor(sf::Color::Green);
		break;
	case GemType::Yellow:
		rect.setFillColor(sf::Color::Yellow);
		break;
	case GemType::Magenta:
		rect.setFillColor(sf::Color::Magenta);
		break;
	default:
		break;
	}

}
