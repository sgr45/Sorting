#include <iostream>
#include "SDL2/SDL.h"
#include "Rectangle.h"
#include "selectionsort.h"
#include "vector"
int main()
{
    SDL_Init((SDL_INIT_EVERYTHING));
    SDL_Window *window1=SDL_CreateWindow("New Window",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,700,SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer= NULL;
    renderer=SDL_CreateRenderer(window1,-1,SDL_RENDERER_ACCELERATED);
    std::vector<int> a, b={};
    for(int i=0;i<60;i++)    a.push_back((rand()%300)*2);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    Rectangle rectangle;
    rectangle.draw_array(renderer,a,b,0);
    SDL_RenderPresent(renderer);
    selectionsort select;
    select.startsort(renderer,a);
    SDL_Delay(5000);
    SDL_DestroyWindow(window1);
    window1=NULL;
    SDL_Quit();




}
