#include "Tourelle.h"
#include "SDL.h"
#include "SDL_image.h"
#include "fonction_affichage.h"
#include "Carte.h"
#include <vector>
#include <iostream>
using namespace std;
#include "Phase_Invasion_Monstre.h"
#include "Jeu.h"
#include<stdio.h>
#include"math.h"
#include <string>


Tourelle::Tourelle()
{
	image_tourelle_degat_1=load_image("Tourelle_degat_1.bmp");
	image_tourelle_degat_2=load_image("Tourelle_degat_2.bmp");
	image_tourelle_slow_1=load_image("Tourelle_slow_1.bmp");
	image_tourelle_slow_2=load_image("Tourelle_slow_2.bmp");
	transparence=load_image("transparence.bmp");
}


Tourelle::~Tourelle(void)
{
}

 SDL_Surface *Tourelle::type_tourelle(int a) 
{
	if (a==1)
	{
		return image_tourelle_degat_1;
	}
	if (a==2)
	{
		return image_tourelle_slow_1;
	}
	if (a==3)
	{
		return image_tourelle_degat_2;
	}
	if (a==4)
	{
		return image_tourelle_slow_2;
	}
} 


void Tourelle::show(SDL_Surface * screen,int a)
{

    apply_surface( x, y, type_tourelle(a), screen );

}

// C'est cette fonction qui permet de placer la tourelle sur la carte en s'assurant que la position choisie est hors du chemin ; on retient ensuite ses 
// coordonnées ainsi que son type dans une liste.
void Tourelle::placement_tourelle(SDL_Surface *screen, int z, int a,int numero_tour,int liste1[],int liste2[],int liste3[])
{
	SDL_Event event;
	 Carte carte;
	 int x1=0;
	 int y1=0;
	 bool quit = false;
	  while( quit == false )
	  {
		  
		  SDL_PollEvent( &event );
		  {
			  if (event.type == SDL_MOUSEMOTION)
			  {
				  x1=event.motion.x;
				  y1=event.motion.y;


			  }
			  if( event.type == SDL_QUIT )
				{
					quit = true;
				}
			 if((coordonneeestsurlechemin(x1,y1,z)==0)&&(coordonneeestsurlechemin(x1+40,y1+58,z)==0)&&(coordonneeestsurlechemin(x1+40,y1,z)==0)&&(coordonneeestsurlechemin(x1,y1+58,z)==0)&&(coordonneeestsurlechemin(x1+20,y1+29,z)==0))
			 {
				  if (event.type == SDL_MOUSEBUTTONDOWN)
				  {
					  if (event.button.button == SDL_BUTTON_LEFT) 
					  {
							liste_tourelle[numero_tour]=a;
							liste_coordonnee_x[numero_tour]=x1;
							liste_coordonnee_y[numero_tour]=y1;
							quit=true;
					 
					  }
				  }

			  }
			  if(numero_tour>0)
			  {
			  carte.carte_avec_tourelle(liste2,liste3,screen,z,liste1,numero_tour-1);
			  apply_surface(x1,y1,type_tourelle(a),screen);
			  SDL_Flip(screen);
			  }
			  else if (numero_tour == 0)
			  {
				  apply_surface(0,0,carte.choix_carte(z),screen);
				  apply_surface(x1,y1,type_tourelle(a),screen);
				  SDL_Flip(screen);
			  }
		  }
	  }
}

void Tourelle::ajout_tourelle_liste(int a,int numero_tour)
{
	liste_tourelle[numero_tour]=a;
}

void Tourelle::ajout_liste_coordonnee_x(int x,int numero_tour)
{
	liste_coordonnee_x[numero_tour]=x;
}

void Tourelle::ajout_liste_coordonnee_y(int y,int numero_tour)
{
	liste_coordonnee_y[numero_tour]=y;
}
 // Cette fonction permet de s'assurer que la tourelle à poser est bien hors du chemin   
