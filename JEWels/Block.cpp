#include "stdafx.h"
#include "Block.h"

using namespace sf;

Block::Block()
{
	// eeeewww
	rect.setPosition(Vector2f(400.0f, 65.0f));
	rect.setOutlineColor(Color(200.0f, 200.0f, 200.0f));
	rect.setOutlineThickness(1.0f);
	rect.setFillColor(Color::Transparent);
	rect.setSize(Vector2f(Gem::SIZE, Gem::SIZE * 3));
}

void Block::update(Time* dt) 
{
	if (!isActive) return;

	stepTime += dt->asMilliseconds();
	if (stepTime >= stepDuration) {
		rect.setPosition(rect.getPosition() + Vector2f(.0f, 40.0f));
		stepTime = 0;
	}

	updateGems();
}

void Block::updateGems()
{
	for (int i = 0; i <= 2; i++) {
		gems[i].update(rect.getPosition(), i);
	}
}

void Block::render(RenderWindow* wnd)
{
	for (int i = 0; i <= 2; i++) {
		gems[i].render(wnd);
	}
	wnd->draw(rect);
}

Block::~Block()
{
}
