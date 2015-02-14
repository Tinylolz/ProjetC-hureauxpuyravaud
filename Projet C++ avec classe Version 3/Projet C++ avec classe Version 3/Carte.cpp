#include "Carte.h"
#include"constante.h"
#include "SDL.h"
#include "SDL_image.h"
#include "fonction_affichage.h"
#include "Tourelle.h"
#include <vector>
#include <iostream>
using namespace std;


Carte::Carte(void)
{
	background_1 = IMG_Load("arriere_plan_1.bmp");
	background_2 = IMG_Load("arriere_plan_2.bmp");
	background_3 = IMG_Load("arriere_plan_3.bmp");
}


Carte::~Carte(void)
{
}
// Cette fonction permet d'actualiser notre carte avec l'emplacement de nos tourelles au fur et à mesure qu'on les pose.
// Notons qu'elle apparaît extrêment redondante et aurait pu être executée avec une simple boucle for ; cependant, pour des raisons
// inconnues, l'utilisation d'une boucle for dans cette fonction buguait le programme
void Carte::carte_avec_tourelle(int liste_coordonnee_x[],int liste_coordonnee_y[], SDL_Surface *screen,int z, int liste_tourelle[],int i)
{
	Tourelle tourelle;
	apply_surface(0,0,choix_carte(z),screen);
	int k;

	apply_surface(liste_coordonnee_x[i],liste_coordonnee_y[i],tourelle.type_tourelle(liste_tourelle[i]),screen);
	if (i==1)
	{
		apply_surface(liste_coordonnee_x[i-1],liste_coordonnee_y[i-1],tourelle.type_tourelle(liste_tourelle[i-1]),screen);

	}
	if (i==2)
	{
		apply_surface(liste_coordonnee_x[i-2],liste_coordonnee_y[i-2],tourelle.type_tourelle(liste_tourelle[i-2]),screen);
		apply_surface(liste_coordonnee_x[i-1],liste_coordonnee_y[i-1],tourelle.type_tourelle(liste_tourelle[i-1]),screen);
	}
	if (i==3)
	{
		apply_surface(liste_coordonnee_x[i-3],liste_coordonnee_y[i-3],tourelle.type_tourelle(liste_tourelle[i-3]),screen);
		apply_surface(liste_coordonnee_x[i-2],liste_coordonnee_y[i-2],tourelle.type_tourelle(liste_tourelle[i-2]),screen);
		apply_surface(liste_coordonnee_x[i-1],liste_coordonnee_y[i-1],tourelle.type_tourelle(liste_tourelle[i-1]),screen);
	}
	if (i==4)
	{
		apply_surface(liste_coordonnee_x[i-4],liste_coordonnee_y[i-4],tourelle.type_tourelle(liste_tourelle[i-4]),screen);
		apply_surface(liste_coordonnee_x[i-3],liste_coordonnee_y[i-3],tourelle.type_tourelle(liste_tourelle[i-3]),screen);
		apply_surface(liste_coordonnee_x[i-2],liste_coordonnee_y[i-2],tourelle.type_tourelle(liste_tourelle[i-2]),screen);
		apply_surface(liste_coordonnee_x[i-1],liste_coordonnee_y[i-1],tourelle.type_tourelle(liste_tourelle[i-1]),screen);
	}
	if (i==5)
	{
		apply_surface(liste_coordonnee_x[i-5],liste_coordonnee_y[i-5],tourelle.type_tourelle(liste_tourelle[i-5]),screen);
		apply_surface(liste_coordonnee_x[i-4],liste_coordonnee_y[i-4],tourelle.type_tourelle(liste_tourelle[i-4]),screen);
		apply_surface(liste_coordonnee_x[i-3],liste_coordonnee_y[i-3],tourelle.type_tourelle(liste_tourelle[i-3]),screen);
		apply_surface(liste_coordonnee_x[i-2],liste_coordonnee_y[i-2],tourelle.type_tourelle(liste_tourelle[i-2]),screen);
		apply_surface(liste_coordonnee_x[i-1],liste_coordonnee_y[i-1],tourelle.type_tourelle(liste_tourelle[i-1]),screen);
	}
	if (i==6)
	{
		apply_surface(liste_coordonnee_x[i-6],liste_coordonnee_y[i-6],tourelle.type_tourelle(liste_tourelle[i-6]),screen);
		apply_surface(liste_coordonnee_x[i-5],liste_coordonnee_y[i-5],tourelle.type_tourelle(liste_tourelle[i-5]),screen);
		apply_surface(liste_coordonnee_x[i-4],liste_coordonnee_y[i-4],tourelle.type_tourelle(liste_tourelle[i-4]),screen);
		apply_surface(liste_coordonnee_x[i-3],liste_coordonnee_y[i-3],tourelle.type_tourelle(liste_tourelle[i-3]),screen);
		apply_surface(liste_coordonnee_x[i-2],liste_coordonnee_y[i-2],tourelle.type_tourelle(liste_tourelle[i-2]),screen);
		apply_surface(liste_coordonnee_x[i-1],liste_coordonnee_y[i-1],tourelle.type_tourelle(liste_tourelle[i-1]),screen);

	}
	if (i==7)
	{
		apply_surface(liste_coordonnee_x[i-7],liste_coordonnee_y[i-7],tourelle.type_tourelle(liste_tourelle[i-7]),screen);
		apply_surface(liste_coordonnee_x[i-6],liste_coordonnee_y[i-6],tourelle.type_tourelle(liste_tourelle[i-6]),screen);
		apply_surface(liste_coordonnee_x[i-5],liste_coordonnee_y[i-5],tourelle.type_tourelle(liste_tourelle[i-5]),screen);
		apply_surface(liste_coordonnee_x[i-4],liste_coordonnee_y[i-4],tourelle.type_tourelle(liste_tourelle[i-4]),screen);
		apply_surface(liste_coordonnee_x[i-3],liste_coordonnee_y[i-3],tourelle.type_tourelle(liste_tourelle[i-3]),screen);
		apply_surface(liste_coordonnee_x[i-2],liste_coordonnee_y[i-2],tourelle.type_tourelle(liste_tourelle[i-2]),screen);
		apply_surface(liste_coordonnee_x[i-1],liste_coordonnee_y[i-1],tourelle.type_tourelle(liste_tourelle[i-1]),screen);

	}

}

