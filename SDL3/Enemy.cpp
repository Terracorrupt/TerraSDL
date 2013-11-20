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

}

void Enemy::Load(char* path, char* textID, float x, float y, int w, int h)
{
	position->setX(x);
	position->setY(y);
	pw = w;
	ph = h;

	enemyRect.h=h;
	enemyRect.w=w;

	initialx = position->getx();

	DrawnToLife::Instance()->LoadImage(path,textID,pRenderer);
	PtextID = textID;
}

void Enemy::Draw()
{
	
	//Spritebatch.Begin
	DrawnToLife::Instance()->AnimationDraw(PtextID,pRenderer,position->getx(),position->gety(),pw,ph,cRow,cFrame);
}

void Enemy::Update()
{

	//Update Animation
	cFrame = int(((SDL_GetTicks() / 100) % 6));

	//Update Position
	enemyRect.x = (int)position->getx();
	enemyRect.y = (int)position->gety();

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

SDL_Rect Enemy::getRect()
{
	return enemyRect;
}