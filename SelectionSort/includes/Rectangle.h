//
// Created by sgr on 2020-11-10.
//

#ifndef SELECTIONSORT_RECTANGLE_H
#define SELECTIONSORT_RECTANGLE_H
#include "SDL2/SDL.h"
#include "vector"



class Rectangle {

    public:
    void draw_array(SDL_Renderer *renderer,std::vector<int>,std::vector<int>,int,int beg=0);
    void DrawRectangle(SDL_Renderer *renderer,int x_pos,int height,int colour);
};


#endif //SELECTIONSORT_RECTANGLE_H
