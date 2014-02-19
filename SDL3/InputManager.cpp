/*
//The Input Manager has a method that returns a Scancode, used for Input. Use for Keyboard Input.
//An example is provided in the Level1 class
*/

#include "InputManager.h"

InputManager* InputManager::instance=0; 

InputManager::InputManager()
{
	keyState = SDL_GetKeyboardState(0);
}

bool InputManager::HasBeenTouched(SDL_Scancode s)
{
	//Take in Scancode
	if(keyState[s]!=1)
		return false;
	else
		return true;

	return false;
}