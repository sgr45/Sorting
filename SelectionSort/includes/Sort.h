//
// Created by sgr on 2020-11-12.
//

#ifndef SELECTIONSORT_SORT_H
#define SELECTIONSORT_SORT_H
#include "SDL2/SDL.h"
#include "iostream"
#include "Rectangle.h"
#include "selectionsort.h"
#include "vector"
#include "Button.h"


class Sort {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    bool quit;
    int mouse_x,mouse_y;
    std::vector<int>v;
    bool generatorclick;
    bool selectionclick;
    Rectangle rectangle;
    TTF_Font *font;
    Button generator;
    Button selection;




public:
    Sort();
    Sort(int w_width,int w_height );
    void EventHandler();
    void close();
    void AllButton();
    void clearall();



};


#endif //SELECTIONSORT_SORT_H