SDL_Surface *Carte::choix_carte(int z) 
{
	if (z==1)
	{
		return background_1;
	}
	if (z==2)
	{
		return background_2;
	}
	if (z==3)
	{
		return background_3;
	}
}

int Carte::coordonnee_finale_x(int z)
{
	if (z==1)
	{
		return 75;
	}
	if (z==2)
	{
		return 665;
	}
	if (z==3)
	{
		return 327;
	}
}

int Carte::coordonnee_finale_y(int z)
{
	if (z==1)
	{
		return 665;
	}
	if (z==2)
	{
		return 531;
	}
	if (z==3)
	{
		return 665;
	}
}
// Cette fonction permet de retourner la position cible du monstre en fonction de sa position actuelle sur la carte
int Carte::carteretournerx(double x,double y,int z) // z est le type de la carte
{
	int x1=0;
	if(z==1)
	{

		if((x>113)&&(y<205)&&(x<119))
		{
			x1=116;
		}

		if((x<303)&&(y<210)&&(y>195)&&(x>113))
		{
			x1=302;
		}


		if((x<310)&&(y<215)&&(y>104)&&(x>295))
		{
			x1=302;
		}


		if((x<306)&&(y<115)&&(y>107)&&(x>189))
		{
			x1=192;
		}

		
		if((x<195)&&(y<112)&&(y>25)&&(x>189))
		{
			x1=192;
		}

		
		if((x<460)&&(y<35)&&(y>25)&&(x>186))
		{
			x1=454;
		}


		if((x<460)&&(y<280)&&(y>25)&&(x>449))
		{
			x1=454;
		}


		if((x<570)&&(y<280)&&(y>270)&&(x>449))
		{
			x1=566;
		}
	
		if((x<570)&&(y<460)&&(y>270)&&(x>560))
		{
			x1=566;
		}

		if((x<570)&&(y<460)&&(y>450)&&(x>389))
		{
			x1=393;
		}

		if((x<398)&&(y<460)&&(y>369)&&(x>389))
		{
			x1=393;
		}

		if((x<398)&&(y<378)&&(y>369)&&(x>71))
		{
			x1=75;
		}

		if((x<84)&&(y<671)&&(y>367)&&(x>71))
		{
			x1=75;
		}
	}
	
	if(z==2)
	{

		if((x<106)&&(y<536)&&(y>526))
		{
			x1=101;
		}

		if((x<106)&&(y<536)&&(y>135)&&(x>96))
		{
			x1=101;
		}


		if((x<181)&&(y<145)&&(y>135)&&(x>96))
		{
			x1=176;
		}


		if((x<181)&&(y<560)&&(y>135)&&(x>171))
		{
			x1=176;
		}

		
		if((x<289)&&(y<560)&&(y>550)&&(x>171))
		{
			x1=284;
		}

		
		if((x<289)&&(y<560)&&(y>342)&&(x>279))
		{
			x1=284;
		}


		if((x<382)&&(y<352)&&(y>342)&&(x>279))
		{
			x1=377;
		}


		if((x<382)&&(y<458)&&(y>342)&&(x>372))
		{
			x1=377;
		}
	
		if((x<457)&&(y<458)&&(y>448)&&(x>372))
		{
			x1=452;
		}

		if((x<457)&&(y<458)&&(y>63)&&(x>447))
		{
			x1=452;
		}

		if((x<545)&&(y<73)&&(y>63)&&(x>447))
		{
			x1=540;
		}

		if((x<545)&&(y<536)&&(y>63)&&(x>535))
		{
			x1=540;
		}

		if((x<670)&&(y<536)&&(y>526)&&(x>535))
		{
			x1= 665;
		}

	}

	if(z==3)
	{

		if((x>210)&&(y>565)&&(x<250))
		{
			x1=230;
		}
		
		if((x<235)&&(y<585)&&(y>575)&&(x>105))
		{
			x1=110;
		}


		if((x<115)&&(y<585)&&(y>362)&&(x>105))
		{
			x1=110;
		}


		if((x<115)&&(y<372)&&(y>362)&&(x>33))
		{
			x1=38;
		}

		
		if((x<43)&&(y<372)&&(y>290)&&(x>33))
		{
			x1=38;
		}

		
		if((x<115)&&(y<300)&&(y>290)&&(x>33))
		{
			x1=110;
		}


		if((x<115)&&(y<300)&&(y>95)&&(x>105))
		{
			x1=110;
		}


		if((x<232)&&(y<105)&&(y>95)&&(x>105))
		{
			x1=227;
		}
	
		if((x<232)&&(y<105)&&(y>27)&&(x>222))
		{
			x1=227;
		}

		if((x<353)&&(y<37)&&(y>27)&&(x>222))
		{
			x1=348;
		}

		if((x<353)&&(y<129)&&(y>27)&&(x>343))
		{
			x1=348;
		}

		if((x<483)&&(y<129)&&(y>119)&&(x>343))
		{
			x1=478;
		}

		if((x<483)&&(y<364)&&(y>119)&&(x>473))
		{
			x1=478;
		
		}
	
		if((x<582)&&(y<364)&&(y>354)&&(x>473))
		{
			x1=577;
		}
	
		if((x<582)&&(y<465)&&(y>354)&&(x>572))
		{
			x1=577;
		}

		if((x<582)&&(y<465)&&(y>455)&&(x>410))
		{
			x1=415;
		}

		if((x<420)&&(y<583)&&(y>455)&&(x>410))
		{
			x1=415;
		}

		if((x<420)&&(y<583)&&(y>573)&&(x>322))
		{
			x1=327;
		}

		if((x<332)&&(y<670)&&(y>573)&&(x>322))
		{
			x1=327;
		
		}
		
	}
	return x1;
}

