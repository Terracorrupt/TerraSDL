#ifndef ENEMY_H
#define ENEMY_H

#include "Generic.h"
#include "Vector2.h"
#include "InputManager.h"

class Enemy: public Generic
{
public:
	void Load(char*,char*,float,float,int,int);
	void Update();
	void Update(bool);
	void Draw();
	void LoadDupe(char* textID, float x, float y, int w, int h);
	void LoadDupe(char* textID, float x, float y, int w, int h, int offset);
	SDL_Rect getRect();
	Enemy(SDL_Renderer*);
	~Enemy();
private:
	//Enemy specific
	SDL_Rect enemyRect;
	float initialx;
	float initialy;
	bool turn;
};
#endif