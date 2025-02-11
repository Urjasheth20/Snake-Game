# SNAKE GAME 
## Overview
This is a console-based Snake game implemented in C++ using basic libraries such as <iostream>, <conio.h>, <cstdlib>, and <windows.h>. The game features simple mechanics where the player controls the snake to eat food while avoiding walls and itself. The snake grows longer as it eats food, and the game ends when the snake collides with a wall or itself.

## 🎮 Game Features
•	Classic Snake game mechanics.
•	Playable within the console window.
•	Dynamic food spawning marked with '*'.
•	Collision detection (walls & snake body).
•	Score tracking.
• Restart & exit options.
• Simple ASCII-based UI.
• Sound effect 
## 🛠 Installation & Execution
### 📥 Prerequisites
•A C++ compiler (GCC, MinGW, MSVC, etc.)
•Windows OS (Uses <conio.h> and <windows.h>)
### ⚡ Run the Game

#### 1. Clone the repository:
https://github.com/Urjasheth20/snake-game
cd snake-game
#### 2. Compile the code:
g++ snake.cpp -o snake.exe
#### 3. Run the game:
./snake.exe
### 🎮 Controls

|KEY | ACTION
|:-|:-
| w | Move up
| a | Move left
| s | Move down
| d | Move right
| r | Restart the game
| x | Exit
### 📝 Code Breakdown
The main components of the game:
• Setup Function: Initializes variables and game state.
• Draw Function: Renders the game area using ASCII characters.
• Input Function: Captures user input for snake movement.
• Logic Function: Updates the snake's position, handles collisions, and checks food consumption.
• StartScreen: Displays the welcome screen before starting.
• GameOverScreen: Shows score and restart/exit options.
### ⚙️ Customization
Game Speed: Modify the Sleep(50); line in the main loop to adjust game speed. Decrease the value for a faster game or increase it for a slower game.
Grid Size: Change the WIDTH and HEIGHT macros to adjust the game grid dimensions.
Initial Tail Length: Modify the nTail variable in the Setup() function to change the starting tail length.
### 📦 Dependencies
<iostream>: For input/output operations.
<conio.h>: For handling keyboard input.
<cstdlib>: For random number generation.
<windows.h>: For the Sleep function and screen clearing.

#### Note: This game is case sensitive.

## *Enjoy playing the Snake game!*


