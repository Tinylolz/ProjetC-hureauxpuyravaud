#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Jeu
{
public:
	Jeu(void);
	~Jeu(void);
	void jouer(SDL_Surface *screen,int);
	int i; // compteur du tour
};

