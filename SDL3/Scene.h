#ifndef SCENE
#define SCENE

#include <SDL.h>
#include "SDL_image.h"
#include "Debug.h"
#include "DrawnToLife.h"
#include "TouchMeBaby.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <math.h>

class Scene
{
public:
	virtual void Update()=0;
	virtual void Draw()=0;
};
#endif