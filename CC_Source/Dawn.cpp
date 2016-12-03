#include "Dawn.h"

void Dawn::Init(Game* game, ResourceManager* rm)
{
	this->game = game;
	this->rm = rm;

	x = 160 - 8;
	y = 120 - 16;
	sizeX = 16;
	sizeY = 32;

	dirX = 0.0f;
	dirY = 0.0f;

	sheet_row = 0.0f;
	sheet_column = 0.0f;	
	sheet_animSpeed = 6.0f;

	move_speed = 32.0f;

	sheet = rm->getTexture("Data/character.png");
}
void Dawn::Update(float deltaTime)
{
	if(dirX != 0 || dirY != 0)
	{
		sheet_row += sheet_animSpeed*deltaTime;
		if((int)sheet_row >= 4)
			sheet_row = 0.0f;
	}
	else
		sheet_row = 0.0f;

	if(dirX > 0)
		sheet_column = 3;
	if(dirX < 0)
		sheet_column = 2;
	if(dirY < 0)
		sheet_column = 1;
	if(dirY > 0)
		sheet_column = 0;

	x += dirX * move_speed * deltaTime;
	y += dirY * move_speed * deltaTime;

	//calculating rectangle coordinates
	//for rendering the sprite sheet
	source_rect.x = sizeX * (int)sheet_column;
	source_rect.y = sizeY * (int)sheet_row;
	source_rect.w = sizeX;
	source_rect.h = sizeY;

	dest_rect.x = x;
	dest_rect.y = y;
	dest_rect.w = sizeX;
	dest_rect.h = sizeY;		

	//we just reset the direction so we can check it
	//again in the next frame
	dirX = 0.0f;
	dirY = 0.0f;
}
void Dawn::Render()
{
	SDL_RenderCopy(game->getRenderer(), sheet, &source_rect, &dest_rect);
}
void Dawn::Move(int dx, int dy)
{
	dirX += dx;
	dirY += dy;
}