#include "tic_tac_toe.h"
#include <limits>

using std::string;
using std::cin;
using std::cout;

int main()
{
	bool play_more = true;

	while (play_more)
	{
		TicTacToe tic_tac_toe;

		// ask for first player and validate input
		string first_player;
		do
		{
			cout << "Enter first player (X or O): ";
			cin >> first_player;
			if (first_player != "X" && first_player != "O")
			{
				cout << "Invalid player. Please enter X or O." << "\n";
			}
		} while (first_player != "X" && first_player != "O");

		tic_tac_toe.start_game(first_player);
		tic_tac_toe.display_board();

		// play the game
		while (!tic_tac_toe.game_over())
		{
			int position = 0;
			cout << "Enter position (1-9): ";

			// validate that user typed an integer in range
			while (true)
			{
				if (!(cin >> position))
				{
					// non-integer entered
					cout << "Invalid input. Please enter a number between 1 and 9." << "\n";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Enter position (1-9): ";
					continue;
				}
				if (position < 1 || position > 9)
				{
					cout << "Position out of range. Please enter a number between 1 and 9." << "\n";
					cout << "Enter position (1-9): ";
					continue;
				}
				break;
			}

			tic_tac_toe.mark_board(position);
			tic_tac_toe.display_board();
		}

		// display winner
		string winner = tic_tac_toe.get_winner();
		if (winner == "C")
		{
			cout << "The game is a tie." << "\n";
		}
		else
		{
			cout << "The winner is: " << winner << "\n";
		}

		// ask to play again
		string response;
		do
		{
			cout << "Play again? (y/n): ";
			cin >> response;
			if (response != "y" && response != "n")
			{
				cout << "Please enter 'y' or 'n'." << "\n";
			}
		} while (response != "y" && response != "n");

		if (response == "n")
			play_more = false;
	}

	return 0;
}
