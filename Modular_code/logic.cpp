#include<snakegame.h>
using namespace std;

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

        if (x == foodX && y == foodY) {
            score += 10;
            if (nTail < 100) nTail++;
            Beep(1000, 100);
            SpawnFood();
        }
    }
