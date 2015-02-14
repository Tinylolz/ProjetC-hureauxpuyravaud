#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include <iostream>
using namespace std;

class Phase_Invasion_Monstre
{
public:
	Phase_Invasion_Monstre(int);
	~Phase_Invasion_Monstre(void);
	
	void jouer(SDL_Surface *screen,int,int liste_tourelle[],int liste_coordonnee_x[],int liste_coordonnee_y[],int liste_degat[],double liste_ralentissement[],int);
	void monstre_a_envoyer();
	int zone_finale(double , double , int);
	int zone_degat_tourelle(int, int, double, double);

	int numero_tour;
	bool quit1;
	int vie_joueur;
	int type_monstre[20];
	int temps_monstre[20]; 	
	int nombre_monstre_tour;	
	int argent_gagner;

};

