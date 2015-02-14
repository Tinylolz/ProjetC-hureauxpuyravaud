#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <iostream>
using namespace std;

class Tourelle
{
public:
	Tourelle();
	~Tourelle(void);
	void show(SDL_Surface * screen,int);
	SDL_Surface *type_tourelle(int) ;
	void placement_tourelle(SDL_Surface *screen,int,int,int,int [],int [],int []);
	void ajout_tourelle_liste(int,int);
	void ajout_liste_coordonnee_x(int,int);
	void ajout_liste_coordonnee_y(int,int);
	int coordonneeestsurlechemin(int ,int ,int);
	void caract_tourelle(int,int);

	int liste_tourelle [10];
	int liste_coordonnee_x [10];
	int liste_coordonnee_y [10];	
	int x , y;
	int liste_degat[10];
	double liste_ralentissement[10];

private :

	SDL_Surface *image_tourelle_degat_1;
	SDL_Surface *image_tourelle_degat_2;
	SDL_Surface *image_tourelle_slow_1;
	SDL_Surface *image_tourelle_slow_2;
	SDL_Surface *transparence;
	

};

