#ifndef ENEMYTANK_H_INCLUDED
#define ENEMYTANK_H_INCLUDED
#include <vector>
#include "wall.h"
#include "bullet.h"
class EnemyTank{
public:
    int x, y;
    int dirX, dirY;
    int moveDelay, shootDelay;
    SDL_Rect rect;
    bool active;
    std::vector<Bullet> bullets;

    EnemyTank(int startX, int startY);
    void move(const std::vector<Wall>& walls);
    void shoot();
    void updateBullets();
    void render(SDL_Renderer* renderer);

};


#endif // ENEMYTANK_H_INCLUDED
