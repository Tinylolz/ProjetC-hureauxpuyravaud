#include "Phase_Achat.h"
#include "SDL.h"
#include "SDL_image.h"
#include "fonction_affichage.h"
#include "Phase_Invasion_Monstre.h"
#include "Carte.h"
#include "Jeu.h"
#include "Tourelle.h"
#include "SDL_ttf.h"
#include "constante.h"
#include <sstream>


Phase_Achat::Phase_Achat(int i, int m) // i représente la i-ème étape achat du jeu ; m est la vie du joueur
{
	menu_choix_achat = IMG_Load("menu_choix_achat.bmp");
	menu_achat_tourelle = IMG_Load("menu_achat_tourelle.bmp");
	menu_achat_amelioration = IMG_Load("menu_achat_amelioration.bmp");
	numero_tour = i;
	vie_joueur =m;
	
}


Phase_Achat::~Phase_Achat(void)
{
}

// Fonction principale qui permet de lancer la phase achat, en actualisant les valeurs d'argent et de vie du joueur
void Phase_Achat::lancement(SDL_Surface *screen,int z,int k,int u,int w)
{
	SDL_Event event;
	argent_joueur+=w;
	vie_joueur=u;
	quit2=false;
	bool quit = false;
	numero_tour = k;
	
	while (quit == false)
	{
		apply_surface(0, 0, menu_choix_achat, screen);
		
		SDL_Flip(screen);
		  SDL_PollEvent( &event );
			 switch(event.type)
			 {
			 case SDL_QUIT:
				 quit = true;
				 quit2=true;
			 case SDL_MOUSEBUTTONDOWN:
				 if (event.button.button == SDL_BUTTON_LEFT) 
				 {
					 if ((180<event.button.x ) && (event.button.x<310 ) && (100<event.button.y) && (event.button.y<280)) // Bouton ne rien acheter
					 {
							quit=true;

							liste_degat[numero_tour]=0;
							liste_ralentissement[numero_tour]=0;
							liste_tourelle [numero_tour]=1;
							liste_coordonnee_x [numero_tour]=5000;
							liste_coordonnee_y [numero_tour]=5000;


					 
					 }
					 if ((390<event.button.x ) && (event.button.x<570 ) && (100<event.button.y) && (event.button.y<280)) // Bouton achat tourelle
					 {
							quit=true;	
							page_achat_tourelle(screen,z);
					 
					 }
					 if ((240<event.button.x ) && (event.button.x<415 ) && (380<event.button.y) && (event.button.y<510)) // Bouton amélioration tourelle
					 {
							quit=true;		
							page_amelioration_tourelle(screen,z);
					 
					 }
				 }
			 }
	}
}

void Phase_Achat::page_achat_tourelle(SDL_Surface *screen,int z)
{
	SDL_Event event;
	quit2=false;
	Tourelle tourelle;
	TTF_Font *font;
	font = TTF_OpenFont("komikax.ttf",20);
	SDL_Color textColor = { 255, 0, 0 };
	stringstream s;
	s << "Argent : " << argent_joueur << "        Vie : " << vie_joueur;
	message = TTF_RenderText_Solid(font, s.str().c_str() , textColor);
	bool quit = false;

	while (quit == false)
	{
		apply_surface(0, 0, menu_achat_tourelle, screen);
		apply_surface(200,100,message,screen);
		SDL_Flip(screen);
		  SDL_PollEvent( &event );
			 switch(event.type)
			 {
			 case SDL_QUIT:
				 quit = true;
				 quit2=true;
			 case SDL_MOUSEBUTTONDOWN:
				 if (event.button.button == SDL_BUTTON_LEFT) 
				 {
					 if ( ((115<event.button.x ) && (event.button.x<215 ) && (210<event.button.y) && (event.button.y<305))  && ( argent_joueur >= 200 ) )	// Bouton tourelle dégâts
					 {
							quit=true;		 
							argent_joueur -= 300;
							tourelle.placement_tourelle(screen,z,1,numero_tour,liste_tourelle,liste_coordonnee_x,liste_coordonnee_y); // Ici, on crée une tourelle et on range dans plusieurs 
							tourelle.caract_tourelle(1,numero_tour);																  // listes, les différentes caractéristiques de la tourelle crée
							liste_degat[numero_tour]=tourelle.liste_degat[numero_tour];
							liste_ralentissement[numero_tour]=tourelle.liste_ralentissement[numero_tour];
							liste_tourelle [numero_tour]=tourelle.liste_tourelle[numero_tour];
							liste_coordonnee_x [numero_tour]=tourelle.liste_coordonnee_x[numero_tour];
							liste_coordonnee_y [numero_tour]=tourelle.liste_coordonnee_y[numero_tour];
					 }
					 if ((120<event.button.x ) && (event.button.x<210 ) && (360<event.button.y) && (event.button.y<460) && ( argent_joueur >= 200 ) ) // Bouton tourelle ralentisseuse
					 {
							quit=true;		
							argent_joueur -= 300;
							tourelle.placement_tourelle(screen,z,2,numero_tour,liste_tourelle,liste_coordonnee_x,liste_coordonnee_y);
							tourelle.caract_tourelle(2,numero_tour);
							liste_degat[numero_tour]=tourelle.liste_degat[numero_tour];
							liste_ralentissement[numero_tour]=tourelle.liste_ralentissement[numero_tour];
							liste_tourelle [numero_tour]=tourelle.liste_tourelle[numero_tour];
							liste_coordonnee_x [numero_tour]=tourelle.liste_coordonnee_x[numero_tour];
							liste_coordonnee_y [numero_tour]=tourelle.liste_coordonnee_y[numero_tour];
					 }
					 if ((245<event.button.x ) && (event.button.x<425 ) && (545<event.button.y) && (event.button.y<660)) // Bouton précédent
					 {
							quit=true;	
							lancement(screen,z,numero_tour,vie_joueur,0);
					 
					 }
				 }
			 }
	}
}

