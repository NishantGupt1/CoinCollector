#include "ResourceManager.h"
#include "Game.h"

ResourceManager::ResourceManager(Game* game)
{
	this->game = game;
}
ResourceManager::~ResourceManager()
{
	std::map<std::string, SDL_Texture*>::iterator i;
	for(i = textures.begin(); i != textures.end(); i++)
	{
		SDL_DestroyTexture(i->second);
	}
	textures.clear();
}
void ResourceManager::loadTexture(std::string filename)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(game->getRenderer(), filename.c_str());

	if(texture == NULL)
		throw std::runtime_error("Error while loading texture: " + filename);

	textures.insert(std::pair<std::string, SDL_Texture*>(filename, texture));
}
SDL_Texture* ResourceManager::getTexture(std::string filename)
{
	SDL_Texture* texture = NULL;
	std::map<std::string, SDL_Texture*>::iterator i;

	i = textures.find(filename);

	/* this assigns the value of pair to texture */
	texture = i->second;

	return texture;
}