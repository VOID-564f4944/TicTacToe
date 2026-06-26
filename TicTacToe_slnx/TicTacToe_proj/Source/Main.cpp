#include <iostream>
#include <limits>

#ifdef _WIN32
#define FLUSH_SCREEN system("cls")
#else
#define FLUSH_SCREEN system("clear")
#endif

namespace Game
{
	constexpr int BOARD_CELLS = 9;
	constexpr int GRID_SIZE = 3;
	constexpr int WIN_PATTERNS = 8;

	constexpr char PLAYER_X = 'x';
	constexpr char PLAYER_O = 'o';
}

void printBoard(char* p_board)	//displays board on terminal
{
	FLUSH_SCREEN;

	std::cout << "Tic tac Toe\n";
	for (int index = 0; index < Game::BOARD_CELLS; index++)
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

bool playerInput(char* p_board, char p_player)	//takes valid input and return false if player wants to quit else true
{
	int location = 0;
	std::cout << "Enter the box number or 0 to quit : ";

	while (true)	//invalid input handling loop
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

		if (location < 1 || location > 9)
		{
			std::cout << "Please enter a number between 1 and 9: ";
			continue;
		}

		if (p_board[location - 1] == 'x' || p_board[location - 1] == 'o')
		{
			std::cout << "Box already taken. Choose another: ";
			continue;
		}

		break;
	}

	p_board[location - 1] = p_player;
	return true;
}

bool checkWinner(char* p_board, char p_player)	//returns true if current player has won else false
{
	static constexpr int s_wins[Game::WIN_PATTERNS][Game::GRID_SIZE] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},	//rows
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},	//columns
		{0, 4, 8}, {2, 4, 6}	//diagonals
	};

	for (int block = 0; block < 8; block++)
	{
		if (p_board[s_wins[block][0]] == p_player && p_board[s_wins[block][1]] == p_player && p_board[s_wins[block][2]] == p_player) {
			return true;
		}
	}

	return false;
}

bool checkDraw(char* p_board)	//returns true if game is a draw else false
{
	for (int index = 0; index < Game::BOARD_CELLS; index++)
	{
		if (p_board[index] >= '1' && p_board[index] <= '9') {
			return false;
		}
	}

	return true;
}

void resetBoard(char* p_board, char& p_player)	//resets board & player to default
{
	for (int index = 0; index < Game::BOARD_CELLS; index++)
	{
		p_board[index] = '1' + index;
	}

	p_player = 'x';

	printBoard(p_board);
}

void endGame(char* p_board, char& p_player, const char* p_message, bool p_showPlayer)
{
	if (p_showPlayer) {
		std::cout << p_player;
	}
	std::cout << p_message;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	FLUSH_SCREEN;
	resetBoard(p_board, p_player);
}

int main()
{
	char board[Game::BOARD_CELLS] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };	//default value of board
	char currentPlayer = Game::PLAYER_X;	//default value of current player

	printBoard(board);

	while (true)	//main game loop
	{
		std::cout << '\n' << currentPlayer << "'s turn\n";

		if (!playerInput(board, currentPlayer)) {
			break;
		}

		printBoard(board);

		if (checkWinner(board, currentPlayer))
		{
			endGame(board, currentPlayer, " is winner!", true);
			continue;
		}

		if (checkDraw(board))
		{
			endGame(board, currentPlayer, "Draw!", false);
			continue;
		}

		currentPlayer = (currentPlayer == Game::PLAYER_X) ? Game::PLAYER_O : Game::PLAYER_X;	//manages turns
	}
}