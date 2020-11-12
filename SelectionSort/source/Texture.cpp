//
// Created by sgr on 2020-11-12.
//

#include "Texture.h"
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_ttf.h>
#include <cstdio>
#include<iostream>

Texture::Texture(const std::string& fontPath){
    texture = nullptr;
    width = 0;
    height = 0;
}

bool Texture::loadFromText(SDL_Renderer *renderer, std::string text, SDL_Color color, TTF_Font *font){
    free(texture);

    SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), color);

    if(!surface){
        printf("Unable to render text, SDL_TTF error:%s\n", TTF_GetError());
    }
    else{
        //create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if(!texture){
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        }
        else{
            width = surface->w;
            height = surface->h;
        }

        //Free the old surface
        SDL_FreeSurface(surface);
    }

    return texture != nullptr;
}

void Texture::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 alpha){
    //Modulate texture rgb
    SDL_SetTextureColorMod(texture, r, g, b);

    SDL_SetTextureAlphaMod(texture, alpha);
}


void Texture::render(SDL_Renderer *renderer,int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip){
    SDL_Rect renderRect = {x, y, width, height};
    if(clip != nullptr){
        renderRect.w = clip->w;
        renderRect.h = clip->h;
    }

    //render to screen
    SDL_RenderCopyEx(renderer, texture, clip, &renderRect, angle, center, flip);
}

int Texture::getWidth() const{
    return width;
}

int Texture::getHeight() const{
    return height;
}

Texture::~Texture(){
    SDL_DestroyTexture(texture);
}
