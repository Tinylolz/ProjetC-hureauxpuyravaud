#include "Phase_Invasion_Monstre.h"
#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "Monstre.h"
#include "fonction_affichage.h"
#include "Temps.h"
#include "Carte.h"
#include "constante.h"
#include "Menu_accueil.h"
#include "Phase_Achat.h"
#include "Jeu.h"
#include "Tourelle.h"
#include <vector>
#include <iostream>
#include<stdio.h>
#include"math.h"
using namespace std;


Phase_Invasion_Monstre::Phase_Invasion_Monstre(int i)
{
	numero_tour = i;
}


Phase_Invasion_Monstre::~Phase_Invasion_Monstre(void)
{
}

// Cette fonction est la fonction principale de lancement de la phase d'invasion des monstres ; elle prend en argument les différentes listes crées auparavant pendant 
// la phase achat
void Phase_Invasion_Monstre::jouer(SDL_Surface *screen, int z,int liste_tourelle_1[],int liste_coordonnee_x_1[],int liste_coordonnee_y_1[],int liste_degat_1[],double liste_ralentissement_1[],int l) // z est le numero de la carte choisie, 
{
	argent_gagner=0;
	numero_tour=l; // on récupère le numero du tour donné par la boucle principale dans "Jeu"
	monstre_a_envoyer(); // On initialise les caractéristiques des monstres du tour en cours
	SDL_Event event;																					
	Carte carte;
	bool quit = false;
	quit1 = false;

    Monstre monstre;
	int compteur; // Ce compteur est crée afin que les tourelles n'attaquent qu'une cible à la fois

    Temps fps; 

	monstre.reinitoffsets(z); // On initialise les positions de départ des monstres en fonction de la carte choisie
	monstre.initcaract(type_monstre);
	fps.start();  // On démarre l'horloge
	while (  ( quit == false )   && ( nombre_monstre_tour > 0) ) 
    {
        compteur =0;
		int y=0;
		for(y=0;y<20;y++)
		{
			if((type_monstre[y]==1)||(type_monstre[y]==2))
			{
		
				SDL_PollEvent( &event  );
				{
					
		   
					if( event.type == SDL_QUIT )
					{
			
						quit = true;
						quit1=true;
					}
			
				}
				if(y==0)
				{
					carte.carte_avec_tourelle(liste_coordonnee_x_1,liste_coordonnee_y_1,screen,z,liste_tourelle_1,numero_tour);
				}

				if ( (monstre.vie_monstre[y]>0) && (zone_finale(monstre.x[y],monstre.y[y],z)==0))
				{
					int s;
					if((fps.get_ticks()/1000)>temps_monstre[y])
					{
						monstre.handle_input(monstre.x[y], monstre.y[y], carte.carteretournerx(monstre.x[y],monstre.y[y],z), carte.carteretournery(monstre.x[y],monstre.y[y],z),y);
						monstre.move(y); // On bouge le monstre
	
						monstre.show(screen,type_monstre[y],y);
					}
					for(s=0;s<10;s++)
					{
						if ( ( liste_tourelle_1[s] == 1 ) || ( liste_tourelle_1[s] == 2 ) || ( liste_tourelle_1[s] == 3 ) || ( liste_tourelle_1[s] == 4 ) )
						{
							if (zone_degat_tourelle(liste_coordonnee_x_1[s],liste_coordonnee_y_1[s],monstre.x[y],monstre.y[y])==1)  // si le monstre est dans la zone de degat (cercle)
							{
								if( (fps.get_ticks()%10==0) && (compteur ==0)  ) // il reçoit des dégâts chaque 10 millisecondes
								{
									monstre.vie_monstre[y]-=liste_degat_1[s];	
									compteur=1;
								}

								monstre.move_ralenti(y,liste_ralentissement_1[s]); // lorsque le monstre est à proximité d'une tourelle ralentisseuse, on appelle l'autre fonction "move ralenti" pour bouger le monstre
								monstre.show(screen,type_monstre[y],y);
							}
						}
					 	
					}
					if (monstre.vie_monstre[y] <=0)
					{
						nombre_monstre_tour -=1; // dès qu'un monstre meurt, on retire 1 au compteur du nombre de monstre afin de terminer correctement la boucle while ci dessus
						argent_gagner+=50;
					}
					if ( (zone_finale(monstre.x[y],monstre.y[y],z)==1) )
					{
						nombre_monstre_tour -=1; // de même lorsqu'un monstre franchit la ligne d'arrivée
						vie_joueur-=1;
					}
				}
				SDL_Flip(screen);


			}
		}
		
    }

	fill_n(type_monstre, 20, 0); // on réinitialise les tableaux
	fill_n(temps_monstre, 20, 0);
}


// Fonction effrayante à premier vu mais incontournable pour définir les caractéristiques des vagues de monstres à chaque tour
void Phase_Invasion_Monstre::monstre_a_envoyer() // temps_monstre réprésente le temps de décalage en seconde (car tous les monstres n'apparaissent pas en même temps
{

	if (numero_tour == 0 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=1; nombre_monstre_tour=2;	}
	if (numero_tour == 1 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=1; type_monstre[2]=1;	temps_monstre[2]=2;	type_monstre[3]=2;	temps_monstre[3]=3; nombre_monstre_tour=4;	}
	if (numero_tour == 2 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3;nombre_monstre_tour=8;	}
	if (numero_tour == 3 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 4 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 5 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 6 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 7 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 8 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 9 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 10 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 11 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 12 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 13 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 14 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 15 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 16 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 17 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 18 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 19 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	if (numero_tour == 20 ){type_monstre[0]=1;	temps_monstre[0]=0;	type_monstre[1]=2;	temps_monstre[1]=0; type_monstre[2]=1;	temps_monstre[2]=1;	type_monstre[3]=2;	temps_monstre[3]=1; type_monstre[4]=1;	temps_monstre[4]=2;	type_monstre[5]=2;	temps_monstre[5]=2; type_monstre[6]=1;	temps_monstre[6]=3;	type_monstre[7]=2;	temps_monstre[7]=3; type_monstre[8]=1;	temps_monstre[8]=3.5;	type_monstre[9]=2;	temps_monstre[9]=3.5; nombre_monstre_tour=10;	}
	


}

int Phase_Invasion_Monstre::zone_degat_tourelle(int x, int y, double x_monstre, double y_monstre)
{

	if(   ( (x_monstre-x)*(x_monstre-x) + (y_monstre-y)*(y_monstre-y) ) < 100*100  )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Phase_Invasion_Monstre::zone_finale(double x, double y, int v)
{
	if(v==1)
	{
		if((x>65)&&(x<85)&&(y>630)&&(y<675))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if(v==2)
	{
		if((x>655)&&(x<675)&&(y>521)&&(y<541))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if(v==3)
	{
		if((x>317)&&(x<337)&&(y>655)&&(y<675))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

}