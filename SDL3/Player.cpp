#include "Player.h"


Player::Player(SDL_Renderer* renderer)
{
	position = new Vector2(0,0);
	pRenderer = renderer;
	cFrame = 1;
	cRow = 1;

}

Player::~Player()
{

}

void Player::Load(char* path, char* textID, float x, float y, int w, int h)
{
	position->setX(x);
	position->setY(y);
	pw = w;
	ph = h;

	playerRect.h=h;
	playerRect.w=w;

	DrawnToLife::Instance()->LoadImage(path,textID,pRenderer);
	PtextID = textID;

}

void Player::Draw()
{
	//SDL_RenderClear(pRenderer);

	//Spritebatch.Begin
	DrawnToLife::Instance()->AnimationDraw(PtextID,pRenderer,position->getx(),position->gety(),pw,ph,cRow,cFrame);
	
	//SDL_RenderPresent(pRenderer);

	//Spritebatch.End
	//DEBUG_MSG(px);

}

void Player::Update()
{
	//Update Animation
	cFrame = int(((SDL_GetTicks() / 100) % 6));

	//DEBUG_MSG(k.keysym.sym);
	Move();

	playerRect.x=(int)position->getx();
	playerRect.y=(int)position->gety();

	//Redraw
	Draw();
}

void Player::Move()
{
	if(TheTouchMeBaby::Instance()->HasBeenTouched(SDL_SCANCODE_A))
	{
		//DEBUG_MSG("YAY");
		position->setX(position->getx()-0.1f);
		
		if(position->getx()<0.0f)
			position->setX(0.1f);
	}
	if(TheTouchMeBaby::Instance()->HasBeenTouched(SDL_SCANCODE_D))
	{
		position->setX(position->getx()+0.1f);
		
		if(position->getx()>900.0-30.f)
			position->setX(900.0-30.f);
	}

}

SDL_Rect Player::getRect()
{
	return playerRect;
}
