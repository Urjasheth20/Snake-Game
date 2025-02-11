#include<snakegame.h>
using namespace std;

void ground() {
        for (int i = 0; i < WIDTH; i++) cout << "#"; //Upper wall printing
        cout << "\n";

        for (int i = 0; i < HEIGHT - 2; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (j == 0 || j == WIDTH - 1) cout << "#"; // Side wall printing
                else if (i == y && j == x) cout << "O"; //snake's head
                else if (i == foodY && j == foodX) cout << "*";  //food
                else {
                    bool print = false;
                    for (int k = 0; k < nTail; k++) {
                        if (tailX[k] == j && tailY[k] == i) {
                            cout << "o";  //snake tail
                            print = true;
                        }
                    }
                    if (!print) cout << " ";
                }
            }
            cout << "\n";
        }

        for (int i = 0; i < WIDTH; i++) cout << "#"; // lower wall printing
        cout << "\n";

        cout << "Score: " << score << "   High Score: " << highScore << "\n";
    }
