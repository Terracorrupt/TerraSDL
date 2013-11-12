#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <iostream>

using namespace std;

class Game
{
private:
	SDL_Window * window;
	SDL_Renderer * renderer;
	SDL_Surface* screenSurface;
	bool running;
public:
	Game();
	~Game();
	bool Initialize(const char*, int, int, int, int, int);
	void Render();
	void Update();
	SDL_Surface* LoadImage(SDL_Surface*, const char*);
	void UnloadImage(SDL_Surface*);
	bool IsRunning();
	void CleanUp();
	void Draw(SDL_Surface*,SDL_Surface *);
};
#endif