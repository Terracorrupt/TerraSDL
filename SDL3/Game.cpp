/*
//The Game Class runs the main Scene Manager, Initializes the SDL Window and Renderer, and other main behaviours
*/

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

		//Load our scene manager
		SceneManager::Instance()->Load();
		
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
		SceneManager::Instance()->NextScene(renderer)->Update();
		

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
		SceneManager::Instance()->NextScene(renderer)->Draw();
		
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
	if(TheInputManager::Instance()->HasBeenTouched(SDL_SCANCODE_P))
	{
		
		SceneManager::Instance()->setCurrent(2);
	}
	if(TheInputManager::Instance()->HasBeenTouched(SDL_SCANCODE_3))
	{
		
		SceneManager::Instance()->setCurrent(4);
	}
	if(TheInputManager::Instance()->HasBeenTouched(SDL_SCANCODE_ESCAPE))
	{
		SDL_Quit();
		running = false;
	}
	
}


