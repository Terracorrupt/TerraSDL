#include <SDL.h>
#include <iostream>
#include "Game.h"

int main(int argc, char *argv[])
{
	Game *g = new Game();

	if((g->Initialize("Hello", 20,20,300,300,0))==true)
	{
		g->Render();
	}

	while(g->IsRunning())
	{
		g->Update();
	}

	return 0;
}
