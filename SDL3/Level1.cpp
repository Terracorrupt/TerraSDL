#include "Level1.h"

Level1::Level1(SDL_Renderer* r)
{
	p = new Player(r);
	e = new Enemy(r);

	p->Load("images/burtRunningRight.png","1",200.0f,200.0f,30,54);
	e->Load("images/floaty.png","2",400.0f,200.0f,42,50);
}

Level1::~Level1()
{

}

void Level1::Update()
{
	p->Update();
	e->Update();

	if(SDL_HasIntersection(&p->getRect(), &e->getRect()))
	{
		//TheGottaCatchEmAll::Instance()->setCurrent(1);
	}
}

void Level1::Draw()
{
	p->Draw();
	e->Draw();
}