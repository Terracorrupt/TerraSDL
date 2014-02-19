#ifndef LEVEL1
#define LEVEL1

#include "Scene.h"
#include "SceneManager.h"

class Level1: public Scene
{
public:
	Level1(SDL_Renderer*);
	~Level1();
	void Update();
	void Draw();
private:
	Mix_Chunk* effect1;
	Generic* p;
	Generic* e;
	Generic* o;
	Generic* o2;
	Generic* m;
	Mix_Music* music2;
	bool changed;
};
#endif