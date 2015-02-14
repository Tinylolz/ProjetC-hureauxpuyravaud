#pragma once
#include "SDL.h"
#include "SDL_image.h"


class Phase_Achat
{
public:
	Phase_Achat(int,int);
	~Phase_Achat(void);
	void lancement(SDL_Surface *screen,int,int,int,int);
	void page_achat_tourelle(SDL_Surface *screen,int);
	void page_amelioration_tourelle(SDL_Surface *screen,int);

	int xplacement;
	int yplacement;
	int numero_tour;
	int liste_tourelle [10];
	int liste_coordonnee_x [10];
	int liste_coordonnee_y [10];
	int liste_degat [10];
	double liste_ralentissement[10];
	int argent_joueur;
	int vie_joueur;
	bool quit2;

private:

	SDL_Surface *menu_choix_achat;
	SDL_Surface *menu_achat_tourelle;
	SDL_Surface *menu_achat_amelioration;
	SDL_Surface *message;
};

