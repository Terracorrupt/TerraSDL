#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer)
{
	position = new Vector2(0,0);
	pRenderer = renderer;
	cFrame = 1;
	cRow = 1;
	turn = false;
}

Enemy::~Enemy()
{
	delete position;
}

void Enemy::Load(char* path, char* textID, float x, float y, int w, int h)
{
	position->setX(x);
	position->setY(y);
	pw = w;
	ph = h;

	enemyRect.h=h-10;
	enemyRect.w=w-10;

	initialx = position->getx();

	TextureManager::Instance()->LoadImage(path,textID,pRenderer);
	PtextID = textID;
}

void Enemy::Draw()
{
	TextureManager::Instance()->AnimationDraw(PtextID,pRenderer,position->getx(),position->gety(),pw,ph,cRow,cFrame);
}

void Enemy::Update()
{

	//Update Animation
	cFrame = int(((SDL_GetTicks() / 100) % 6));

	//Update Position
	enemyRect.x = (int)position->getx()+20;
	enemyRect.y = (int)position->gety()+20;


	//Move Left/Right
	if(turn)
		position->setX(position->getx()-0.07f);
	else										
		position->setX(position->getx()+0.07f);

	if(position->getx()>initialx+200.0f)
	{
		turn = true;
	}
	if(position->getx()<initialx)
	{
		turn = false;
	}

	//Redraw
	Draw();
}

void Enemy::Update(bool vertical)
{

	//Update Animation
	cFrame = int(((SDL_GetTicks() / 100) % 6));

	//Update Position
	enemyRect.x = (int)position->getx()+20;
	enemyRect.y = (int)position->gety()+20;


	//Move Left/Right and Up/Down, depending on passed in value
	if(!vertical)
	{
		if(turn)
			position->setX(position->getx()-0.07f);
		else										
			position->setX(position->getx()+0.07f);

		if(position->getx()>initialx+200.0f)
		{
			turn = true;
		}
		if(position->getx()<initialx)
		{
			turn = false;
		}
	}
	else
	{
		if(turn)
			position->setY(position->gety()-0.07f);
		else										
			position->setY(position->gety()+0.07f);

		if(position->gety()>initialy+200.0f)
		{
			turn = true;
		}
		if(position->gety()<initialy)
		{
			turn = false;
		}
	}

	//Redraw
	Draw();
}

SDL_Rect Enemy::getRect()
{
	return enemyRect;
}

//Initializing variables that don't require loading in an image already on the TextureMap
void Enemy::LoadDupe(char* textID, float x, float y, int w, int h)
{
	position->setX(x);
	position->setY(y);
	pw = w;
	ph = h;

	initialx = position->getx();
	initialy = position->gety();

	enemyRect.x=(int)x;
	enemyRect.y=(int)y;
	enemyRect.h=h;
	enemyRect.w=w;

	PtextID = textID;
}

//If we want to pass in how far an enemy can go
void Enemy::LoadDupe(char* textID, float x, float y, int w, int h, int offset)
{
	position->setX(x);
	position->setY(y);
	pw = w;
	ph = h;

	initialx = position->getx() - offset;
	initialy = position->gety() - offset;

	enemyRect.x=(int)x;
	enemyRect.y=(int)y;
	enemyRect.h=h;
	enemyRect.w=w;

	PtextID = textID;
}