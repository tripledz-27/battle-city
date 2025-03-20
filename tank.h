#ifndef TANK_H_INCLUDED
#define TANK_H_INCLUDED

#include <vector>
#include "wall.h"
#include "bullet.h"


class PlayerTank{
    public:
        int x, y;
        int dirX, dirY;
        SDL_Rect rect;
        std::vector<Bullet> bullets;

        PlayerTank(int startX, int startY);
        void move(int dx, int dy, const std:: vector <Wall>& walls);
        void render(SDL_Renderer *renderer);
        void shoot();
        void updateBullets();
};


#endif // TANK_H_INCLUDED
