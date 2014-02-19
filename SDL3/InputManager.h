#ifndef TOUCHMEBABY
#define TOUCHMEBABY

#include <SDL.h>
#include "SDL_image.h"
#include "Debug.h"
#include "Vector2.h"

class InputManager//I wanna know what love is
{
public:
	~InputManager();
	bool HasBeenTouched(SDL_Scancode);

	//Singelton
	static InputManager* Instance()
	{
		if(instance ==0)
		{
			instance = new InputManager();
			return instance;
		}
		return instance;
	}

private:
	InputManager();
	static InputManager* instance; 
	const Uint8* keyState;

};
#endif
typedef InputManager TheInputManager;