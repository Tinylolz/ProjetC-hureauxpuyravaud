#include "Menu_accueil.h"
#include "SDL.h"
#include "SDL_image.h"
#include "fonction_affichage.h"
#include "Jeu.h"
#include "Carte.h"


Menu_accueil::Menu_accueil(void)
{
	menu_accueil = IMG_Load("menu_accueil.bmp");
	sprite_background = IMG_Load( "arriere_plan_1.bmp" );
	sprite_regle = IMG_Load("page_regle.bmp");
	sprite_commande_1 = IMG_Load("page_commande_1.bmp");
	sprite_commande_2 = IMG_Load("page_commande_2.bmp");
	sprite_choix_carte = IMG_Load("page_choix_carte.bmp");
}


Menu_accueil::~Menu_accueil(void)
{
}

// Cette première fonction affiche la première page d'accueil permettant soit de jouer soit de lire les régles du jeu.
void Menu_accueil::page_accueil(SDL_Surface *screen,bool quitmenu,bool quitregle,bool quitcommande1,bool quitcommande2,bool quitjouer)
{
	SDL_Event event;
	while (quitmenu == false)
	{
		apply_surface(0, 0, menu_accueil, screen);
		SDL_Flip(screen);
		 SDL_PollEvent( &event );
			 switch(event.type)
			 {
			 case SDL_QUIT:
				 quitmenu = true;
			 case SDL_MOUSEBUTTONDOWN:
				 if (event.button.button == SDL_BUTTON_LEFT) 
				 {
					 if ((100<event.button.x ) && (event.button.x<285 ) && (130<event.button.y) && (event.button.y<225)) // Bouton Jouer
					 {
						quitmenu=true;
						page_choix_carte(screen,quitmenu,quitregle,quitcommande1,quitcommande2,quitjouer);
					 
					 }
					 if ((100<event.button.x ) && (event.button.x<285 ) && (270<event.button.y) && (event.button.y<375)) // bouton "Règles & Commandes" : accède à la page règle
					 {
							quitmenu=true;
							quitregle=false;
							 page_regle(screen,quitmenu,quitregle,quitcommande1,quitcommande2,quitjouer);	 
					 
					 }
					 if ((100<event.button.x ) && (event.button.x<285 ) && (415<event.button.y) && (event.button.y<510)) // bouton quitter
					 {
							quitmenu=true;
							 
					 
					 }
				 }
				 
			 }
		 
	}
}

void::Menu_accueil::page_regle(SDL_Surface *screen,bool quitmenu,bool quitregle,bool quitcommande1,bool quitcommande2,bool quitjouer)
{
	SDL_Event event;
	while (quitregle == false)
	{
		apply_surface(0, 0, sprite_regle, screen);
		SDL_Flip(screen);
		  SDL_PollEvent( &event );
			 switch(event.type)
			 {
			 case SDL_QUIT:
				 quitregle = true;
			 case SDL_MOUSEBUTTONDOWN:
				 if (event.button.button == SDL_BUTTON_LEFT) 
				 {
					 if ((30<event.button.x ) && (event.button.x<200 ) && (570<event.button.y) && (event.button.y<680)) // bouton retour au menu
					 {
							quitregle=true;
							quitmenu=false;
							 page_accueil(screen,quitmenu,quitregle,quitcommande1,quitcommande2,quitjouer);	 
					 
					 }
					 if ((480<event.button.x ) && (event.button.x<650 ) && (570<event.button.y) && (event.button.y<680)) // bouton pour accéder à la page commande 1
					 {
							quitregle=true;
							quitcommande1=false;
							 page_commande_1(screen,quitmenu,quitregle,quitcommande1,quitcommande2,quitjouer);	 
					 
					 }

				 }
				 
			 }
	}
}

void::Menu_accueil::page_commande_1(SDL_Surface *screen,bool quitmenu,bool quitregle,bool quitcommande1,bool quitcommande2,bool quitjouer)
{
	SDL_Event event;
	while (quitcommande1 == false)
	{
		apply_surface(0, 0, sprite_commande_1, screen);
		SDL_Flip(screen);
		  SDL_PollEvent( &event );
			 switch(event.type)
			 {
			 case SDL_QUIT:
				 quitcommande1 = true;
			 case SDL_MOUSEBUTTONDOWN:
				 if (event.button.button == SDL_BUTTON_LEFT) 
				 {
					 if ((30<event.button.x ) && (event.button.x<200 ) && (570<event.button.y) && (event.button.y<680)) // Bouton pour retour au menu
					 {
							quitcommande1=true;
							quitmenu=false;
							 page_accueil(screen,quitmenu,quitregle,quitcommande1,quitcommande2,quitjouer);	 
					 
					 }
					 if ((480<event.button.x ) && (event.button.x<650 ) && (570<event.button.y) && (event.button.y<680)) // Bouton pour accéder à la page commande 2
					 {
							quitcommande1=true;
							quitcommande2=false;
							 page_commande_2(screen,quitmenu,quitregle,quitcommande1,quitcommande2,quitjouer);	 
					 
					 }

				 }
				 
			 }
	}
}

void::Menu_accueil::page_commande_2(SDL_Surface *screen,bool quitmenu,bool quitregle,bool quitcommande1,bool quitcommande2,bool quitjouer)
{
	SDL_Event event;
	while (quitcommande2 == false)
	{
		apply_surface(0, 0, sprite_commande_2, screen);
		SDL_Flip(screen);
		  SDL_PollEvent( &event );
			 switch(event.type)
			 {
			 case SDL_QUIT:
				 quitcommande2 = true;
			 case SDL_MOUSEBUTTONDOWN:
				 if (event.button.button == SDL_BUTTON_LEFT) 
				 {
					 if ((230<event.button.x ) && (event.button.x<410 ) && (590<event.button.y) && (event.button.y<695)) // Bouton pour retour au menu
					 {
							quitcommande2=true;
							quitmenu=false;
							 page_accueil(screen,quitmenu,quitregle,quitcommande1,quitcommande2,quitjouer);	 
					 
					 }

				 }
				 
			 }
	}
}
// C'est cette fonction qui va lancer la boucle principale de jeu après avoir sélectionner la carte sur laquelle on voulait jouer
void::Menu_accueil::page_choix_carte(SDL_Surface *screen,bool quitmenu,bool quitregle,bool quitcommande1,bool quitcommande2,bool quitjouer)
{
	SDL_Event event;
	while (quitjouer == false)
	{
		apply_surface(0, 0, sprite_choix_carte, screen);
		SDL_Flip(screen);
		  SDL_PollEvent( &event );
			 switch(event.type)
			 {
			 case SDL_QUIT:
				 quitjouer = true;
			 case SDL_MOUSEBUTTONDOWN:
				 if (event.button.button == SDL_BUTTON_LEFT) 
				 {
					 if ((100<event.button.x ) && (event.button.x<310 ) && (180<event.button.y) && (event.button.y<380)) // Bouton carte 1
					 {
							quitjouer=true;
							Jeu jeu;
							jeu.jouer(screen,1);
							
 
					 
					 }
					 if ((390<event.button.x ) && (event.button.x<600 ) && (180<event.button.y) && (event.button.y<380)) // Bouton carte 2
					 {
							quitjouer=true;
							Jeu jeu;
							jeu.jouer(screen,2);

							
 
					 
					 }
					 if ((235<event.button.x ) && (event.button.x<445 ) && (440<event.button.y) && (event.button.y<650)) // Bouton carte 3
					 {
							quitjouer=true;
							Jeu jeu;
							jeu.jouer(screen,3);
							
 
					 
					 }

				 }
				 
			 }
	}
}