#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <vector>

class GameState;

class Game
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;

	int screen_width;
	int screen_height;

	bool quit;

	//state management
	std::vector<GameState*> states;

	//deltaTime related variables
	Uint32 new_time;
	Uint32 old_time;	

public:	
	Game();
	bool Init(GameState* state);
	void Thread(); //this function will begin the main thread and will loop until quit is set to true
private:	
	//internal loop functions
	void Update();
	void Render();
	void Quit();	
public:
	//state management functions
	void PushState(GameState* state);
	void PopState();	

	void setQuit();

	SDL_Renderer* getRenderer();
};

#endif