#include <iostream>
#include <limits>
#include "Constants.h"
#include "Types.h"

bool humanMove(char* p_board, char p_player)
{
	int location = 0;
	std::cout << "Enter the box number or 0 to quit : ";

	while (true)
	{
		if (!(std::cin >> location))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Enter a number 1-9: ";
			continue;
		}

		if (location == 0) {
			return false;
		}

		if (location < 1 || location > Constants::BOARD_CELLS)
		{
			std::cout << "Please enter a number between 1 and 9: ";
			continue;
		}

		if (p_board[location - 1] == Constants::PLAYER_X || p_board[location - 1] == Constants::PLAYER_O)
		{
			std::cout << "Box already taken. Choose another: ";
			continue;
		}

		break;
	}

	p_board[location - 1] = p_player;

	return true;
}

GameMode selectMode()
{
	std::cout << "Select a mode from the following-\n" << "1. PvP\n2. PvA\n" << "Enter 1 or 2 : ";

	int mode = 0;

	while (true)
	{
		if (!(std::cin >> mode))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Enter a number 1 or 2 : ";
			continue;
		}

		if (mode != 1 && mode != 2)
		{
			std::cout << "Please enter 1 or 2 : ";
			continue;
		}

		break;
	}

	if (mode == 1) {
		return GameMode::PVP;
	}
	else {
		return GameMode::PVA;
	}
}

Difficulty selectDifficulty()
{
	std::cout << "Select a difficulty from the following-\n" << "1. Easy\n2. Medium\n3. Impossible\n" << "Enter 1, 2 or 3 : ";

	int difficulty = 0;

	while (true)
	{
		if (!(std::cin >> difficulty))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Enter a number 1-3 : ";
			continue;
		}

		if (difficulty < 1 || difficulty > 3)
		{
			std::cout << "Please enter a number between  1 and 3 : ";
			continue;
		}

		break;
	}

	if (difficulty == 1) {
		return Difficulty::EASY;
	}
	else if (difficulty == 2) {
		return Difficulty::MEDIUM;
	}
	else {
		return Difficulty::IMPOSSIBLE;
	}
}

char selectCharacter(char& p_ai)
{
	std::cout << "Select 'x' or 'o' (Remember 'x' goes first) : ";

	char humanPlayer = '\0';

	while (true)
	{
		if (!(std::cin >> humanPlayer))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Enter either 'x' or 'o'\n";
			continue;
		}

		if (humanPlayer != Constants::PLAYER_X && humanPlayer != Constants::PLAYER_O)
		{
			std::cout << "Please enter either 'x' or 'o'\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		break;
	}

	p_ai = (humanPlayer == Constants::PLAYER_X) ? Constants::PLAYER_O : Constants::PLAYER_X;

	return humanPlayer;
}

void waitForEnter()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	// discard any extra characters entered before pressing enter
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}