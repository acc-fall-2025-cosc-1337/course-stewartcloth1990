#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

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