// Idem avec y
int Carte::carteretournery(double x,double y,int z)
{
	int y1=0;
	if(z==1)
	{
		if((x>113)&&(y<205)&&(x<119))
		{
		y1=202;
		}

		if((x<303)&&(y<210)&&(y>195)&&(x>113))
		{
			y1=202;
		}


		if((x<310)&&(y<215)&&(y>104)&&(x>295))
		{
			y1=109;
		}


		if((x<306)&&(y<115)&&(y>107)&&(x>189))
		{
			y1=109;
		}

		
		if((x<195)&&(y<112)&&(y>25)&&(x>189))
		{
			y1=30;
		}

		
		if((x<460)&&(y<35)&&(y>25)&&(x>186))
		{
			y1=30;
		}


		if((x<460)&&(y<280)&&(y>25)&&(x>449))
		{
			y1=275;
		}


		if((x<570)&&(y<280)&&(y>270)&&(x>449))
		{
			y1=275;
		}
	
		if((x<570)&&(y<460)&&(y>270)&&(x>560))
		{
			y1=454;
		}

		if((x<570)&&(y<460)&&(y>450)&&(x>389))
		{
			y1=454;
		}

		if((x<398)&&(y<460)&&(y>369)&&(x>389))
		{
			y1=373;
		}

		if((x<398)&&(y<378)&&(y>369)&&(x>71))
		{
			y1=373;
		}

		if((x<84)&&(y<671)&&(y>367)&&(x>71))
		{
			y1= 665;
		}

		
	}
	if(z==2)
	{
		if((x<106)&&(y<536)&&(y>526))
		{
		y1=531;
		}

		if((x<106)&&(y<536)&&(y>135)&&(x>96))
		{
			y1=140;
		}


		if((x<181)&&(y<145)&&(y>135)&&(x>96))
		{
			y1=140;
		}


		if((x<181)&&(y<560)&&(y>135)&&(x>171))
		{
			y1=555;
		}

		
		if((x<289)&&(y<560)&&(y>550)&&(x>171))
		{
			y1=555;
		}

		
		if((x<289)&&(y<560)&&(y>342)&&(x>279))
		{
			y1=347;
		}


		if((x<382)&&(y<352)&&(y>342)&&(x>279))
		{
			y1=347;
		}


		if((x<382)&&(y<458)&&(y>342)&&(x>372))
		{
			y1=453;
		}
	
		if((x<457)&&(y<458)&&(y>448)&&(x>372))
		{
			y1=453;
		}

		if((x<457)&&(y<458)&&(y>63)&&(x>447))
		{
			y1=68;
		}

		if((x<545)&&(y<73)&&(y>63)&&(x>447))
		{
			y1=68;
		}

		if((x<545)&&(y<536)&&(y>63)&&(x>535))
		{
			y1=531;
		}

		if((x<670)&&(y<536)&&(y>526)&&(x>535))
		{
			y1= 531;
		}
	}


	if(z==3)
	{
		if((x>210)&&(y>565)&&(x<250))
		{
		y1=580;
		}

		
		if((x<235)&&(y<585)&&(y>575)&&(x>105))
		{
			y1=580;
		}


		if((x<115)&&(y<585)&&(y>362)&&(x>105))
		{
			y1=367;
		}


		if((x<115)&&(y<372)&&(y>362)&&(x>33))
		{
			y1=367;
		}

		
		if((x<43)&&(y<372)&&(y>290)&&(x>33))
		{
			y1=295;
		}

		
		if((x<115)&&(y<300)&&(y>290)&&(x>33))
		{
			y1=295;
		}


		if((x<115)&&(y<300)&&(y>95)&&(x>105))
		{
			y1=100;
		}


		if((x<232)&&(y<105)&&(y>95)&&(x>105))
		{
			y1=100;
		}
	
		if((x<232)&&(y<105)&&(y>27)&&(x>222))
		{
			y1=32;
		}

		if((x<353)&&(y<37)&&(y>27)&&(x>222))
		{
			y1=32;
		}

		if((x<353)&&(y<129)&&(y>27)&&(x>343))
		{
			y1=124;
		}

		if((x<483)&&(y<129)&&(y>119)&&(x>343))
		{
			y1=124;
		}

		if((x<483)&&(y<364)&&(y>119)&&(x>473))
		{
			y1=359;
		
		}
		
		if((x<572)&&(y<364)&&(y>354)&&(x>473))
		{
			y1=359;
		}
	
		if((x<582)&&(y<465)&&(y>354)&&(x>572))
		{
			y1=460;
		}

		if((x<582)&&(y<465)&&(y>455)&&(x>410))
		{
			y1=460;
		}

		if((x<420)&&(y<583)&&(y>455)&&(x>410))
		{
			y1=578;
		}

		if((x<420)&&(y<583)&&(y>573)&&(x>322))
		{
			y1=578;
		}

		if((x<332)&&(y<670)&&(y>573)&&(x>322))
		{
			y1=665;
		
		}
	}
	return y1;

}


