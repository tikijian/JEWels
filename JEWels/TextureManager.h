#pragma once
#include <map>
#include <string>
#include <SFML\Graphics.hpp>

using namespace std;

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	map<string, sf::Texture> textures;
	void initialize();

	const static string textureNames[];
};

