#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <SFML\Graphics.hpp>

class Score
{
private: 
	sf::Font font;
public:
	Score();
	~Score();

	int score = 0;
	void add(int val);
	int operator+=(int val) { return score += val; }
	
	sf::Text text;
	sf::Text formatted();
};

