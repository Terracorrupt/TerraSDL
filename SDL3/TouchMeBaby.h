#ifndef TOUCHMEBABY
#define TOUCHMEBABY

#include <SDL.h>
#include "SDL_image.h"
#include "Debug.h"
#include "Vector2.h"


class TouchMeBaby//I wanna know what love is
{
public:
	~TouchMeBaby();
	bool HasBeenTouched(SDL_Scancode);
	const Uint8* keyState;

	//Singelton
	static TouchMeBaby* Instance()
	{
		if(instance ==0)
		{
			instance = new TouchMeBaby();
			return instance;
		}
		return instance;
	}

private:
	TouchMeBaby();
	static TouchMeBaby* instance; 

};
#endif
typedef TouchMeBaby TheTouchMeBaby;