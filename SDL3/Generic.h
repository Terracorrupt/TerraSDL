#ifndef GENERIC_H
#define GENERIC_H

#include <SDL.h>
#include "SDL_image.h"
#include "Debug.h"
#include "DrawnToLife.h"
#include <iostream>
#include <math.h>

class Generic
{
public:
	virtual void Load(char* ,char*, float,float,int,int)=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual SDL_Rect getRect()=0;
	//int px;
	//int py;
	int ph;
	int pw;
	int cFrame;
	int cRow;
	char* PtextID;
	SDL_Renderer* pRenderer;
};
#endif