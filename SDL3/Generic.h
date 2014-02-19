#ifndef GENERIC_H
#define GENERIC_H

#include <SDL.h>
#include "SDL_image.h"
#include "Debug.h"
#include "TextureManager.h"
#include <iostream>
#include <math.h>
#include "Vector2.h"

class Generic
{
public:
	virtual void Load(char* ,char*, float,float,int,int)=0;
	virtual void Update()=0;
	virtual void Draw()=0;
	virtual SDL_Rect getRect()=0;
	virtual void LoadDupe(char* textID, float x, float y, int w, int h) = 0;
	int ph;
	int pw;
	int cFrame;
	int cRow;
	char* PtextID;
	SDL_Renderer* pRenderer;
	Vector2* position;
};
#endif