#pragma once
#include"constante.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>
#include "Monstre.h"
#include "fonction_affichage.h"
#include "Temps.h"
#include "Menu_accueil.h"

SDL_Surface *screen = NULL;


int main( int argc, char* args[] )
{


	TTF_Init(); // Lancement de SDL

	SDL_WM_SetCaption( "Tower defense", NULL );
 
	screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
	bool quitmenu=false;
	bool quitregle=false;
	bool quitcommande1=false;
	bool quitcommande2=false;
	bool quitjouer=false;


    Menu_accueil menu; // Lancement du menu principal afin de lancer le jeu

    menu.page_accueil(screen,quitmenu,quitregle,quitcommande1,quitcommande2,quitjouer);

    TTF_Quit(); // Fermeture de SDL

    return 0;
}

