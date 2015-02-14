#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <iostream>
using namespace std;

class Carte
{
public:
	Carte(void);
	~Carte(void);
	void carte_avec_tourelle(int liste_coordonnee_x[],int liste_coordonnee_y[],SDL_Surface *screen, int,int liste_tourelle[],int);
	SDL_Surface *choix_carte(int);

	int carteretournerx(double,double,int);
	int carteretournery(double,double,int);
	int numero_carte;
	int coordonnee_finale_x(int);
	int coordonnee_finale_y(int);



private:
	
	SDL_Surface *background_1;
	SDL_Surface *background_2;
	SDL_Surface *background_3;

};

