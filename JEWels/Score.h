#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <SFML\Graphics.hpp>

class Score : public sf::Drawable
{
private: 
	sf::Font font;
	std::stringstream scoreText;
	int add(int val);
public:
	Score();
	~Score();

	int score = 0;
	sf::Text text;
	int operator+=(int val) { return add(val); }
	
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const;

};

