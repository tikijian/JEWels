#pragma once
#include <map>
#include <vector>
#include <string>
#include <sstream>
#include <SFML\Graphics.hpp>

using namespace std;

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	map<string, sf::Texture> textures;
	void initialize();
	sf::Texture get(const string &filename);

	const static vector<string> textureNames;
};

