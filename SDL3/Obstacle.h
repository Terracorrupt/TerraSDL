#ifndef OBST
#define OBST

#include "Generic.h"

class Obstacle: public Generic
{
public:
	void Load(char* ,char*, float,float,int,int);
	void Update();
	void Draw();
	SDL_Rect getRect();
	Obstacle(SDL_Renderer*);
	~Obstacle();
	void LoadDupe(char* textID, float x, float y, int w, int h);
private:
	SDL_Rect obRect;
};

#endif