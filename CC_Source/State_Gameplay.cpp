#include "State_Gameplay.h"

bool State_Gameplay::Init(Game* game)
{
	this->game = game;

	rm = new ResourceManager(game);

	try
	{
		rm->loadTexture("Data/character.png");
		rm->loadTexture("Data/tile_01.png");
		rm->loadTexture("Data/font_texture.png");
		rm->loadTexture("Data/item.png");
	}
	catch(std::runtime_error &e)
	{
		std::cerr << e.what() << std::endl;
		return false;
	}

	font = new Font(game, rm->getTexture("Data/font_texture.png"), 16, 16, 8, 16);

	level = new Level(game, rm);
	level->Init();

	dawn.Init(game, rm);

	for(int i=0; i<10; i++)
	{
		coins.push_back(new Coin());
		coins.back()->Init(game, rm);
	}

	score = 0;

	return true;
}
void State_Gameplay::HandleEvents(SDL_Event* event)
{
	if(event->type == SDL_QUIT)
		game->PopState();
}
void State_Gameplay::Update(float deltaTime)
{
	const Uint8* keyboard = SDL_GetKeyboardState(NULL);

	if(keyboard[SDL_SCANCODE_RIGHT])
		dawn.Move(1, 0);
	if(keyboard[SDL_SCANCODE_LEFT])
		dawn.Move(-1, 0);
	if(keyboard[SDL_SCANCODE_UP])
		dawn.Move(0, -1);
	if(keyboard[SDL_SCANCODE_DOWN])
		dawn.Move(0, 1);

	dawn.Update(deltaTime);

	for(int i=0; i<coins.size(); i++)
	{
		coins[i]->Update(deltaTime);
		if(coins[i]->collidesWith(&dawn))
		{
			coins[i]->Relocate();
			score++;
		}
	}
}
void State_Gameplay::Render()
{
	level->Render();

	for(int i=0; i<coins.size(); i++)
	{
		coins[i]->Render();
	}

	dawn.Render();

	char buffer[64];
	font->RenderString(0, 0, "SCORE: " + std::string(itoa(score, buffer, 10)));
}
void State_Gameplay::Quit()
{
	for(int i=0; i<coins.size(); i++)
	{
		delete coins[i];
	}
	coins.clear();
	
	delete font;
	delete level;
	delete rm;
}