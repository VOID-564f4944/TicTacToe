#pragma once

// clears the terminal screen
void flushScreen();

// displays the current state of game board
void printBoard(const char* p_board);

// displays the outcome of completed game
void showResult(char p_player, const char* p_message, bool p_showPlayer);