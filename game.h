#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include "wall.h"
#include "tank.h"
#include "enemytank.h"
#include "bullet.h"


 using namespace std;

 const int SCREEN_WIDTH = 800;
 const int SCREEN_HEIGHT = 600;
 const int TILE_SIZE = 40;
 const int MAP_WIDTH = SCREEN_WIDTH / TILE_SIZE;
 const int MAP_HEIGHT = SCREEN_HEIGHT / TILE_SIZE;
class Game
{
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running;
    vector<Wall> walls;
    PlayerTank player;
    int enemyNumber = 3;
    vector<EnemyTank> enemies;

    Game();
    void render();
    void run();
    ~ Game();
    void generateWalls();
    void handleEvents();
    void update();
    void spawnEnemies();
};


#endif // GAME_H_INCLUDED
