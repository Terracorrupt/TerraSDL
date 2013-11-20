#include <SDL.h>
#include "SDL_image.h"
#include "Debug.h"
#include "DrawnToLife.h"
#include <iostream>

using namespace std;

DrawnToLife* DrawnToLife::instance=0; 

bool DrawnToLife::LoadImage(const char* filepath, char* id, SDL_Renderer* renderer)
{
	SDL_Surface* temp;

	//Temporrary Surface
	temp = IMG_Load(filepath);

	if(!temp)
	{
		DEBUG_MSG("Image Not Loaded");
		return false;
	}

	//Make Texture from surface and passed in renderer
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,temp);
	//Get rid of surface
	SDL_FreeSurface(temp);

	DEBUG_MSG("Image Loaded");
	
	if(texture==0)
	{
		return false;
	}
	else
	{
		//Add to texture map
		TMap[id]=texture;
		return true;
	}


}

void DrawnToLife::Draw(char* id,SDL_Renderer* renderer,float x, float y, int w, int h)
{
	//Rectnagles yo
	SDL_Rect source;
	SDL_Rect dest;
	
	source.x= 0;
	source.y= 0;
	source.w= w;
	source.h= h;

	dest.w = w;
	dest.h = h;
	dest.x= (int)x;
	dest.y= (int)y;

	

	//Do the copy
	SDL_RenderCopy(renderer,TMap[id],&source,&dest);
}

void DrawnToLife::AnimationDraw(char* id, SDL_Renderer* renderer,float x, float y, int w, int h, int cRow,int cFrame)
{
	//Rectnagles yo
	SDL_Rect source;
	SDL_Rect dest;
	
	//Source x and y adhere to location on map
	source.x= w*cFrame; 
	source.y= h*(cRow-1);
	source.w= w;
	source.h= h;

	dest.w = w;
	dest.h = h;
	dest.x= (int)x;
	dest.y= (int)y;

	//Do the copy
	SDL_RenderCopy(renderer,TMap[id],&source,&dest);
}
