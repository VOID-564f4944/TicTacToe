#include <iostream>
#include "Constants.h"
#include "UI.h"
#include "Board.h"
#include "Input.h"
#include "Types.h"
#include "AI.h"

void playPvp()
{
	char board[Constants::BOARD_CELLS] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char currentPlayer = Constants::PLAYER_X;

	printBoard(board);

	while (true)
	{
		std::cout << '\n' << currentPlayer << "'s turn\n";

		if (!humanMove(board, currentPlayer)) {
			break;
		}

		printBoard(board);

		if (checkWinner(board, currentPlayer))
		{
			showResult(currentPlayer, " is winner!", true);
			waitForEnter();
			resetGame(board, currentPlayer);
			printBoard(board);
			continue;
		}

		if (checkDraw(board))
		{
			showResult(currentPlayer, "Draw!", false);
			waitForEnter();
			resetGame(board, currentPlayer);
			printBoard(board);
			continue;
		}

		currentPlayer = (currentPlayer == Constants::PLAYER_X) ? Constants::PLAYER_O : Constants::PLAYER_X;
	}
}

void playPva()
{
	char board[Constants::BOARD_CELLS] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	Difficulty difficulty = selectDifficulty();
	char aiPlayer;
	char humanPlayer = selectCharacter(aiPlayer);
	char currentPlayer = Constants::PLAYER_X;

	printBoard(board);

	while (true)
	{
		if (currentPlayer == humanPlayer)
		{
			if (!humanMove(board, humanPlayer))
			{
				break;
			}

			printBoard(board);
		}

		if (currentPlayer == aiPlayer)
		{
			std::cout << "\nAI's turn...\n";
			aiMove(board, aiPlayer, humanPlayer, difficulty);
			printBoard(board);
		}

		if (checkWinner(board, currentPlayer))
		{
			showResult(currentPlayer, " is winner!", true);
			waitForEnter();
			resetGame(board, currentPlayer);
			printBoard(board);
			continue;
		}

		if (checkDraw(board))
		{
			showResult(currentPlayer, "Draw!", false);
			waitForEnter();
			resetGame(board, currentPlayer);
			printBoard(board);
			continue;
		}

		currentPlayer = (currentPlayer == Constants::PLAYER_X) ? Constants::PLAYER_O : Constants::PLAYER_X;
	}
}