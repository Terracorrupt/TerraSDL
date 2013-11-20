#ifndef CATCHEM
#define CATCHEM

#include <SDL.h>
#include "SDL_image.h"
#include "Level1.h"
#include "Menu.h"


class GottaCatchEmAll
{
public:

	int MenuOne;
	int LevelOne;
	int Loading;
	int current;
	Scene* previous;
	Scene* active;

	void Load();

	int getCurrent();
	void setCurrent(int);
	Scene* NextScene(SDL_Renderer*);


	//Singelton
	static GottaCatchEmAll* Instance()
	{
		if(instance ==0)
		{
			instance = new GottaCatchEmAll();
			return instance;
		}
		return instance;
	}

private:
	GottaCatchEmAll(){};
	static GottaCatchEmAll* instance; 

	int last;
};

#endif

typedef GottaCatchEmAll TheGottaCatchEmAll;