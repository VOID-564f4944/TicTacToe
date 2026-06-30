#pragma once

// returns true if the specified player has a winning pattern
bool checkWinner(const char* p_board, char p_player);

// returns treu if no moves remaining
bool checkDraw(const char* p_board);

// restores the game to its inintial state
void resetGame(char* p_board, char& p_player);

// return true if the specified board position is unoccupied
bool isAvailable(const char* p_board, int p_index);