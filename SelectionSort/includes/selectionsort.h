//
// Created by sgr on 2020-11-10.
//

#ifndef SELECTIONSORT_SELECTIONSORT_H
#define SELECTIONSORT_SELECTIONSORT_H
#include "SDL2/SDL.h"
#include "Rectangle.h"
#include "vector"

class selectionsort {
private:
    Rectangle rectangle;
public:
   void startsort(SDL_Renderer *renderer , std::vector<int> v);

};


#endif //SELECTIONSORT_SELECTIONSORT_H
