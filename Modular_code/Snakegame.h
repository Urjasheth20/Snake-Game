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

using namespace std;

class SnakeGame {
private:
    bool gameOver;
    int x, y, foodX, foodY, score;
    int tailX[100], tailY[100];
    int nTail;
    int direction;
    int highScore;

    int obstaclesX[MAX_OBSTACLES], obstaclesY[MAX_OBSTACLES]; // Store obstacle positions
    int nObstacles;

    void gotoxy(int x, int y) {
        COORD coord = { static_cast<SHORT>(x), static_cast<SHORT>(y) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
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

public:
    SnakeGame() : gameOver(false), direction(RIGHT), x(WIDTH / 2), y(HEIGHT / 2), score(0), nTail(2), highScore(0), nObstacles(0) {
    	nObstacles=5;
        SpawnFood();
        
        SpawnObstacles();
    }

void gotoxy(int x, int y);
void SpawnFood();
void SpawnObstacles();
SnakeGame() (Constructor);.
void Setup();
void ground();
void Input();
void Logic();
void StartScreen();
void GameOverScreen();
void Run();


