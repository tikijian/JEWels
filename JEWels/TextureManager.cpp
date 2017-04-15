#include "stdafx.h"
#include "TextureManager.h"

const vector<string> TextureManager::textureNames = {
	"jew.png"
};

TextureManager::TextureManager()
{

}


TextureManager::~TextureManager()
{
}

void TextureManager::initialize()
{
	using namespace std;
	for (vector<int>::size_type i = 0; i != textureNames.size(); i++) {
		stringstream path; 
		path << "graphics/";
		path << textureNames[i];
		sf::Texture texJew;
		texJew.loadFromFile(path.str());

		textures[textureNames[i]] = texJew;
	}
}

sf::Texture TextureManager::get(const char* filename)
{
	return textures[filename];
}
