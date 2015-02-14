#include "Jeu.h"
#include "SDL.h"
#include "SDL_image.h"
#include "Phase_Achat.h"
#include "Phase_Invasion_Monstre.h"
#include "Carte.h"
#include "Tourelle.h"


Jeu::Jeu(void)
{
}


Jeu::~Jeu(void)
{
}
// Classe principale du jeu, constituée d'une succession de phase achat et de phase d'invasion des monstres ; tant que la vie du joueur est strictement positive
void Jeu::jouer(SDL_Surface *screen,int z) // z est le numero de la carte choisie
{
	i=0;
	Phase_Invasion_Monstre phase_invasion_monstre(i); // Ici, on initialise les 2 phases de jeu
	phase_invasion_monstre.vie_joueur=20;
	Phase_Achat phase_achat(i,phase_invasion_monstre.vie_joueur);
	phase_achat.argent_joueur=1000; // Le joueur début avec 1000 OR et 20 points de vie
	phase_invasion_monstre.argent_gagner=0;
	
	Carte carte;
	SDL_Event event;
	phase_invasion_monstre.quit1 = false;
	phase_achat.quit2 = false;

	while ( (i<=20) && (phase_invasion_monstre.quit1 == false) && (phase_invasion_monstre.vie_joueur > 0 ) && (phase_achat.quit2 == false))
	{
		
		phase_achat.lancement(screen,z,i,phase_invasion_monstre.vie_joueur,phase_invasion_monstre.argent_gagner);

		if(phase_achat.quit2 == true)
		{
			break;
		}
		phase_invasion_monstre.jouer(screen,z,phase_achat.liste_tourelle,phase_achat.liste_coordonnee_x,phase_achat.liste_coordonnee_y,phase_achat.liste_degat,phase_achat.liste_ralentissement,i);
		
		i++;
	}

	




}