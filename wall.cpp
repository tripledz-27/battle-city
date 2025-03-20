#include "wall.h"
#include "game.h"
#include <SDL.h>

Wall :: Wall(int startX , int startY){
    x = startX;
    y = startY;
    active = true;
    rect = {x, y, TILE_SIZE, TILE_SIZE};
}

void Wall:: render(SDL_Renderer * renderer){
    if(active){
    SDL_SetRenderDrawColor(renderer, 150, 75, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
    }
}

