#ifndef ENEMY_H
#define ENEMY_H

#include "Generic.h"
#include "Vector2.h"
#include "TouchMeBaby.h"

class Enemy: public Generic
{
public:
	void Load(char*,char*,float,float,int,int);
	void Update();
	void Draw();
	SDL_Rect getRect();
	Enemy(SDL_Renderer*);
	~Enemy();
private:
	//Enemy specific
	SDL_Rect enemyRect;
	Vector2* position;
	float initialx;
	bool turn;
};
#endif