//
// Created by sgr on 2020-11-12.
//

#ifndef SELECTIONSORT_BUTTON_H
#define SELECTIONSORT_BUTTON_H
#include <SDL2/SDL_ttf.h>
#include "SDL2/SDL.h"
#include "iostream"
#include "Texture.h"

class Button {
private:
    int height,width,xPosition,yPosition;
    std::string text;
    bool isClickedButton;

public:
    Button();
    Button(std::string , int x_pos, int y_pos, int width=60, int height=40);
    bool isClicked(int mouse_x,int mouse_y);
    void render(SDL_Renderer *renderer, TTF_Font *font);
    int getx() const;
    int gety() const;
    ~Button();
    void outer(SDL_Renderer *renderer);
    SDL_Texture * loadTexture(std::string head);


};


#endif //SELECTIONSORT_BUTTON_H
