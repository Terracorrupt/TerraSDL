#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>
#include "GottaCatchEmAll.h"
#include "TouchMeBaby.h"
#include "SDL_mixer.h"

using namespace std;

class Game
{
private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Surface* screenSurface;
	bool running;
	int playerUpdateValue;
	SDL_Event e;
public:
	Game();
	~Game();
	bool Initialize(const char*, int, int, int, int, int);
	void Render();
	void Update();
	bool IsRunning();
	void CleanUp();	
	void Events();
};
#endif