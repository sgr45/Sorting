//
// Created by sgr on 2020-11-13.
//

#include "Quicksort.h"

void Quicksort::Quick( SDL_Renderer *renderer,int beg, int end)
{
    std::string path= "../Media/Fonts/font2.ttf";
    font = TTF_OpenFont(path.c_str(), 20);
    nquit=true;
    if(end>beg) {
        if(nquit)
        {
            if (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_KEYDOWN) {
                    if (e.key.keysym.sym == SDLK_ESCAPE) { nquit = false; }
                }
            }

            int vot = beg + rand()%((end + 1 - beg));
            int pivot = v[vot];
            swap(v[beg],v[vot]);
            int mid = beg;
            clear(renderer);
            rectangle.draw_array(renderer,v,{vot},end,beg);
            SDL_RenderPresent(renderer);
            SDL_Delay(400);
            for (int i = beg + 1; i <= end; i++) {
                if (v[i] < pivot) {
                    swap(v[i], v[++mid]);

                }
            }
            swap(v[beg], v[mid]);
            clear(renderer);
            rectangle.draw_array(renderer,v,{mid},end,beg);
            SDL_RenderPresent(renderer);
            SDL_Delay(600);
            Quick(renderer,beg, mid - 1);
            Quick(renderer, mid+ 1, end);
        }
        else return;
    }

}


void Quicksort::swap ( int& x, int &y){
    int temp = x;
    x=y;
    y=temp;
}

void Quicksort::clear(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer,29,208,252,255);
    SDL_RenderClear(renderer);
}
Quicksort::Quicksort(std::vector<int>q)
{
    v=q;
}

void Quicksort::startQuick(SDL_Renderer *renderer)
{
    Quick(renderer,0,v.size()-1);
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