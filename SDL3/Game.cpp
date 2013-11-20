#include <SDL.h>
#include "SDL_image.h"
#include "Game.h"
#include "Level1.h"

using namespace std;

Game::Game()
{

}

bool Game::Initialize(const char* msg, int x, int y , int w, int l, int f)
{
	SDL_Init(SDL_INIT_EVERYTHING);  //Include everything

	if(window = SDL_CreateWindow(msg,x,y,w,l,f))
	{

		screenSurface = SDL_GetWindowSurface(window);
		renderer = SDL_CreateRenderer(window,-1,0);

		//s = new Level1(renderer);
		TheGottaCatchEmAll::Instance()->Load();
		
		return true;
	}
	else
	{
		return false;
	}

}


void Game::Update()
{
	while(running)
	{
		
		SDL_RenderClear(renderer);

		//Insert your hopes and dreams here
		while(SDL_PollEvent(&e))
		{

		}

		//Have we switched state?
		Events();

		//Update dem scenes yo
		TheGottaCatchEmAll::Instance()->NextScene(renderer)->Update();
		

		SDL_RenderPresent(renderer);

	}
}

void Game::Render()
{
	
		//Set to black
		SDL_SetRenderDrawColor(renderer,0,0,0,255);

		//Clear Window to black, Think of as spritebatch.draw
		SDL_RenderClear(renderer);

		//Draw
		//s->Draw();
		TheGottaCatchEmAll::Instance()->NextScene(renderer)->Draw();

		//Show Window, spritebatch.end
		SDL_RenderPresent(renderer);
}


bool Game::IsRunning()
{
	if(running)
	{
		return true;
	}
	else
	{
		SDL_Quit();
		return false;
	}
}


void Game::Events()
{
	if(TheTouchMeBaby::Instance()->HasBeenTouched(SDL_SCANCODE_1))
	{
		//DEBUG_MSG("YAY");
		TheGottaCatchEmAll::Instance()->setCurrent(1);
	}
	if(TheTouchMeBaby::Instance()->HasBeenTouched(SDL_SCANCODE_ESCAPE))
	{
		SDL_Quit();
		running = false;
	}
	
}


