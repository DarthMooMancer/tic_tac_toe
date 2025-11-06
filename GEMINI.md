# Gemini Code Assistant Context

This document provides context for the Gemini code assistant to understand and assist with the development of this project.

## Project Overview

This is a simple, terminal-based Tic-Tac-Toe game written in C++. It uses the `ncurses` library to create the game interface in the terminal. The game is played on a 5x5 grid.

The project is structured into three main components:

*   **`Engine`**: The main game engine that manages the game loop, player turns, and input processing.
*   **`Window`**: Handles the display of the game board in the terminal.
*   **`Player`**: Represents a player in the game.

## Building and Running

The project uses CMake for building.

**To build the project:**

```bash
mkdir build
cd build
cmake ..
make
```

**To run the game:**

```bash
./tic_tac_toe
```

## Development Conventions

*   **Language**: C++23
*   **Build System**: CMake
*   **Code Style**: The code follows a consistent style with the use of header guards, and clear naming conventions.
*   **Testing**: There are no tests in the project.
