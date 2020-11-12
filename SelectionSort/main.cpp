#include "SDL2/SDL.h"
#include "Sort.h"

int main()
{
    SDL_Init((SDL_INIT_EVERYTHING));
    TTF_Init();
    Sort sort(1000,700);
    sort.EventHandler();



}



