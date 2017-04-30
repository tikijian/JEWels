#include "stdafx.h"
#include "Score.h"


Score::Score()
{
	if (!font.loadFromFile("fonts/KOMIKAP_.ttf"))
	{
		std::cout << "ERROR: Cannot load font" << std::endl;
	}
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(28);
	text.setPosition(40, 250);
	scoreText << std::setw(6) << std::setfill('0') << score;
	text.setString(scoreText.str());
}

Score::~Score()
{
}

int Score::add(int val)
{
	score += val;
	scoreText.str(std::string()); scoreText.clear();
	scoreText << std::setw(6) << std::setfill('0') << score;
	text.setString(scoreText.str());
	return score;
}

void Score::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(text);
}



