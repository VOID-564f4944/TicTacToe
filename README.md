# Tic-Tac-Toe

A terminal-based two-player Tic-Tac-Toe game written in C++.

## Features

- Two-player local multiplayer
- Input validation and error handling
- Cross-platform terminal support (Windows & Linux)
- Option to quit (since v1.1.0)

## How to Play

- Players take turns as `x` and `o`
- Enter a number (1-9) corresponding to the board position
- First to get 3 in a row wins, otherwise it's a draw

Board positions:

```
 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```

## Building

**Visual Studio:**
1. Open the `.slnx` file in Visual Studio
2. Press `Ctrl+F5` to build and run

**Linux/macOS:**
```bash
g++ main.cpp -o tictactoe
./tictactoe
```

**Windows (g++):**
```bash
g++ main.cpp -o tictactoe.exe
tictactoe.exe
```
