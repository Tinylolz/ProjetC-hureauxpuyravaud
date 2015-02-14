#include "Temps.h"
#include "SDL.h"
#include "SDL_image.h"

Temps::Temps(void)
{
	
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}


Temps::~Temps(void)
{
}


void Temps::start()
{
  
    started = true;


    paused = false;

    startTicks = SDL_GetTicks();
}

void Temps::stop()
{

    started = false;


    paused = false;
}

void Temps::pause()
{

    if( ( started == true ) && ( paused == false ) )
    {

        paused = true;

  
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}

void Temps::unpause()
{

    if( paused == true )
    {
 
        paused = false;

 
        startTicks = SDL_GetTicks() - pausedTicks;

        pausedTicks = 0;
    }
}
// permet de récupérer le temps en cours après un lancement d'horloge
int Temps::get_ticks()
{
  
    if( started == true )
    {
      
        if( paused == true )
        {
        
            return pausedTicks;
        }
        else
        {
          
            return SDL_GetTicks() - startTicks;
        }
    }

    
    return 0;
}

bool Temps::is_started()
{
    return started;
}

bool Temps::is_paused()
{
    return paused;
}


