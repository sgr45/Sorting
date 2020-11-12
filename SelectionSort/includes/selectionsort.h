//
// Created by sgr on 2020-11-10.
//

#ifndef SELECTIONSORT_SELECTIONSORT_H
#define SELECTIONSORT_SELECTIONSORT_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "Rectangle.h"
#include "vector"

class selectionsort {
private:
    Rectangle rectangle;
    SDL_Event e;
    bool nquit;
    TTF_Font *font;
public:
   void startsort(SDL_Renderer *renderer , std::vector<int> v);
   void buttons(SDL_Renderer *renderer);
   void clear(SDL_Renderer *renderer);


};


#endif //SELECTIONSORT_SELECTIONSORT_H
