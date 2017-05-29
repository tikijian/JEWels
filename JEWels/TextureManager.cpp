#include "stdafx.h"
#include "TextureManager.h"
#include <iostream>


const vector<string> TextureManager::textureNames = {
	"jew.png"
};

TextureManager::TextureManager()
{
	initialize();
	// manually load gems spritesheet
	// convert pink background to transparent color
	sf::Image image;
	image.loadFromFile(resourcePath("graphics/gems.png"));
	image.createMaskFromColor(sf::Color(237, 0, 235));

	sf::Texture gems;
	gems.loadFromImage(image);
	textures["gems.png"] = gems;
}


TextureManager::~TextureManager()
{
}

void TextureManager::initialize()
{
	using namespace std;
	cout << "initializing TM" << endl;
	for (vector<int>::size_type i = 0; i != textureNames.size(); i++) {
		stringstream path; 
		path << "graphics/";
		path << textureNames[i];
		sf::Texture texture;
        const char* finalPath = path.str().c_str();
        texture.loadFromFile(resourcePath(finalPath));

		textures[textureNames[i]] = texture;
	}
}

const sf::Texture& TextureManager::get(const string &filename)
{
	return textures[filename];
}
