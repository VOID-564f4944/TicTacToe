#pragma once
#include "Types.h"

// returns a random valid move
int getRandomMove(const char* p_board);

// attempts to win immediately, otherwise blocks the opponent
// falls back to a random move if neither exists
int getMediumMove(char* p_board, char p_ai, char p_human);

// simple implementation of famous minimax algorithm with alpha beta pruning
int minimax(char* p_board, char p_ai, char p_human, bool p_isMaximizing, int p_alpha, int p_beta, int p_depth);

// returns the optimal move using the minimax algorithm
int getImpossibleMove(char* p_board, char p_ai, char p_human);

// executes an AI move based on the selected difficulty
void aiMove(char* p_board, char p_ai, char p_human, Difficulty p_difficulty);