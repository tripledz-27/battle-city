#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include "SDL.h"


class Wall{
public:
    int x, y;
    SDL_Rect rect;
    bool active;
    Wall(int startX, int startY);
    void render(SDL_Renderer* renderer);
};


#endif // WALL_H_INCLUDED
