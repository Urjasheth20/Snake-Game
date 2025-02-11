#include<snakegame.h>
using namespace std;

void Run() {
        StartScreen();
        while (true) {
            Setup();
            while (!gameOver) {
                gotoxy(0, 0);
                ground();
                Input();
                Logic();
                Sleep(20);
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
