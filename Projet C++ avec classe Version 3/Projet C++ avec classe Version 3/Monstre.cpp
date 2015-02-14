#include "SDL.h"
#include "SDL_image.h"
#include "Monstre.h"
#include"constante.h"
#include "fonction_affichage.h"
#include "Carte.h"

Monstre::Monstre()
{    
	sprite_monstre_fantome = load_image( "fantome_transparence.bmp" );
	sprite_monstre_troll = load_image( "troll.bmp" );
	
}
SDL_Surface* Monstre::afficher_monstre(int a)
{	
	if (a == 1)
	{
		return sprite_monstre_fantome;
	}
	if (a == 2)
	{
		return sprite_monstre_troll;
	}
}


Monstre::~Monstre(void)
{
}


// Fonction qui initialise les positions des monstres en fonction de la carte choisie
void Monstre::reinitoffsets(int z)
{
	int p;
	for(p=0;p<=19;p++)
	{
		if(z==1)
		{
			x[p]=116;
			y[p]=0;
		}
		if(z==2)
		{
			y[p]=531;
			x[p]=0;
		}
		if(z==3)
		{
			y[p]=665;
			x[p]=230;
		}
	}

}
void Monstre::initcaract(int liste[]) // l'entrée est la liste de type des monstres
{
	int p;
	for(p=0;p<=19;p++)
	{
		if(liste[p]==1)
		{
			Vel[p]=2;
			vie_monstre[p]=150;

		}
		if(liste[p]==2)
		{
			Vel[p]=1;
			vie_monstre[p]=300;
		}
	}

}

// C'est cette fonction qui permet de modifier la vitesse du monstre
void Monstre::handle_input(double a, double b, int c, int d,int k)
{
	if((a!=c)||(b!=d))
	{
	    if( (c > a) && (xVel[k]<=0))
		{
			xVel[k] = Vel[k];      
	    }
	    if( (c < a) && (xVel[k]>=0))
		{
		     xVel[k]= -Vel[k]; 
	    }
		
		if( (a == c))
		{
		        xVel[k] = 0; 
		}

		if( (d > b) && (yVel[k]<=0))
		{
		      yVel[k] = Vel[k];
	    }

		if( (d < b) && (yVel[k]>=0))
		{
		        yVel[k] = -Vel[k]; 
		}

		if( (d == b))
		{	
		        yVel[k] = 0; 
		}
	}
	if((a==c)&&(b==d))
	{
		xVel[k] =0 ;
		yVel[k] =0;
	}
}


// Fonction qui permet de faire bouger le monstre prenant en compte sa vitesse et sa position défini auparavant
void Monstre::move(int k) // k est le numero du monstre (emplacement k dans la liste x[20])
{
  
    x[k] += xVel[k];

  
    if( ( x[k] < 0 ) || ( x[k] + DOT_WIDTH > SCREEN_WIDTH ) )
    {
       
        x[k] -= xVel[k];
    }

    
    y[k] += yVel[k];

 
    if( ( y[k] < 0 ) || ( y[k] + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
      
        y[k] -= yVel[k];
    }
}

void Monstre::move_ralenti(int k,double b) // k est le numero du monstre (emplacement k dans la liste x[20])
{

	if(xVel[k]>0)
	{
		 x[k] = x[k]-b;
	}


    if(xVel[k]<0)
	{
		x[k]= x[k]+ b;
	}



 	if(yVel[k]>0)
	{
		y[k]= y[k]- b;
	}


 	if(yVel[k]<0)
	{
		y[k]= y[k]+ b;
	}

}

void Monstre::show(SDL_Surface * screen,int a,int k)
{

    apply_surface( x[k], y[k], afficher_monstre(a), screen );
}

