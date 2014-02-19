/*
//Level1 inherits from Scene and is a Scene object that the Scene manager can then switch based on cases.
//Scene objects can include Levels, Menus, Cutscenes and other seperate instances.
//Make sure, when adding new Scenes, to update the Scene Manager class accordingly.
*/

#include "Level1.h"

Level1::Level1(SDL_Renderer* r)
{
	p = new Player(r);
	e = new Enemy(r);
	o = new Obstacle(r);
	o2 = new Obstacle(r);
	m = new Obstacle(r);

	p->Load("images/burt.png","1",200.0f,200.0f,30,54);
	e->Load("images/floaty.png","2",400.0f,400.0f,42,50);
	o->Load("images/ob1.png","3",200.0f,450.0f,300,90);
	o2->LoadDupe("3",600.0f,450.0f,300,90);
	m->Load("images/explain.png","5",50.0f,50.f,300,300);

	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096);
	music = Mix_LoadMUS("audio/Happy.wav");
	music2 = Mix_LoadMUS("audio/Dreary.wav");
	effect1 = Mix_LoadWAV("audio/KillZombie2.wav");

	Mix_PlayMusic(music,1);

	changed = true;
}

Level1::~Level1()
{
	Mix_FreeMusic(music);
	Mix_FreeChunk(effect1);
	Mix_CloseAudio();
	delete p, o, o2, e, m;
}

void Level1::Update()
{
	p->Update();
	e->Update();
	o->Update();
	o2->Update();
	m->Update();

	

	if(Mix_PlayingMusic()==0)
	{
		if(!changed)
		{
			DEBUG_MSG("music1");
			Mix_PlayMusic(music,1);
		}
		if(changed)
		{
			DEBUG_MSG("music2");
			Mix_PlayMusic(music2,1);
		}
	}

	switch(p->cRow)
	{
	case 1:
		if(changed)
		{
				DEBUG_MSG(changed);

			
			Mix_HaltMusic();
			Mix_PlayMusic(music,1);
			
			changed = false;
		}
		break;
	case 2:
		if(!changed)
		{
			DEBUG_MSG(changed);
				
			Mix_HaltMusic();
			Mix_PlayMusic(music2,1);
			
			changed = true;
		}
		break;
	}

	//If Player meets enemy, new Woody Allen film, coming Sept 20Never
	if(SDL_HasIntersection(&p->getRect(), &e->getRect()))
	{
		Mix_PlayChannel(-1,effect1,0);
		SDL_Delay(100);
		p->position->setX(200.f);

		SceneManager::Instance()->setCurrent(4);
	}

	if(SDL_HasIntersection(&p->getRect(), &o->getRect()))
	{
		p->position->setY(o->position->gety()-p->ph);
	}
	if(SDL_HasIntersection(&p->getRect(), &o2->getRect()))
	{
		p->position->setY(o2->position->gety()-p->ph);
	}
}

void Level1::Draw()
{
	p->Draw();
	e->Draw();
	o->Draw();
	o2->Draw();
	m->Draw();
}