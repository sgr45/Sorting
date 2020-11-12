//
// Created by sgr on 2020-11-10.
//

#include "../includes/Rectangle.h"

void Rectangle::DrawRectangle(SDL_Renderer * renderer,int x_pos, int height, int colour) {
    if(colour==1) SDL_SetRenderDrawColor(renderer,00,00,00,00);//starting colour
    else if(colour==2) SDL_SetRenderDrawColor(renderer,208,118,0,255);//selection colour
    else if(colour==3) SDL_SetRenderDrawColor(renderer,255,255,255,255);//final colour
    SDL_Rect rect;
    rect.x=x_pos;
    rect.y=650;
    rect.w=10;
    rect.h=height;
    SDL_RenderFillRect(renderer,&rect);
}

void Rectangle::draw_array(SDL_Renderer *renderer, std::vector <int> v, std::vector<int> swap, int i)
{

    for(int j=0;j<=i;j++)
    {
        DrawRectangle(renderer,50+j*15 ,-v[j],3);

    }
    for(int j=i+1;j<v.size();j++)
    {
        DrawRectangle(renderer,50+j*15 ,-v[j],1);

    }

    for(int s:swap)
    {
        DrawRectangle(renderer,50+s*15 ,-v[s],2);

    }


}