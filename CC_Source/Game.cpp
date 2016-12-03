#include "Game.h"
#include "GameState.h"

#include <iostream>
#include <time.h>

Game::Game()
{
	window = NULL;
	renderer = NULL;

	screen_width = 320;
	screen_height = 240;

	old_time = 0;

	quit = false;
}

bool Game::Init(GameState* state)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}

	window = SDL_CreateWindow("Tutorial", SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, screen_width, screen_height, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}

	srand(time(NULL));

	PushState(state);

	return true;
}
void Game::Thread()
{
	while(quit == false)
	{		
		Update();
		Render();
	}
	Quit();
}
void Game::Update()
{
	while(SDL_PollEvent(&event))
	{
		if(states.size() > 0)
			states.back()->HandleEvents(&event);
	}	

	if(states.size() > 0)
	{
		old_time = new_time;
		new_time = SDL_GetTicks();

		if(new_time > old_time)
		{
			float deltaTime = (float)(new_time - old_time) / 1000.0f;
					
			states.back()->Update(deltaTime);
		}
	}
}
void Game::Render()
{
	SDL_RenderClear(renderer);

	if(states.size() > 0)
		states.back()->Render();

	SDL_RenderPresent(renderer);
}
void Game::Quit()
{
	while(states.size() > 0)
	{
		states.back()->Quit();
		delete states.back();
		states.pop_back();
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();	
}
void Game::setQuit()
{
	quit = true;
}
SDL_Renderer* Game::getRenderer()
{
	return renderer;
}
