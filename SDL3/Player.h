#ifndef PLAYER_H
#define PLAYER_H

#include "Generic.h"
#include "Vector2.h"
#include "InputManager.h"


class Player: public Generic
{
public:
	void Load(char*,char*,float,float,int,int);
	void Update();
	void Draw();
	void Move();
	void LoadDupe(char* textID, float x, float y, int w, int h);
	void Jump();
	Player(SDL_Renderer*);
	~Player();
	SDL_Rect getRect();
private:
	int timer;
	SDL_Rect playerRect;
	bool jumping;
};
#endif