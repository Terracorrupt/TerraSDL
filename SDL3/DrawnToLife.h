#ifndef DRAWNTOLIFE_H
#define DRAWNTOLIFE_H

#include <SDL.h>
#include "SDL_image.h"
#include <map>


using namespace std;



class DrawnToLife
{
private:
	map<char*, SDL_Texture*> TMap;
	DrawnToLife(){};
	static DrawnToLife* instance; 

public:
	bool LoadImage(const char*, char*, SDL_Renderer*);
	void Draw(char*,SDL_Renderer*,float,float,int,int);
	void AnimationDraw(char*,SDL_Renderer*,float,float,int,int,int,int);

	//Singelton
	static DrawnToLife* Instance()
	{
		if(instance ==0)
		{
			instance = new DrawnToLife();
			return instance;
		}
		return instance;
	}
};
#endif