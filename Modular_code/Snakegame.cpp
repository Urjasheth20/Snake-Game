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

    void ground() {
        for (int i = 0; i < WIDTH; i++) cout << "#";
        cout << "\n";

        for (int i = 0; i < HEIGHT - 2; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (j == 0 || j == WIDTH - 1) cout << "#";
                else if (i == y && j == x) {
                	
				    cout << "O";
					}
                else if (i == foodY && j == foodX) {
				
				cout << "*";
				}
                else {
                    bool print = false;
                    for (int k = 0; k < nTail; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                        	
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print) {
                        bool obstaclePrint = false;
                        for (int k = 0; k < nObstacles; k++) {
                            if (obstaclesX[k] == j && obstaclesY[k] == i) {
                            	
                                cout << "#"; 
								
                                obstaclePrint = true;
                                break;
                            }
                        }
                        if (!obstaclePrint) cout << " ";
                    }
                }
            }
            cout << "\n";
        }

        for (int i = 0; i < WIDTH; i++) cout << "#";
        cout << "\n";

        cout << "Score: " << score << "   High Score: " << highScore << "\n";
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
                case 'a': if (direction != RIGHT) direction = LEFT; break;
                case 'd': if (direction != LEFT) direction = RIGHT; break;
                case 'w': if (direction != DOWN) direction = UP; break;
                case 's': if (direction != UP) direction = DOWN; break;
                case 'r': gameOver = true; break;
                case 'x': exit(0);
            }
        }
    }

    void Logic() {
        int prevX = tailX[0], prevY = tailY[0];
        int prev2X, prev2Y;
        tailX[0] = x;
        tailY[0] = y;

        for (int i = 1; i < nTail; i++) {
            prev2X = tailX[i];
            prev2Y = tailY[i];
            tailX[i] = prevX;
            tailY[i] = prevY;
            prevX = prev2X;
            prevY = prev2Y;
        }

        switch (direction) {
            case LEFT: x--; break;
            case RIGHT: x++; break;
            case UP: y--; break;
            case DOWN: y++; break;
            default: break;
        }

        if (x <= 0 || x >= WIDTH - 2 || y < 0 || y >= HEIGHT - 2) gameOver = true;

        for (int i = 0; i < nTail; i++)
            if (tailX[i] == x && tailY[i] == y) gameOver = true;

        for (int i = 0; i < nObstacles; i++) {
            if (obstaclesX[i] == x && obstaclesY[i] == y) gameOver = true;
        }

        if (x == foodX && y == foodY) {
            score += 10;
            if (nTail < 100) nTail++;
            Beep(1000, 100);
            SpawnFood();
        }
    }

    void StartScreen() {
        system("cls");
        cout << "#####      #    #     #  #######" << endl;
        cout << "#     #   # #   ##   ##  #" << endl;
        cout << "#        #   #  # # # #  #####" << endl;
        cout << "#  ####  #####  #  #  #  #" << endl;
        cout << " #    #  #   #  #     #  #" << endl;
        cout << "  ####   #   #  #     #  #######" << endl;
        cout << endl;
        cout << " Press any key to continue " << endl;
        
        _getch();
    }

    void GameOverScreen() {
        system("cls");
        
        cout << "\n"
         "  #####     #    #     #  #######        #####   #     #  #######  #####  \n"
         " #     #   # #   ##   ##  #             #     #  #     #  #        #     # \n"
         " #        #   #  # # # #  #####         #     #  #     #  #####    ######  \n"
         " #  ####  #####  #  #  #  #             #   # #   #   #   #        #   #   \n"
         "  #    #  #   #  #     #  #             #    #     # #    #        #    #  \n"
         "   ####   #   #  #     #  #######        ####       #     #######  #     # \n"
         << endl;

        
        cout << "Final Score: " << score << "\n";
        if (score > highScore) {
            highScore = score;
            cout << "New High Score: " << highScore << "!\n";
        } else {
            cout << "High Score: " << highScore << "\n";
        }
        cout << "Press 'R' to Restart or 'X' to Exit\n";
    }

    void Run() {
        StartScreen();
        while (true) {
            Setup();
            while (!gameOver) {
                gotoxy(0, 0);
                ground();
                Input();
                Logic();
                Sleep(50);
            }
            GameOverScreen();
            while (true) {
                if (_kbhit()) {
                    char key = _getch();
                    if (key == 'r') break;
                    else if (key == 'x') return;
                }
            }
        }
    }
};

int main() {
    SnakeGame game;
    game.Run();
    return 0;
}
