#include "Game.h"
#include "State_Menu.h"

int main(int argc, char** args)
{
	Game g;
	if(g.Init(new State_Menu()))
		g.Thread();
	
	return 0;
}