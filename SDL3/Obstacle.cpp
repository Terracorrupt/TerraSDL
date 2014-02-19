#include "Obstacle.h"

Obstacle::Obstacle(SDL_Renderer* r)
{
	position = new Vector2(0,0);
	pRenderer = r;
}

Obstacle::~Obstacle()
{
	delete position, pRenderer;
}

void Obstacle::Load(char* path, char* textID, float x, float y, int w, int h)
{
	position->setX(x);
	position->setY(y);
	pw = w;
	ph = h;

	obRect.x=(int)x;
	obRect.y=(int)y;
	obRect.h=h;
	obRect.w=w;

	TextureManager::Instance()->LoadImage(path,textID,pRenderer);
	PtextID = textID;
}

void Obstacle::Draw()
{
	TextureManager::Instance()->Draw(PtextID,pRenderer,position->getx(),position->gety(),pw,ph);
}

void Obstacle::Update()
{
	//Redraw
	Draw();
}

SDL_Rect Obstacle::getRect()
{
	return obRect;
}

void Obstacle::LoadDupe(char* textID, float x, float y, int w, int h)
{
	position->setX(x);
	position->setY(y);
	pw = w;
	ph = h;

	obRect.x=(int)x;
	obRect.y=(int)y;
	obRect.h=h;
	obRect.w=w;

	PtextID = textID;
}