//
// Created by sgr on 2020-11-10.
//
#include "selectionsort.h"
#include "iostream"
#include "vector"
void swap ( int& x, int &y){
    int temp= x;
    x=y;
    y=temp;
}


void selectionsort::startsort(SDL_Renderer *renderer, std::vector<int> v)
{
    SDL_RenderPresent(renderer);
    for(int i=0;i<v.size()-1;i++)
    {
        std::vector<int> sw={};
        int min_ind=i;
        SDL_RenderPresent(renderer);
        for(int j=i+1;j<v.size();j++)
        {
            if(v[j]<v[min_ind])
            {
                min_ind=j;
            }
        }
        SDL_SetRenderDrawColor(renderer,255,0,0,255);
        SDL_RenderClear(renderer);
        sw.push_back(min_ind);
        sw.push_back(i);
        rectangle.draw_array(renderer,v,sw,i);
        SDL_RenderPresent(renderer);
        //rectangle.DrawRectangle(renderer,50+i*15,-v[i],0);
        //rectangle.DrawRectangle(renderer,50+min_ind*15,-v[min_ind],0);
        //SDL_RenderPresent(renderer);
        swap(v[i],v[min_ind]);

       // rectangle.DrawRectangle(renderer,50+i*15,-v[i],3);
        //rectangle.DrawRectangle(renderer,50+min_ind*15,-v[min_ind],1);
        SDL_RenderPresent(renderer);
//
//            SDL_RenderClear(renderer);
//            rectangle.draw_array(renderer,v);
            SDL_Delay(500);


    }

}

