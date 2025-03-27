

# Tic Tac Toe Game

**Project:** First Semester Project  
**Author:** Maaz Hassan
**Course:** Programming fundamentals

## Overview

This is a simple Tic Tac Toe game implemented in C++ as my first semester project. The game uses object-oriented programming (OOP) principles to model the game participants, the playing board, and the overall game logic. Two players take turns placing their tokens (either 'X' or 'O') on a 3x3 grid. The game checks for a win after each move and declares a winner when a player succeeds in placing three of their tokens in a row, column, or diagonal. If the board fills up with no winner, the game ends in a draw.

## Features

- **Player Management:**  
  Represents players with their names and tokens.

- **Board Handling:**  
  A 3x3 grid to manage the state of the game, check for valid moves, and determine if a win condition has been met.

- **Game Logic:**  
  Alternating turns between two players, input validation, and win/draw detection.

- **User Interaction:**  
  A console-based interface that prompts users to enter their moves.

## Getting Started

### Prerequisites

- A C++ compiler that supports C++11 (e.g., g++, clang, or Visual Studio)
- Basic knowledge of compiling and running C++ programs

### Compilation

If you are using **g++** in a terminal (e.g., Git Bash on Windows, Linux, or macOS):

1. Open your terminal.
2. Navigate to the directory containing the source code file (e.g., `main.cpp`):

   ```bash
   cd /path/to/your/project
   ```

3. Compile the project using g++:

   ```bash
   g++ -std=c++11 -o tic_tac_toe main.cpp
   ```

   If your project consists of multiple source files, include them all in the compile command.

### Running the Game

After successful compilation, run the game using:

```bash
./tic_tac_toe
```

Follow the on-screen instructions to play Tic Tac Toe.

## Project Structure

- **main.cpp:**  
  Contains the main function and initiates the game.

- **Participant, Grid, and GameBoard Classes:**  
  Implement the game logic and encapsulate the functionality for players and the game board.

## Future Enhancements

- Adding a graphical user interface (GUI)
- Implementing AI for single-player mode
- Enhancing error handling and input validation

## Acknowledgments

This project was developed as my first semester project to learn and apply the principles of object-oriented programming in C++. Special thanks to my instructors and peers for their support and feedback.

## License

This project is released under the MIT License.

