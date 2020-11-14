//
// Created by sgr on 2020-11-10.
//

#include "../includes/Rectangle.h"
//Draw rectangle at x_pos with width 10 and given height and colour code
void Rectangle::DrawRectangle(SDL_Renderer * renderer,int x_pos, int height, int colour) {
    if(colour==1) SDL_SetRenderDrawColor(renderer,00,00,00,00);//starting colour
    else if(colour==2) SDL_SetRenderDrawColor(renderer,208,118,0,255);//selection colour
    else if(colour==3) SDL_SetRenderDrawColor(renderer,255,255,255,255);//final colour
    else if(colour==4) SDL_SetRenderDrawColor(renderer,204,255,0,255);
    SDL_Rect rect;
    rect.x=x_pos;
    rect.y=650;
    rect.w=10;
    rect.h=height;
    SDL_RenderFillRect(renderer,&rect);
}
/*Draw array of rectangle with black colour for vector v except the index in vector swap and
and index from beg to end. Different colour for index of vector v in swap and different for index beg to end*/

void Rectangle::draw_array(SDL_Renderer *renderer, std::vector <int> v, std::vector<int> swap, int i,int beg)
{

    for(int j=beg;j<=i;j++)
    {
        DrawRectangle(renderer,50+j*15 ,-v[j],3);//xpos = 50+indexofelementof array *(width+gap)

    }
    for(int j=0;j<beg;j++)
    {
        DrawRectangle(renderer,50+j*15 ,-v[j],4);

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