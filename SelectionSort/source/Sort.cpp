//
// Created by sgr on 2020-11-12.
//

#include "Sort.h"

Sort::Sort() {}
Sort::Sort(int w_width, int w_height)
{
    window=SDL_CreateWindow("Sort Visualisation",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w_width=1000,w_height=700,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    quit=false;
    generatorclick=false;
    selectionclick=false;
}

void Sort::EventHandler()
{
    Button generator("Generate new set of numbers",100,100,400);
    Button selection("Selection Sort",100,200,400);
    generator.render(renderer,font);
    selection.render(renderer,font);
    SDL_RenderPresent(renderer);

    while(!quit) {
        while (SDL_PollEvent(&event))
        {
            SDL_GetMouseState(&mouse_x,&mouse_y);
            if(event.type==SDL_QUIT)
            {
                quit=true;
            }
            else if(event.type==SDL_MOUSEBUTTONDOWN)
            {
                if(generator.isClicked(mouse_x,mouse_y))
                {
                    generatorclick=true;
                    srand((mouse_y+mouse_x));
                    v={};
                    for(int i=0;i<60;i++)    v.push_back((rand()%600));
                    rectangle.draw_array(renderer,v,{},-1);
                    SDL_RenderPresent(renderer);
                }
                if(selection.isClicked(mouse_x,mouse_y))
                {
                    selectionsort select;
                    select.startsort(renderer,v);
                }
            }
        }
    }
    close();

}

void Sort::close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window=NULL;
    renderer=NULL;
    SDL_Quit();

}