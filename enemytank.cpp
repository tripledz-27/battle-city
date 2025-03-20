    #include "enemytank.h"
    #include "wall.h"
    #include <vector>
    #include <algorithm>
    #include "game.h"
    #include "bullet.h"
    using namespace std;
    EnemyTank:: EnemyTank(int startX, int startY){
        moveDelay = 15;
        shootDelay = 5;
        x = startX;
        y = startY;
        rect = {x, y, TILE_SIZE, TILE_SIZE};
        dirX = 0;
        dirY = 1;
        active = true;
    }
    void EnemyTank:: move(const std:: vector<Wall>& walls) {
        if(-- moveDelay > 0) return ;
        moveDelay = 15;
        int r = rand() % 4;
        if(r == 0){
            this -> dirX = 0;
            this -> dirY = -5;
        }
        else if(r == 1){
            this -> dirX = 0;
            this -> dirY = 5;
        }
        else if(r == 2){
            this -> dirY = 0;
            this -> dirX = -5;
        }
        else{
            this -> dirY = 0;
            this -> dirX = 5;
        }
        int newX = x + this -> dirX;
        int newY = y + this -> dirY;
        SDL_Rect newRect = {newX, newY, TILE_SIZE, TILE_SIZE};
        for(const auto & wall : walls){
            if(wall.active && SDL_HasIntersection(&newRect, &wall.rect)){
                return;
            }
        }
        if(newX >= TILE_SIZE && newX <= SCREEN_WIDTH -TILE_SIZE * 2 &&
           newY >= TILE_SIZE && newY <= SCREEN_HEIGHT -TILE_SIZE * 2){
             x = newX;
             y = newY;
             rect.x = x;
             rect.y = y;
           }
    }

    void EnemyTank:: shoot(){
        if (--shootDelay > 0) return;
        shootDelay = 5;
        bullets.push_back(Bullet(x + TILE_SIZE / 2 -5, y + TILE_SIZE / 2 - 5, this -> dirX, this -> dirY));
    }

    void EnemyTank :: updateBullets(){
        for(auto & bullet : bullets){
            bullet.move();
        }
        bullets.erase(std::remove_if(bullets.begin(), bullets.end(),
                 [](Bullet &b) { return !b.active; }), bullets.end());

    }

    void EnemyTank::render(SDL_Renderer* renderer){
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
        for(auto & bullet : bullets){
            bullet.render(renderer);
        }
    }
