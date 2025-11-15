#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test is game over with a vector that has 9 pegs with value of space")
{
	TicTacToe tic_tac_toe;

	REQUIRE(false == tic_tac_toe.game_over());
}

TEST_CASE("Test is first player set correctly when starting the game")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	REQUIRE(tic_tac_toe.get_player() == "X");
}

TEST_CASE("Test if board is full - game over ")
{
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");
	REQUIRE(tic_tac_toe.get_player() == "X");

	tic_tac_toe.mark_board(1);
	REQUIRE(tic_tac_toe.get_player() == "O");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(2);
	REQUIRE(tic_tac_toe.get_player() == "X");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(3);
	REQUIRE(tic_tac_toe.get_player() == "O");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(6);
	REQUIRE(tic_tac_toe.get_player() == "X");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(4);
	REQUIRE(tic_tac_toe.get_player() == "O");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(7);
	REQUIRE(tic_tac_toe.get_player() == "X");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(5);
	REQUIRE(tic_tac_toe.get_player() == "O");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(9);
	REQUIRE(tic_tac_toe.get_player() == "X");
	REQUIRE(false  ==  tic_tac_toe.game_over());

	tic_tac_toe.mark_board(8);
	REQUIRE(tic_tac_toe.get_player() == "O");
	REQUIRE(true  ==  tic_tac_toe.game_over());

	// when all 9 slots are selected and no winner, the game should be a tie (winner == "C")
	REQUIRE(tic_tac_toe.get_winner() == "C");

}

TEST_CASE("test first player set to X") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");
	REQUIRE(tic_tac_toe.get_player() == "X");
}

TEST_CASE("Test first player set to O") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("O");
	REQUIRE(tic_tac_toe.get_player() == "O");
}

TEST_CASE("Test win by first column") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	// Sequence of moves to give X the first column: 1,4,7
	tic_tac_toe.mark_board(1); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(4); // X
	tic_tac_toe.mark_board(3); // O
	tic_tac_toe.mark_board(7); // X -> should win

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by second column") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	// Sequence to give X the second column: 2,5,8
	tic_tac_toe.mark_board(2); // X
	tic_tac_toe.mark_board(1); // O
	tic_tac_toe.mark_board(5); // X
	tic_tac_toe.mark_board(3); // O
	tic_tac_toe.mark_board(8); // X -> should win

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by third column") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	// Sequence to give X the third column: 3,6,9
	tic_tac_toe.mark_board(3); // X
	tic_tac_toe.mark_board(1); // O
	tic_tac_toe.mark_board(6); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(9); // X -> should win

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by first row ") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	// Sequence to give X the first row: 1,2,3
	tic_tac_toe.mark_board(1); // X
	tic_tac_toe.mark_board(4); // O
	tic_tac_toe.mark_board(2); // X
	tic_tac_toe.mark_board(5); // O
	tic_tac_toe.mark_board(3); // X -> should win

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by second row ") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	// Sequence to give X the second row: 4,5,6
	tic_tac_toe.mark_board(4); // X
	tic_tac_toe.mark_board(1); // O
	tic_tac_toe.mark_board(5); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(6); // X -> should win

	REQUIRE(true == tic_tac_toe.game_over());
}

TEST_CASE("Test win by third row") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	// Sequence to give X the third row: 7,8,9
	tic_tac_toe.mark_board(7); // X
	tic_tac_toe.mark_board(1); // O
	tic_tac_toe.mark_board(8); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(9); // X -> should win

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left ") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	// Sequence to give X the diagonal from top-left: 1,5,9
	tic_tac_toe.mark_board(1); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(5); // X
	tic_tac_toe.mark_board(3); // O
	tic_tac_toe.mark_board(9); // X -> should win

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("   Test win diagonally from bottom left") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	// Sequence to give X the diagonal from bottom-left: 7,5,3
	tic_tac_toe.mark_board(7); // X
	tic_tac_toe.mark_board(1); // O
	tic_tac_toe.mark_board(5); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(3); // X -> should win

	REQUIRE(true == tic_tac_toe.game_over());
}

