/*
//The Player class is an example of a generic object. Player inherits from Generic, and is a "Generic object" in our game. This can
//be a player, an enemy, an obstacle, basically any object that exists in our game.
*/

#include "Player.h"


Player::Player(SDL_Renderer* renderer)
{
	position = new Vector2(0,0);
	pRenderer = renderer;
	cFrame = 1;
	cRow = 1;
	jumping = false;
}

Player::~Player()
{
	delete position, pRenderer;
}

void Player::Load(char* path, char* textID, float x, float y, int w, int h)
{
	position->setX(x);
	position->setY(y);
	pw = w;
	ph = h;

	playerRect.h=h;
	playerRect.w=w;

	TextureManager::Instance()->LoadImage(path,textID,pRenderer);
	PtextID = textID;
	timer=0;
}

void Player::Draw()
{
	TextureManager::Instance()->AnimationDraw(PtextID,pRenderer,position->getx(),position->gety(),pw,ph,cRow,cFrame);
}

void Player::Update()
{
	//Update Animation
	cFrame = int(((SDL_GetTicks() / 100) % 6));

	Move();
	
	//Fall
	if(!jumping)
	{
		position->setY(position->gety()+0.5f);

		if(position->gety()>700.0-30.f)
			position->setY(700.0-30.f);
	}

	playerRect.x=(int)position->getx();
	playerRect.y=(int)position->gety();


	//Redraw
	Draw();
}

void Player::Move()
{
	if(TheInputManager::Instance()->HasBeenTouched(SDL_SCANCODE_A))
	{
		//Move left
		position->setX(position->getx()-0.2f);
		
		if(position->getx()<0.0f)
			position->setX(0.1f);
		cRow = 2;
	}
	if(TheInputManager::Instance()->HasBeenTouched(SDL_SCANCODE_D))
	{
		//Move Right
		position->setX(position->getx()+0.2f);
		
		if(position->getx()>1300.0-30.f)
			position->setX(1300.0-30.f);
		cRow=1;
	}
	if(TheInputManager::Instance()->HasBeenTouched(SDL_SCANCODE_SPACE))
	{
		jumping = true;
	}

	Jump();

}

SDL_Rect Player::getRect()
{
	return playerRect;
}

void Player::Jump()
{
	if(jumping)
	{
		if(timer<300)
		{
			position->setY(position->gety()-0.4f);
			
		} 
		if(timer>=300)
		{
			position->setY(position->gety()+0.4f);

		}
		
		if(timer>=600)
		{
			timer = 0;
			jumping = false;
		}

		timer++;
	}
		
}

void Player::LoadDupe(char* textID, float x, float y, int w, int h)
{
	//NotUsing
}