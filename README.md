# Tic-Tac-Toe

A simple terminal-based Tic-Tac-Toe game.

## Build

To build the game, run the following commands:

```bash
cmake -S . -B build && cmake --build build
```

## Run

To run the game, execute the following command from the `build` directory:

```bash
./build/tic_tac_toe
```

## How to Play

- Use the numbers 1-9 on your keyboard to select a cell on the board.
- The numbers correspond to the cells as follows:

```
1 | 2 | 3
--+---+--
4 | 5 | 6
--+---+--
7 | 8 | 9
```

- Press 'q' to quit the game at any time.

## About

- This is a simple implementation of the classic Tic-Tac-Toe game.
- It is written in C++23.
- It uses the `ncurses` library to render the game in the terminal.
