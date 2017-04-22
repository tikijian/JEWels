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
		sf::Texture texture;
		texture.loadFromFile(path.str());

		textures[textureNames[i]] = texture;
	}
}

sf::Texture TextureManager::get(const string &filename)
{
	return textures[filename];
}