TEST_CASE("Test win by first column - check after each move") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(4); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(3); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(7); REQUIRE(true  == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by second column - check after each move") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(2); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(1); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(3); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(8); REQUIRE(true  == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by third column - check after each move") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(3); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(1); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(6); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(9); REQUIRE(true  == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by first row - check after each move") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(4); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(3); REQUIRE(true  == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by second row - check after each move") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(4); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(1); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(6); REQUIRE(true  == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win by third row - check after each move") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(7); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(1); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(8); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(9); REQUIRE(true  == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win diagonally from top left - check after each move") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(3); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(9); REQUIRE(true  == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test win diagonally from bottom left - check after each move") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(7); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(1); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(5); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(2); REQUIRE(false == tic_tac_toe.game_over());
	tic_tac_toe.mark_board(3); REQUIRE(true  == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test winner is X when X wins by first column") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(4); // X
	tic_tac_toe.mark_board(3); // O
	tic_tac_toe.mark_board(7); // X -> wins

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test winner is O when O wins by first column") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(2); // X
	tic_tac_toe.mark_board(1); // O
	tic_tac_toe.mark_board(3); // X
	tic_tac_toe.mark_board(4); // O
	tic_tac_toe.mark_board(5); // X
	tic_tac_toe.mark_board(7); // O -> wins

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "O");
}

TEST_CASE("Test winner is X when X wins by second row") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(4); // X
	tic_tac_toe.mark_board(1); // O
	tic_tac_toe.mark_board(5); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(6); // X -> wins

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test winner is O when O wins by third row") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1); // X
	tic_tac_toe.mark_board(7); // O
	tic_tac_toe.mark_board(2); // X
	tic_tac_toe.mark_board(8); // O
	tic_tac_toe.mark_board(4); // X
	tic_tac_toe.mark_board(9); // O -> wins

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "O");
}

TEST_CASE("Test winner is X when X wins by diagonal top-left to bottom-right") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(5); // X
	tic_tac_toe.mark_board(3); // O
	tic_tac_toe.mark_board(9); // X -> wins

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test winner is O when O wins by diagonal bottom-left to top-right") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1); // X
	tic_tac_toe.mark_board(7); // O
	tic_tac_toe.mark_board(2); // X
	tic_tac_toe.mark_board(5); // O
	tic_tac_toe.mark_board(6); // X
	tic_tac_toe.mark_board(3); // O -> wins

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "O");
}

TEST_CASE("Test winner is C (tie) when board is full with no winner") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(1); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(3); // X
	tic_tac_toe.mark_board(6); // O
	tic_tac_toe.mark_board(4); // X
	tic_tac_toe.mark_board(7); // O
	tic_tac_toe.mark_board(5); // X
	tic_tac_toe.mark_board(9); // O
	tic_tac_toe.mark_board(8); // X

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "C");
}

TEST_CASE("Test winner is O when O wins by second column") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("O");

	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(1); // X
	tic_tac_toe.mark_board(5); // O
	tic_tac_toe.mark_board(3); // X
	tic_tac_toe.mark_board(8); // O -> wins

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "O");
}

TEST_CASE("Test winner is X when X wins by third column") {
	TicTacToe tic_tac_toe;
	tic_tac_toe.start_game("X");

	tic_tac_toe.mark_board(3); // X
	tic_tac_toe.mark_board(1); // O
	tic_tac_toe.mark_board(6); // X
	tic_tac_toe.mark_board(2); // O
	tic_tac_toe.mark_board(9); // X -> wins

	REQUIRE(true == tic_tac_toe.game_over());
	REQUIRE(tic_tac_toe.get_winner() == "X");
}

TEST_CASE("Test TicTacToeManager get_winner_total - X wins, O wins, and ties") {
	TicTacToeManager manager;

	// Game 1: X wins by first row
	TicTacToe game1;
	game1.start_game("X");
	game1.mark_board(1); // X
	game1.mark_board(4); // O
	game1.mark_board(2); // X
	game1.mark_board(5); // O
	game1.mark_board(3); // X wins
	manager.save_game(game1);

	// Game 2: O wins by first column
	TicTacToe game2;
	game2.start_game("X");
	game2.mark_board(2); // X
	game2.mark_board(1); // O
	game2.mark_board(3); // X
	game2.mark_board(4); // O
	game2.mark_board(5); // X
	game2.mark_board(7); // O wins
	manager.save_game(game2);

	// Game 3: Tie (C)
	TicTacToe game3;
	game3.start_game("X");
	game3.mark_board(1); // X
	game3.mark_board(2); // O
	game3.mark_board(3); // X
	game3.mark_board(6); // O
	game3.mark_board(4); // X
	game3.mark_board(7); // O
	game3.mark_board(5); // X
	game3.mark_board(9); // O
	game3.mark_board(8); // X - Tie
	manager.save_game(game3);

	// Game 4: X wins by diagonal
	TicTacToe game4;
	game4.start_game("X");
	game4.mark_board(1); // X
	game4.mark_board(2); // O
	game4.mark_board(5); // X
	game4.mark_board(3); // O
	game4.mark_board(9); // X wins
	manager.save_game(game4);

	// Game 5: O wins by second row
	TicTacToe game5;
	game5.start_game("O");
	game5.mark_board(4); // O
	game5.mark_board(1); // X
	game5.mark_board(5); // O
	game5.mark_board(2); // X
	game5.mark_board(6); // O wins
	manager.save_game(game5);

	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);

	REQUIRE(x_wins == 2);
	REQUIRE(o_wins == 2);
	REQUIRE(ties == 1);
}

