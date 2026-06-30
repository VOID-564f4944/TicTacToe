#include <iostream>
#include "limits"
#include <random>
#include <Constants.h>
#include <Board.h>
#include"Types.h"

int getRandomMove(const char* p_board)
{
	int availableIndexes[Constants::BOARD_CELLS] = {};
	int count = 0;

	for (int index = 0; index < Constants::BOARD_CELLS; index++)
	{
		if (isAvailable(p_board, index)) {
			availableIndexes[count++] = index;
		}
	}

	static std::random_device entropy;
	static std::mt19937 rng(entropy());
	std::uniform_int_distribution <int> dist(0, count - 1);
	int pick = dist(rng);

	return availableIndexes[pick];
}

int getMediumMove(char* p_board, char p_ai, char p_human)
{
	// check whether the ai can win in a single move
	for (int index = 0; index < Constants::BOARD_CELLS; index++)
	{
		if (isAvailable(p_board, index))
		{
			char temp = p_board[index];
			p_board[index] = p_ai;
			bool isWin = checkWinner(p_board, p_ai);
			p_board[index] = temp;

			if (isWin) {
				return index;
			}
		}
	}

	// otherwise, block the opponent's immediate winning move
	for (int index = 0; index < Constants::BOARD_CELLS; index++)
	{
		if (isAvailable(p_board, index))
		{
			char temp = p_board[index];
			p_board[index] = p_human;
			bool isWin = checkWinner(p_board, p_human);
			p_board[index] = temp;

			if (isWin) {
				return index;
			}
		}
	}

	return getRandomMove(p_board);
}

/*
	evaluates the current board using the minimax algorithm with alpha-beta pruning

	score interpretation:
	  10 - depth : ai victory (prefer faster wins)
	  depth - 10 : human victory (delay losses as long as possible)
	  0          : Draw

	alpha-beta pruning skips branches that cannot improve the current
	best outcome, reducing the number of positions that must be explored
*/
int minimax(char* p_board, char p_ai, char p_human, bool p_isMaximizing, int p_alpha, int p_beta, int p_depth)
{
	if (checkWinner(p_board, p_ai)) {
		// prefer faster victories
		return 10 - p_depth;
	}
	if (checkWinner(p_board, p_human)) {
		// prefer delaying defeat
		return p_depth - 10;
	}
	if (checkDraw(p_board)) {
		return 0;
	}

	if (p_isMaximizing)
	{
		int best = std::numeric_limits<int>::min();

		for (int index = 0; index < Constants::BOARD_CELLS; index++)
		{
			if (isAvailable(p_board, index))
			{
				char temp = p_board[index];
				p_board[index] = p_ai;
				int score = minimax(p_board, p_ai, p_human, false, p_alpha, p_beta, p_depth + 1);
				p_board[index] = temp;

				best = (score > best) ? score : best;

				if (best > p_alpha) {
					p_alpha = best;
				}

				// remaining moves cannot improve the current outcome
				if (p_beta <= p_alpha) {
					break;
				}
			}
		}

		return best;
	}
	else
	{
		int best = std::numeric_limits<int>::max();

		for (int index = 0; index < Constants::BOARD_CELLS; index++)
		{
			if (isAvailable(p_board, index))
			{
				char temp = p_board[index];
				p_board[index] = p_human;
				int score = minimax(p_board, p_ai, p_human, true, p_alpha, p_beta, p_depth + 1);
				p_board[index] = temp;

				best = (score < best) ? score : best;

				if (best < p_beta) {
					p_beta = best;
				}

				// remaining moves cannot improve the current outcome
				if (p_beta <= p_alpha) {
					break;
				}
			}
		}

		return best;
	}
}

int getImpossibleMove(char* p_board, char p_ai, char p_human)
{
	int bestScore = std::numeric_limits<int>::min();
	int bestMove = -1;

	for (int index = 0; index < Constants::BOARD_CELLS; index++)
	{
		if (isAvailable(p_board, index))
		{
			char temp = p_board[index];
			p_board[index] = p_ai;
			int score = minimax(p_board, p_ai, p_human, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), 0);
			p_board[index] = temp;

			if (score > bestScore)
			{
				bestScore = score;
				bestMove = index;
			}
		}
	}

	return bestMove;
}

void aiMove(char* p_board, char p_ai, char p_human, Difficulty p_difficulty)
{
	switch (p_difficulty)
	{
	case Difficulty::EASY:
		p_board[getRandomMove(p_board)] = p_ai;
		break;

	case Difficulty::MEDIUM:
		p_board[getMediumMove(p_board, p_ai, p_human)] = p_ai;
		break;

	case Difficulty::IMPOSSIBLE:
		p_board[getImpossibleMove(p_board, p_ai, p_human)] = p_ai;
		break;
	}
}