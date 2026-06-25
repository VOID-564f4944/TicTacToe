#include <iostream>
#include <limits>

#ifdef _WIN32
#define FLUSH_SCREEN system("cls")
#else
#define FLUSH_SCREEN system("clear")
#endif

void printBoard(char* p_board)	//displays board on terminal
{
	FLUSH_SCREEN;

	std::cout << "Tic tac Toe\n";
	for (int index = 0; index < 9; index++)
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

void playerInput(char* p_board, char p_player)
{
	int location = 0;
	std::cout << "Enter the box number : ";

	while (true)	//invalid input handling loop
	{
		if (!(std::cin >> location))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Enter a number 1-9: ";
			continue;
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
}

bool checkWinner(char* p_board, char p_player)	//returns true if current player has won else false
{
	static int wins[8][3] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},	//rows
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},	//columns
		{0, 4, 8}, {2, 4, 6}	//diagonals
	};

	for (int block = 0; block < 8; block++)
	{
		if (p_board[wins[block][0]] == p_player && p_board[wins[block][1]] == p_player && p_board[wins[block][2]] == p_player) {
			return true;
		}
	}

	return false;
}

bool checkDraw(char* p_board)	//returns true if game is a draw else false
{
	for (int index = 0; index < 9; index++)
	{
		if (p_board[index] >= '1' && p_board[index] <= '9') {
			return false;
		}
	}

	return true;
}

void resetBoard(char* p_board, char& p_player)	//resets board & player to default
{
	for (int index = 0; index < 9; index++)
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
	std::cin.ignore();
	std::cin.get();
	FLUSH_SCREEN;
	resetBoard(p_board, p_player);
}

int main()
{
	char board[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };	//default value of board
	char currentPlayer = 'x';	//default value of current player

	printBoard(board);

	while (true)	//main game loop
	{
		std::cout << '\n' << currentPlayer << "'s turn\n";
		playerInput(board, currentPlayer);
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

		currentPlayer = (currentPlayer == 'x') ? 'o' : 'x';	//manages turns
	}
}