int Tourelle::coordonneeestsurlechemin(int x,int y,int z1)
{
	
	if(z1==1)
	{
		if((x>115)&&(x<150)&&(y>0)&&(y<236))
		{
			return 1;
		}
		if((x>115)&&(x<337)&&(y>202)&&(y<236))
		{
			return 1;
		}
		if((x>302)&&(x<337)&&(y>108)&&(y<236))
		{
			return 1;
		}
		if((x>192)&&(x<337)&&(y>108)&&(y<144))
		{
			return 1;
		}
		if((x>192)&&(x<227)&&(y>29)&&(y<144))
		{
			return 1;
		}
		if((x>192)&&(x<490)&&(y>29)&&(y<65))
		{
			return 1;
		}
		if((x>455)&&(x<490)&&(y>29)&&(y<309))
		{
			return 1;
		}
		if((x>455)&&(x<600)&&(y>275)&&(y<309))
		{
			return 1;
		}
		if((x>566)&&(x<600)&&(y>275)&&(y<488))
		{
			return 1;
		}
		if((x>393)&&(x<600)&&(y>454)&&(y<488))
		{
			return 1;
		}
		if((x>393)&&(x<428)&&(y>373)&&(y<488))
		{
			return 1;
		}
		if((x>75)&&(x<428)&&(y>373)&&(y<408))
		{
			return 1;
		}
		if((x>75)&&(x<109)&&(y>373)&&(y<700))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(z1==2)
	{
		if((x>0)&&(x<136)&&(y>532)&&(y<567))
		{
			return 1;
		}
		if((x>101)&&(x<136)&&(y>141)&&(y<567))
		{
			return 1;
		}
		if((x>101)&&(x<211)&&(y>141)&&(y<176))
		{
			return 1;
		}
		if((x>176)&&(x<211)&&(y>141)&&(y<590))
		{
			return 1;
		}
		if((x>176)&&(x<319)&&(y>554)&&(y<590))
		{
			return 1;
		}
		if((x>284)&&(x<319)&&(y>346)&&(y<590))
		{
			return 1;
		}
		if((x>284)&&(x<412)&&(y>346)&&(y<382))
		{
			return 1;
		}
		if((x>377)&&(x<412)&&(y>346)&&(y<489))
		{
			return 1;
		}
		if((x>377)&&(x<487)&&(y>454)&&(y<489))
		{
			return 1;
		}
		if((x>452)&&(x<487)&&(y>68)&&(y<489))
		{
			return 1;
		}
		if((x>452)&&(x<575)&&(y>68)&&(y<104))
		{
			return 1;
		}
		if((x>540)&&(x<575)&&(y>68)&&(y<567))
		{
			return 1;
		}
		if((x>540)&&(x<700)&&(y>532)&&(y<567))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	if(z1==3)
	{
		if((x>230)&&(x<265)&&(y>518)&&(y<700))
		{
			return 1;
		}
		if((x>110)&&(x<265)&&(y>518)&&(y<616))
		{
			return 1;
		}
		if((x>110)&&(x<145)&&(y>368)&&(y<616))
		{
			return 1;
		}
		if((x>38)&&(x<145)&&(y>368)&&(y<403))
		{
			return 1;
		}
		if((x>38)&&(x<73)&&(y>295)&&(y<403))
		{
			return 1;
		}
		if((x>38)&&(x<73)&&(y>295)&&(y<330))
		{
			return 1;
		}
		if((x>38)&&(x<145)&&(y>295)&&(y<330))
		{
			return 1;
		}
		if((x>110)&&(x<145)&&(y>100)&&(y<330))
		{
			return 1;
		}
		if((x>110)&&(x<262)&&(y>100)&&(y<134))
		{
			return 1;
		}
		if((x>227)&&(x<262)&&(y>31)&&(y<134))
		{
			return 1;
		}
		if((x>227)&&(x<382)&&(y>31)&&(y<67))
		{
			return 1;
		}
		if((x>348)&&(x<382)&&(y>31)&&(y<159))
		{
			return 1;
		}
		if((x>348)&&(x<512)&&(y>124)&&(y<159))
		{
			return 1;
		}
		if((x>478)&&(x<512)&&(y>124)&&(y<394))
		{
			return 1;
		}
		if((x>478)&&(x<612)&&(y>359)&&(y<394))
		{
			return 1;
		}
		if((x>577)&&(x<612)&&(y>359)&&(y<495))
		{
			return 1;
		}
		if((x>415)&&(x<612)&&(y>460)&&(y<495))
		{
			return 1;
		}
		if((x>415)&&(x<450)&&(y>460)&&(y<613))
		{
			return 1;
		}
		if((x>326)&&(x<450)&&(y>578)&&(y<613))
		{
			return 1;
		}
		if((x>326)&&(x<362)&&(y>578)&&(y<700))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

}

// Cette fonction permet d'actualiser les listes des différentes caractéristiques des tourelles : soit un ralentissement, soit un dégât.
void Tourelle::caract_tourelle(int a,int i)
{

	if(a==1)
	{
		liste_degat[i]=10;
		liste_ralentissement[i]=0;
	}
	if(a==2)
	{
		liste_degat[i]=0;
		liste_ralentissement[i]=0.5;
	}
	if(a==3)
	{
		liste_degat[i]=30;
		liste_ralentissement[i]=0;
	}
	if(a==4)
	{
		liste_degat[i]=0;
		liste_ralentissement[i]=0.8;
	}

}

