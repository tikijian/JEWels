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
}

Score::~Score()
{
}

void Score::add(int val)
{
	score += val;
}

sf::Text Score::formatted()
{
	std::stringstream scoreText;
	scoreText << std::setw(6) << std::setfill('0') << score;
	text.setString(scoreText.str());

	return text;
}


