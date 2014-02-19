/*
//The Main Class runs the main game loop, and controls game speed
*/

#include <SDL.h>
#include <iostream>
#include "Game.h"

int main(int argc, char *argv[])
{
	Uint32 fStart, fTime;
	const int FPS = 60;

	const int DELAY = 1000/FPS;
	Game *g = new Game();


	if((g->Initialize("TerraSDL", 20,20,1300,700,0))==true)
	{
		g->Render();
	}

	while(g->IsRunning())
	{
		//Get Current Ticks
		fStart = SDL_GetTicks();

		g->Update();

		//Calculate new current ticks
		fTime = SDL_GetTicks() - fStart;

		//If slow, delay
		if(fTime<DELAY)
		{
			SDL_Delay((int)(DELAY - fTime));
		}
	}

	SDL_Quit();

	return 0;
}
