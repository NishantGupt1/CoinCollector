#ifndef OBJECT_H
#define OBJECT_H

#include "Game.h"
#include "ResourceManager.h"

class Object
{
protected:
	float x, y;
	float sizeX, sizeY;

	Game* game;
	ResourceManager* rm;

	SDL_Rect source_rect;
	SDL_Rect dest_rect;
public:
	virtual void Init(Game* game, ResourceManager* rm) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;

	bool collidesWith(Object* other);
};

#endif