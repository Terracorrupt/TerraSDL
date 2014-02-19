/*
//The Scene Manager handles Scene switching in our game. It switches Scene Objects based on conditions set by the programmer
//Make sure when making new Scene Objects that you update the information below for new scenes, examples below.
*/

#include "SceneManager.h"

SceneManager* SceneManager::instance=0; 

void SceneManager::Load()
{
	MenuOne = 1;
	LevelOne = 2;
	Loading = 3;
	LevelTwo = 4;

	//CURRENT SCENE
	current = MenuOne;
	last = Loading;
}

int SceneManager::getCurrent()
{
	return current;
}

void SceneManager::setCurrent(int i)
{
	current = i;
}

Scene* SceneManager::NextScene(SDL_Renderer* r)
{
	switch(current)
	{
	case 1: //Menu
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
	case 4: //Level2
		if(last!=LevelTwo)
		{
			active = new Level2(r);
			last = LevelTwo;
			previous = active;
		}
	}

	return active;
}