#include "stdafx.h"
#include "Gem.h"
#include "TextureManager.h"

Gem::Gem()
{
	GemType t = static_cast<GemType>(rand() % (int)GemType::Magenta);
	rect.setSize(sf::Vector2f(Constants::GEMSIZE, Constants::GEMSIZE));
	TextureManager & tm = TextureManager::Instance();
	rect.setTexture(&tm.get("gems.png"));
	setType(t);
}

Gem::Gem(GemType t)
{
	rect.setSize(sf::Vector2f(Constants::GEMSIZE, Constants::GEMSIZE));
	TextureManager & tm = TextureManager::Instance();
	rect.setTexture(&tm.get("gems.png"));
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
	rect.setPosition(blockPosition.x, blockPosition.y + (offset * Constants::GEMSIZE));
}

void Gem::destroy()
{
	setType(GemType::Empty);
	//TODO: destruction animation
}

void Gem::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	if (type == GemType::Empty) return;
	target.draw(rect);
}

void Gem::setColor(GemType t)
{
	using namespace sf;

	switch (t)
	{
	case GemType::Red:
		rect.setTextureRect(IntRect(72, 3, 16, 16));
		break;
	case GemType::Blue:
		rect.setTextureRect(IntRect(89, 3, 16, 16));
		break;
	case GemType::Green:
		rect.setTextureRect(IntRect(36, 3, 16, 16));
		break;
	case GemType::Yellow:
		rect.setTextureRect(IntRect(2, 2, 16, 16));
		break;
	case GemType::Magenta:
		rect.setTextureRect(IntRect(54, 3, 16, 16));
		break;
	default:
		break;
	}

}
