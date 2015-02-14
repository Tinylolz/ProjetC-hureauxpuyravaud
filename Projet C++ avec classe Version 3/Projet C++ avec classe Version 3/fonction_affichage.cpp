//The headers

#include "SDL.h"
#include "SDL_image.h"
#include <string>
#include "fonction_affichage.h"
#include"constante.h"



SDL_Surface *load_image( std::string filename )
{
    SDL_Surface* loadedImage = NULL;
   
    SDL_Surface* optimizedImage = NULL;

    loadedImage = IMG_Load( filename.c_str() );

    if( loadedImage != NULL )
    {
   
        optimizedImage = SDL_DisplayFormat( loadedImage );

        SDL_FreeSurface( loadedImage );

        if( optimizedImage != NULL )
        {

            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
			 Uint32 colorkey = SDL_MapRGB( optimizedImage->format, 244, 244, 244 );

            SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, colorkey );
        }
    }

    return optimizedImage;
}

void apply_surface( int x, int y, SDL_Surface* fonction_affichage, SDL_Surface* destination)
{

    SDL_Rect offset;

    
    offset.x = x;
    offset.y = y;


    SDL_BlitSurface( fonction_affichage, NULL, destination, &offset );
}








