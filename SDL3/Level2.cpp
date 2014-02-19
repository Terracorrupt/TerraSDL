#include "Level2.h"

Level2::Level2(SDL_Renderer* r)
{
	//Variable Decleration
	e = new Enemy(r);
	e2 = new Enemy(r);
	e3 = new Enemy(r);
	m = new Obstacle(r);

	//Image Loading, LoadDupe so we dont load same image twice, save memory
	e->Load("images/floaty.png","2",400.0f,400.0f,42,50);
	e2->LoadDupe("2",600.0f,450.0f,42,50,70);
	e3->LoadDupe("2",600.0f,250.0f,42,50,200);
	m->Load("images/explain2.png","6",50.0f,50.f,300,300);

	//Open Audio
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096);
	music = Mix_LoadMUS("audio/Speception.wav");
	Mix_HaltMusic();
	Mix_PlayMusic(music,1);
}

Level2::~Level2()
{
	Mix_FreeMusic(music);
	Mix_FreeChunk(effect1);
	Mix_CloseAudio();
	delete e, e2, e3, m;
}

void Level2::Update()
{
	e->Update();
	e2->Update();
	e3->Update(true);
	m->Update();

	if(Mix_PlayingMusic()==0)
	{
		Mix_PlayMusic(music,1);
	}
}

void Level2::Draw()
{
	e->Draw();
	e2->Draw();
	e3->Draw();
	m->Draw();
}