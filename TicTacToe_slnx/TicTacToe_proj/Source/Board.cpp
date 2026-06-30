#include "Constants.h"

bool checkWinner(const char* p_board, char p_player)
{
	static constexpr int s_wins[Constants::WIN_PATTERNS][Constants::GRID_SIZE] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},
		{0, 4, 8}, {2, 4, 6}
	};

	for (int block = 0; block < Constants::WIN_PATTERNS; block++)
	{
		if (p_board[s_wins[block][0]] == p_player && p_board[s_wins[block][1]] == p_player && p_board[s_wins[block][2]] == p_player) {
			return true;
		}
	}

	return false;
}

bool checkDraw(const char* p_board)
{
	for (int index = 0; index < Constants::BOARD_CELLS; index++)
	{
		if (p_board[index] >= '1' && p_board[index] <= '9') {
			return false;
		}
	}

	return true;
}

void resetGame(char* p_board, char& p_player)
{
	for (int index = 0; index < Constants::BOARD_CELLS; index++)
	{
		p_board[index] = '1' + index;
	}

	p_player = Constants::PLAYER_X;
}

bool isAvailable(const char* p_board, int p_index) {
	return p_board[p_index] >= '1' && p_board[p_index] <= '9';
}