#pragma once
#include "SDL.h"
#include "SDL_image.h"
class Monstre
{
public:
	Monstre(void);
	~Monstre(void);
	SDL_Surface* afficher_monstre(int);
	void reinitoffsets(int);
	void initcaract(int liste[]);
    void handle_input(double,double,int,int,int);
    void move(int);
	void move_ralenti(int,double); 
    void show(SDL_Surface * screen,int,int);

	double x[20];
	double y[20];
	double xVel[20];
	double yVel[20];
	int vie_monstre[20];
    double Vel[20];

	private:
  

	SDL_Surface *sprite_monstre_fantome;
	SDL_Surface *sprite_monstre_troll;
};

