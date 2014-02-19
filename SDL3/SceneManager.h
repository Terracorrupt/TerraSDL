#ifndef CATCHEM
#define CATCHEM

#include <SDL.h>
#include "Level1.h"
#include "Menu.h"
#include "Level2.h"

class SceneManager
{
public:
	void Load();
	int getCurrent();
	void setCurrent(int);
	Scene* NextScene(SDL_Renderer*);

	//Singelton
	static SceneManager* Instance()
	{
		if(instance ==0)
		{
			instance = new SceneManager();
		}
		return instance;
	}

private:
	SceneManager(){};
	static SceneManager* instance; 
	int MenuOne;
	int LevelOne;
	int LevelTwo;
	int Loading;
	int current;
	Scene* previous;
	Scene* active;
	int last;
};

#endif

//typedef SceneManager TheSceneManager;