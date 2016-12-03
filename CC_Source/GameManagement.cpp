#include "Game.h"
#include "GameState.h"

void Game::PushState(GameState* state)
{
	states.push_back(state);
	if(state->Init(this) == false)
	{
		quit = true;
	}
}
void Game::PopState()
{
	states.back()->Quit();
	delete states.back();
	states.pop_back();

	//if we just popped the last state
	if(states.size() == 0) 
	{
		quit = true;
	}
}