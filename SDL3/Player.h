#ifndef PLAYER_H
#define PLAYER_H

#include "Generic.h"
#include "Vector2.h"
#include "TouchMeBaby.h"


class Player: public Generic
{
public:
	void Load(char*,char*,float,float,int,int);
	void Update();
	void Draw();
	void Move();
	Player(SDL_Renderer*);
	~Player();
	SDL_Rect getRect();
	//Player specific
private:
	SDL_Rect playerRect;
	Vector2* position;
};
#endif