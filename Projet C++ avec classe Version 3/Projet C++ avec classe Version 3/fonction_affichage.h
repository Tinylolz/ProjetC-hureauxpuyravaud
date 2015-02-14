#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <string>


SDL_Surface *load_image( std::string);
void apply_surface( int, int, SDL_Surface* , SDL_Surface* );


