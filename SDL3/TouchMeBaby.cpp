#include "TouchMeBaby.h"

TouchMeBaby* TouchMeBaby::instance=0; 

TouchMeBaby::TouchMeBaby()
{
	keyState = SDL_GetKeyboardState(0);
}

bool TouchMeBaby::HasBeenTouched(SDL_Scancode s)
{
	//Take in Scancode
	if(keyState[s]!=1)
		return false;
	else
		return true;

	return false;
}