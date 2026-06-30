# Tic-Tac-Toe

A terminal-based Tic-Tac-Toe game written in **C++** featuring both local multiplayer and AI opponents with multiple difficulty levels.

## Features

* 🎮 **Player vs Player (PvP)**
* 🤖 **Player vs AI (PvA)**
* 🧠 Three AI difficulty levels:

  * Easy
  * Medium
  * Impossible *(Minimax with Alpha-Beta Pruning)*
* ✅ Robust input validation and error handling
* 🚪 Quit an ongoing game at any time
* 🖥️ Cross-platform terminal support (Windows & Linux)
* 📁 Modular project structure

## How to Play

1. Select a game mode:

   * Player vs Player
   * Player vs AI
2. If playing against the AI:

   * Choose a difficulty level.
   * Select your character (`x` or `o`). **`x` always plays first.**
3. Enter a number (`1`-`9`) corresponding to the desired board position.
4. The first player to align three marks horizontally, vertically, or diagonally wins. If all cells are occupied without a winner, the game ends in a draw.

### Board Layout

```text
 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
```

## Building

### Visual Studio

1. Open the `.slnx` file.
2. Build and run using **Ctrl + F5**.

### Linux / macOS (g++)

> If all source files are in the project root:

```bash
g++ *.cpp -o tictactoe
./tictactoe
```

> If your project uses a `src/` directory:

```bash
g++ src/*.cpp -o tictactoe
./tictactoe
```

### Windows (g++)

> If all source files are in the project root:

```bash
g++ *.cpp -o tictactoe.exe
tictactoe.exe
```

> If your project uses a `src/` directory:

```bash
g++ src/*.cpp -o tictactoe.exe
tictactoe.exe
```

## Version

**Current Version:** `v1.2.0`

### Changelog

#### v1.2.0

* Added **Player vs AI (PvA)** mode.
* Added **Easy**, **Medium**, and **Impossible** AI difficulties.
* Implemented **Minimax with Alpha-Beta Pruning** for the Impossible AI.
* Refactored the project into multiple source and header files.
* Improved code organization and maintainability.

#### v1.1.0

* Added the option to quit an ongoing game.
* Improved input validation and error handling.

#### v1.0.0

* Initial release with local two-player gameplay.
