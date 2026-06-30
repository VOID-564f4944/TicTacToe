#pragma once
#include "Types.h"

// reads and validates guman player's move
// returns false if player choose to quite
bool humanMove(char* p_board, char p_player);

// waits for user to press enter before continuing
void waitForEnter();

// prompts a user to select a game mode
GameMode selectMode();

// prompts the user to select an AI difficulty
Difficulty selectDifficulty();

// prompts the user to choose 'x' or 'o'
// also determines the AI's character
char selectCharacter(char& p_ai);