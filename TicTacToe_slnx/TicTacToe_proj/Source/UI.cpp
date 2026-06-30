#include <iostream>
#include "Constants.h"

// use the appropriate command for the current operating system
void flushScreen()
{
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
}

void printBoard(const char* p_board)
{
	flushScreen();

	std::cout << "Tic tac Toe\n";
	for (int index = 0; index < Constants::BOARD_CELLS; index++)
	{
		std::cout << ' ' << p_board[index] << ' ';
		if (index == 2 || index == 5)
		{
			std::cout << "\n---+---+---\n";
			continue;
		}

		if (index != 8) {
			std::cout << '|';
		}
		else {
			std::cout << std::endl;
		}
	}
}

void showResult(char p_player, const char* p_message, bool p_showPlayer)
{
	if (p_showPlayer) {
		std::cout << p_player;
	}
	std::cout << p_message;
}