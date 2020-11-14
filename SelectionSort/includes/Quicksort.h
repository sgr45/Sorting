//
// Created by sgr on 2020-11-13.
//

#ifndef SELECTIONSORT_QUICKSORT_H
#define SELECTIONSORT_QUICKSORT_H
#include "vector"
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Rectangle.h"
#include "iostream"
#include "Button.h"
class Quicksort {
private:
    std::vector<int> v;
    bool nquit;
    SDL_Event e;
    TTF_Font *font;
public:
    void startQuick(SDL_Renderer*renderer);
    Rectangle rectangle;
    Quicksort();
    Quicksort(std::vector<int>);
    void Quick(SDL_Renderer *renderer,int beg,int end);
    void swap ( int& x, int &y);
    void clear(SDL_Renderer *renderer);
};


#endif //SELECTIONSORT_QUICKSORT_H
