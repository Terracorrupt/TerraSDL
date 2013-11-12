#include <SDL.h>
#include "Game.h"
#include "Debug.h"
#include <iostream>

using namespace std;

SDL_Event event;

SDL_Surface* img = NULL;
SDL_Rect rect;

Game::Game()
{
	rect.x=0;
	rect.y=0;
}

bool Game::Initialize(const char* msg, int x, int y , int w, int l, int f)
{
	SDL_Init(SDL_INIT_EVERYTHING);  //Include everything

	if(window = SDL_CreateWindow(msg,x,y,w,l,f))
	{
		screenSurface = SDL_GetWindowSurface(window);
		return true;
	}
	else
	{
		return false;
	}
	
}

void Game::Render()
{
		renderer = SDL_CreateRenderer(window,-1,0);
		SDL_SetRenderDrawColor(renderer,0,0,0,255);
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);
}

void Game::Update()
{
	while(running)
	{
		//DEBUG_MSG("Running");

		while(SDL_PollEvent(&event))  
		{
			//Main Game here


			//Hit Escape, exit
			switch(event.type)
				case SDL_KEYDOWN:
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							running = false;
							break;
						case SDLK_0:
							img = LoadImage(img,"images/EotA.bmp");
							break;
						case SDLK_1:
							
							break;
						case SDLK_2:
							UnloadImage(img);
							break;
						case SDLK_3:
							rect.x++;
							break;
					}

			//img->
			//Update All
			SDL_RenderClear(renderer);

			Draw(img,screenSurface);
			SDL_UpdateWindowSurface(window);

			SDL_RenderPresent(renderer);
			
		}
	}
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

SDL_Surface* Game::LoadImage(SDL_Surface* image, const char* imagePath)
{
	image = SDL_LoadBMP(imagePath);

	if(image==NULL)
	{
		DEBUG_MSG("Did not load image");
		return false;
	}
	else
	{
		DEBUG_MSG("Image loaded");
		return image;
	}
}

void Game::UnloadImage(SDL_Surface* image)
{
	SDL_FreeSurface(image);
	image = NULL;
	DEBUG_MSG("Image Unloaded");
}

void Game::Draw(SDL_Surface* image, SDL_Surface* screen)
{
	SDL_BlitSurface( image, NULL, screen, &rect );
	DEBUG_MSG("Image Drawn");
}


