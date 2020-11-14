//
// Created by sgr on 2020-11-10.
//
#include "selectionsort.h"
#include "iostream"
#include "Button.h"
//swaping number
void swap ( int& x, int &y){
    int temp= x;
    x=y;
    y=temp;
}


void selectionsort::startsort(SDL_Renderer *renderer, std::vector<int> v)
{
    //font to render
    std::string path= "../Media/Fonts/font2.ttf";
    font = TTF_OpenFont(path.c_str(), 20);
    nquit=true;
    for(int i=0;i<v.size()-1;i++)
    {
        if(nquit)
        {
            if(SDL_PollEvent(&e)!=0) {
                if (e.type == SDL_KEYDOWN) {
                    if (e.key.keysym.sym == SDLK_ESCAPE ) { nquit=false; }
                }
            }
            std::vector<int> sw = {};
            int min_ind = i;
            SDL_RenderPresent(renderer);
            for (int j = i + 1; j < v.size(); j++) {
                if (v[j] < v[min_ind]) {
                    min_ind = j;
                }
            }
            clear(renderer);
            sw.push_back(min_ind);
            sw.push_back(i);
            /*Rendering rectangle array with different colour for swaping number swapped number and need to be swapped number*/
            rectangle.draw_array(renderer, v, sw, i);
            SDL_RenderPresent(renderer);
            swap(v[i], v[min_ind]);
            SDL_Delay(400);
        }
        else return;
    }
    clear(renderer);
    rectangle.draw_array(renderer,v, {},v.size());

    Button butt("Press any key to continue",10,10,500);
    butt.render(renderer,font);
    SDL_RenderPresent(renderer);


    while(nquit) {
        if (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_KEYDOWN) {
                 nquit = false;
            }
        }
    }


}
//screen clear
void selectionsort::clear(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer,74,192,53,255);
    SDL_RenderClear(renderer);

}

