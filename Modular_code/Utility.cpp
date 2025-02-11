#include "snake_game.h"
using namespace std;

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

#define WIDTH 50
#define HEIGHT 25
#define MAX_OBSTACLES 10 // Maximum number of obstacles

#define STOP 0
#define LEFT -1
#define RIGHT 1
#define UP -2
#define DOWN 2

 void Setup() {
        gameOver = false;
        direction = RIGHT;
        x = WIDTH / 2;
        y = HEIGHT / 2;
        SpawnFood();
        SpawnObstacles();
        score = 0;
        nTail = 2;
    }


 void SpawnFood() {
        bool valid;
        do {
            valid = true;
            foodX = (rand() % (WIDTH - 4)) + 2;
            foodY = (rand() % (HEIGHT - 4)) + 2;

            if (foodX == x && foodY == y) valid = false;
            for (int i = 0; i < nTail; i++) {
                if (foodX == tailX[i] && foodY == tailY[i]) {
                    valid = false;
                    break;
                }
            }
        } while (!valid);
    }

    void SpawnObstacles() {
        
        bool valid;
        
        for (int i = 0; i < nObstacles; i++) {
            do {
                valid = true;
                obstaclesX[i] = (rand() % (WIDTH - 4)) + 2;
                obstaclesY[i] = (rand() % (HEIGHT - 4)) + 2;
                
                if (obstaclesX[i] == x && obstaclesY[i] == y) valid = false;
                if (obstaclesX[i] == foodX && obstaclesY[i] == foodY) valid = false;
                for (int j = 0; j < nTail; j++) {
                    if (obstaclesX[i] == tailX[j] && obstaclesY[i] == tailY[j]) valid = false;
                }
            } while (!valid);
        }
    }
