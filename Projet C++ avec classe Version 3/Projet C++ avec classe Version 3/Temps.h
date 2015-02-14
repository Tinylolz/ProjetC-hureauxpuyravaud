#pragma once
#include "SDL.h"
#include "SDL_image.h"
class Temps
{
public:
	Temps(void);
	~Temps(void);

    void start();
    void stop();
    void pause();
    void unpause();

    int get_ticks();
 
    bool is_started();
    bool is_paused();

	 private:
    
    int startTicks;
    int pausedTicks;
    bool paused;
    bool started;
};

