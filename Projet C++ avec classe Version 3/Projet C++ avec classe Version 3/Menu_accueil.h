#pragma once
#include "SDL.h"
#include "SDL_image.h"
class Menu_accueil
{
public:
	Menu_accueil(void);
	~Menu_accueil(void);
	void page_accueil(SDL_Surface *screen, bool,bool,bool,bool,bool);
	void page_regle(SDL_Surface *screen,bool,bool,bool,bool,bool);
	void page_commande_1(SDL_Surface *screen,bool,bool,bool,bool,bool);
	void page_commande_2(SDL_Surface *screen,bool,bool,bool,bool,bool);
	void page_choix_carte(SDL_Surface *screen,bool,bool,bool,bool,bool);

	

private:
	SDL_Surface *menu_accueil;
	SDL_Surface *sprite_background;
	SDL_Surface *sprite_regle;
	SDL_Surface *sprite_commande_1;
	SDL_Surface *sprite_commande_2;
	SDL_Surface *sprite_choix_carte;

};

