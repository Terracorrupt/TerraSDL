#ifndef LEVEL2
#define LEVEL2

#include "Scene.h"

class Level2: public Scene
{
public:
	Level2(SDL_Renderer*);
	~Level2();
	void Update();
	void Draw();

private:
	Mix_Chunk* effect1;
	Enemy* e;
	Enemy* e2;
	Enemy* e3;
	Generic* m;
};
#endif