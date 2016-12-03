#ifndef DAWN_H
#define DAWN_H

#include "Object.h"
#include <SDL.h>
#include <SDL_image.h>

class Dawn : public Object
{
private:
	float move_speed;	

	SDL_Texture* sheet;
	float sheet_row;
	float sheet_column;	
	float sheet_animSpeed;

	float dirX, dirY;
public:
	void Init(Game* game, ResourceManager* rm);
	void Update(float deltaTime);
	void Render();

	void Move(int dx, int dy);
};

#endif