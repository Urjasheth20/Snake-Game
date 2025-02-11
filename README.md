# Snake-Game
SNAKE GAME IN C++
Overview
This is a console-based Snake game implemented in C++ using basic libraries such as <iostream>, <conio.h>, <cstdlib>, and <windows.h>. The game features simple mechanics where the player controls the snake to eat food while avoiding walls and itself. The snake grows longer as it eats food, and the game ends when the snake collides with a wall or itself.
Features
•	Snake movement controlled by WASD keys.
•	Food randomly spawns on the screen.
•	Real-time game updates using the Sleep function.
•	Dynamic snake growth when eating food.
•	Game-over screen displaying the final score.
•	Restart or exit option after the game ends.
Gameplay Controls
•	W: Move Up
•	A: Move Left
•	S: Move Down
•	D: Move Right
•	R: Restart the game
•	X: Exit the game
How to Run
1.	Compile the code: Use a C++ compiler (e.g., g++, Visual Studio, or Code::Blocks) to compile the code. For example, if using g++, run the following command: 
2.	g++ -o snake_game snake_game.cpp
3.	Run the executable: 
4.	./snake_game
5.	Start the game: 
o	A start screen will appear. Press any key to begin.
o	Control the snake using WASD keys, eat food to increase your score, and avoid hitting the walls or yourself.
Code Structure
•	Global Variables: Maintain game state, such as snake position, food position, direction, score, and tail length.
•	Functions: 
o	Setup(): Initializes the game state.
o	Draw(): Renders the game screen.
o	Input(): Handles user input for controlling the snake.
o	Logic(): Updates the game state, including snake movement, collisions, and food consumption.
o	SpawnFood(): Generates new food at random positions.
o	StartScreen(): Displays the start screen.
o	GameOverScreen(): Displays the game-over screen and final score.
Customization
•	Game Speed: Modify the Sleep(100); line in the main loop to adjust game speed. Decrease the value for a faster game or increase it for a slower game.
•	Grid Size: Change the WIDTH and HEIGHT macros to adjust the game grid dimensions.
•	Initial Tail Length: Modify the nTail variable in the Setup() function to change the starting tail length.
Dependencies
•	<iostream>: For input/output operations.
•	<conio.h>: For handling keyboard input.
•	<cstdlib>: For random number generation.
•	<windows.h>: For the Sleep function and screen clearing.
Notes
•	This game is designed for Windows systems due to the use of <windows.h> and <conio.h>.
•	For cross-platform compatibility, consider replacing Sleep with std::this_thread::sleep_for and _getch() with platform-agnostic input handling libraries.
•	
Enjoy playing the Snake game!

