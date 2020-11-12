//
// Created by sgr on 2020-11-12.
//

#include "Sort.h"

Sort::Sort() {}
Sort::Sort(int w_width, int w_height)
{
    window=SDL_CreateWindow("Sort Visualisation",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w_width=1000,w_height=700,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    std::string path= "../Media/Fonts/font2.ttf";
    font = TTF_OpenFont(path.c_str(), 20);
    quit=false;
    generatorclick=false;
    selectionclick=false;
}

void Sort::EventHandler()
{
    clearall();
    generator= Button("Generate numbers",10,10,300);
    selection=Button("Selection Sort",400,10,300);
    AllButton();
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
                    clearall();
                    AllButton();
                    rectangle.draw_array(renderer,v,{},-1);
                    SDL_RenderPresent(renderer);
                }

                if(selection.isClicked(mouse_x,mouse_y))
                {
                    selectionsort select;
                    select.startsort(renderer,v);
                    clearall();
                    rectangle.draw_array(renderer,v,{},-1);
                    AllButton();
                    SDL_RenderPresent(renderer);

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

void Sort::AllButton()
{
    generator.render(renderer,font);
    selection.render(renderer,font);
   // SDL_RenderPresent(renderer);

}
void  Sort::clearall()
{
    SDL_SetRenderDrawColor(renderer,136,192,208,255);
    SDL_RenderClear(renderer);
    //SDL_RenderPresent(renderer);

}