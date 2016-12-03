#ifndef STATE_GAMEPLAY_H
#define STATE_GAMEPLAY_H

#include "GameState.h"
#include "ResourceManager.h"
#include "Dawn.h"
#include "Level.h"
#include "Coin.h"
#include "Font.h"

class State_Gameplay : public GameState
{
private:
	ResourceManager* rm;	

	Dawn dawn;
	Level* level;
	std::vector<Coin*> coins;

	Font* font;

	unsigned int score;
public:
	bool Init(Game* game);
	void HandleEvents(SDL_Event* event);
	void Update(float deltaTime);
	void Render();
	void Quit();
};

#endif