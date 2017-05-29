#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

using namespace std;

class TextureManager
{
private: 
	TextureManager();
	~TextureManager();
public:
	static TextureManager & Instance()
	{
		static TextureManager s;
		return s;
	}

	unordered_map<string, sf::Texture> textures;
	void initialize();
	const sf::Texture& get(const string &filename);

	const static vector<string> textureNames;
};

