#ifndef STATE_MENU
#define STATE_MENU

#include "GameState.h"
#include "ResourceManager.h"
#include "Font.h"

class State_Menu : public GameState
{
private:
	ResourceManager* rm;
	
	Font* font;

	float blinking;	
public:
	bool Init(Game* game);
	void HandleEvents(SDL_Event* event);
	void Update(float deltaTime);
	void Render();
	void Quit();
};

#endif