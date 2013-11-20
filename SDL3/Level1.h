#ifndef LEVEL1
#define LEVEL1

#include "Scene.h"

class Level1: public Scene
{
public:
	Level1(SDL_Renderer*);
	~Level1();
	void Update();
	void Draw();

	Generic* p;
	Generic* e;
};
#endif