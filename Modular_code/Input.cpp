#include<snake.h>
using namespace std;


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
