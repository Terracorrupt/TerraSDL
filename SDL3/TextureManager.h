#ifndef DRAWNTOLIFE_H
#define DRAWNTOLIFE_H

#include <SDL.h>
#include "SDL_image.h"
#include <map>

using namespace std;

class TextureManager
{
private:
	map<char*, SDL_Texture*> TMap;
	TextureManager(){};
	static TextureManager* instance; 
	SDL_Surface* temp;
	SDL_Rect source;
	SDL_Rect dest;
public:
	bool LoadImage(const char*, char*, SDL_Renderer*);
	void Draw(char*,SDL_Renderer*,float,float,int,int);
	void AnimationDraw(char*,SDL_Renderer*,float,float,int,int,int,int);

	//Singelton
	static TextureManager* Instance()
	{	
		if(instance ==0)
		{
			instance = new TextureManager();
			return instance;
		}
		return instance;
	}
};
#endif