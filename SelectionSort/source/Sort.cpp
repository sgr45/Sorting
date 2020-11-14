//
// Created by sgr on 2020-11-12.
//

#include "Sort.h"

Sort::Sort() {}
Sort::Sort(int w_width, int w_height)
{
    //creating window and rendere
    window=SDL_CreateWindow("Sort Visualisation",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,w_width=1000,w_height=700,SDL_WINDOW_SHOWN);
    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    //path for font for rendering button text
    std::string path= "../Media/Fonts/font2.ttf";
    font = TTF_OpenFont(path.c_str(), 20);
    quit=false;

}

void Sort::EventHandler()
{
    //clearing screen
    clearall();
    //Button generation
    generator= Button("Generate numbers",10,10,250);
    selection=Button("Selection Sort",300,10,250);
    quick=Button("Quick Sort",590,10,250);
    //Button renderer
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
                //generator button clicked
                if(generator.isClicked(mouse_x,mouse_y))
                {

                    srand(mouse_x*mouse_y);
                    v={};
                    //generating random 60 numbers
                    for(int i=0;i<60;i++)    v.push_back((rand()%600));
                    clearall();
                    AllButton();
                    //drawing random array
                    rectangle.draw_array(renderer,v,{},-1);
                    SDL_RenderPresent(renderer);
                }
                //selection sort clicked
                if(selection.isClicked(mouse_x,mouse_y))
                {
                    //selection sort
                    selectionsort select;
                    select.startsort(renderer,v);
                    //clean screen with button and not sorted array
                    clearall();
                    rectangle.draw_array(renderer,v,{},-1);
                    AllButton();
                    SDL_RenderPresent(renderer);

                }
                if(quick.isClicked(mouse_x,mouse_y))
                {
                    //quicksort
                    Quicksort quicksort(v);
                    quicksort.startQuick(renderer);
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
//clearing memory
void Sort::close()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    window=NULL;
    renderer=NULL;
    SDL_Quit();

}
//rendering button
void Sort::AllButton()
{
    generator.render(renderer,font);
    selection.render(renderer,font);
    quick.render(renderer,font);
   // SDL_RenderPresent(renderer);

}
//clear screen
void  Sort::clearall()
{
    SDL_SetRenderDrawColor(renderer,136,192,208,255);
    SDL_RenderClear(renderer);

}