void Phase_Achat::page_amelioration_tourelle(SDL_Surface *screen,int z)
{
	SDL_Event event;
	quit2=false;
	Tourelle tourelle;
	TTF_Font *font;
	font = TTF_OpenFont("komikax.ttf",20);
	SDL_Color textColor = { 255, 0, 0 };
	stringstream s;
	s << "Argent : " << argent_joueur << "        Vie : " << vie_joueur;
	message = TTF_RenderText_Solid(font, s.str().c_str() , textColor);

	bool quit = false;

	while (quit == false)
	{
		apply_surface(0, 0, menu_achat_amelioration, screen);
		apply_surface(200,100, message, screen);
		SDL_Flip(screen);
		  SDL_PollEvent( &event );
			 switch(event.type)
			 {
			 case SDL_QUIT:
				 quit = true;
				 quit2=true;
			 case SDL_MOUSEBUTTONDOWN:
				 if (event.button.button == SDL_BUTTON_LEFT) 
				 {
					 if ((115<event.button.x ) && (event.button.x<215 ) && (210<event.button.y) && (event.button.y<305) && ( argent_joueur >= 500 )) // Bouton tourelle dégâts V2
					 {
							argent_joueur -= 600;
							tourelle.placement_tourelle(screen,z,3,numero_tour,liste_tourelle,liste_coordonnee_x,liste_coordonnee_y);
							tourelle.caract_tourelle(3,numero_tour);
							liste_degat[numero_tour]=tourelle.liste_degat[numero_tour];
							liste_ralentissement[numero_tour]=tourelle.liste_ralentissement[numero_tour];
							liste_tourelle [numero_tour]=tourelle.liste_tourelle[numero_tour];
							liste_coordonnee_x [numero_tour]=tourelle.liste_coordonnee_x[numero_tour];
							liste_coordonnee_y [numero_tour]=tourelle.liste_coordonnee_y[numero_tour];
							quit=true;	
					 
					 }
					 if ((120<event.button.x ) && (event.button.x<210 ) && (360<event.button.y) && (event.button.y<460) && ( argent_joueur >= 500 )) // Bouton tourelle ralentisseuse V2
					 {
							quit=true;		
							argent_joueur -= 800;
							tourelle.placement_tourelle(screen,z,4,numero_tour,liste_tourelle,liste_coordonnee_x,liste_coordonnee_y);
							tourelle.caract_tourelle(4,numero_tour);
							liste_degat[numero_tour]=tourelle.liste_degat[numero_tour];
							liste_ralentissement[numero_tour]=tourelle.liste_ralentissement[numero_tour];
							liste_tourelle [numero_tour]=tourelle.liste_tourelle[numero_tour];
							liste_coordonnee_x [numero_tour]=tourelle.liste_coordonnee_x[numero_tour];
							liste_coordonnee_y [numero_tour]=tourelle.liste_coordonnee_y[numero_tour];
					 }
					 if ((245<event.button.x ) && (event.button.x<425 ) && (545<event.button.y) && (event.button.y<660)) // Bouton précédent
					 {
							quit=true;	
							lancement(screen,z,numero_tour,vie_joueur,0);
					 
					 }
				 }
			 }
	}
}

