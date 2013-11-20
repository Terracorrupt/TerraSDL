#include "GottaCatchEmAll.h"


GottaCatchEmAll* GottaCatchEmAll::instance=0; 

void GottaCatchEmAll::Load()
{
	MenuOne = 1;
	LevelOne = 2;
	Loading = 3;

	//CURRENT SCENE
	current = LevelOne;
	last = Loading;
}

int GottaCatchEmAll::getCurrent()
{
	return current;
}

void GottaCatchEmAll::setCurrent(int i)
{
	current = i;
}

Scene* GottaCatchEmAll::NextScene(SDL_Renderer* r)
{
	switch(current)
	{
	case 1: //MENU
		if(last!=MenuOne)
		{
			active = new Menu(r);
			last = MenuOne;
			previous = active;
		}
		break;
	case 2: //Level1
		if(last!=LevelOne)
		{
			active = new Level1(r);
			last = LevelOne;
			previous = active;
		}
	case 3: //Loading
		break;
	}

	return active;
}