TEST_CASE("Test TicTacToeManager get_winner_total - all X wins") {
	TicTacToeManager manager;

	// Game 1: X wins
	TicTacToe game1;
	game1.start_game("X");
	game1.mark_board(1);
	game1.mark_board(4);
	game1.mark_board(2);
	game1.mark_board(5);
	game1.mark_board(3);
	manager.save_game(game1);

	// Game 2: X wins
	TicTacToe game2;
	game2.start_game("X");
	game2.mark_board(7);
	game2.mark_board(1);
	game2.mark_board(5);
	game2.mark_board(2);
	game2.mark_board(3);
	manager.save_game(game2);

	// Game 3: X wins
	TicTacToe game3;
	game3.start_game("X");
	game3.mark_board(1);
	game3.mark_board(2);
	game3.mark_board(4);
	game3.mark_board(3);
	game3.mark_board(7);
	manager.save_game(game3);

	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);

	REQUIRE(x_wins == 3);
	REQUIRE(o_wins == 0);
	REQUIRE(ties == 0);
}

TEST_CASE("Test TicTacToeManager get_winner_total - all O wins") {
	TicTacToeManager manager;

	// Game 1: O wins
	TicTacToe game1;
	game1.start_game("O");
	game1.mark_board(4);
	game1.mark_board(1);
	game1.mark_board(5);
	game1.mark_board(2);
	game1.mark_board(6);
	manager.save_game(game1);

	// Game 2: O wins
	TicTacToe game2;
	game2.start_game("X");
	game2.mark_board(1);
	game2.mark_board(7);
	game2.mark_board(2);
	game2.mark_board(8);
	game2.mark_board(4);
	game2.mark_board(9);
	manager.save_game(game2);

	// Game 3: O wins
	TicTacToe game3;
	game3.start_game("O");
	game3.mark_board(2);
	game3.mark_board(1);
	game3.mark_board(5);
	game3.mark_board(3);
	game3.mark_board(8);
	manager.save_game(game3);

	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);

	REQUIRE(x_wins == 0);
	REQUIRE(o_wins == 3);
	REQUIRE(ties == 0);
}

TEST_CASE("Test TicTacToeManager get_winner_total - all ties") {
	TicTacToeManager manager;

	// Game 1: Tie
	TicTacToe game1;
	game1.start_game("X");
	game1.mark_board(1);
	game1.mark_board(2);
	game1.mark_board(3);
	game1.mark_board(6);
	game1.mark_board(4);
	game1.mark_board(7);
	game1.mark_board(5);
	game1.mark_board(9);
	game1.mark_board(8);
	manager.save_game(game1);

	// Game 2: Tie
	TicTacToe game2;
	game2.start_game("O");
	game2.mark_board(5);
	game2.mark_board(1);
	game2.mark_board(2);
	game2.mark_board(8);
	game2.mark_board(3);
	game2.mark_board(7);
	game2.mark_board(4);
	game2.mark_board(6);
	game2.mark_board(9);
	manager.save_game(game2);

	// Game 3: Tie
	TicTacToe game3;
	game3.start_game("X");
	game3.mark_board(5);
	game3.mark_board(1);
	game3.mark_board(3);
	game3.mark_board(7);
	game3.mark_board(2);
	game3.mark_board(8);
	game3.mark_board(4);
	game3.mark_board(6);
	game3.mark_board(9);
	manager.save_game(game3);

	int x_wins = 0, o_wins = 0, ties = 0;
	manager.get_winner_total(x_wins, o_wins, ties);

	REQUIRE(x_wins == 0);
	REQUIRE(o_wins == 0);
	REQUIRE(ties == 3);
}