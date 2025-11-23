#include <iostream>
#include "src/homework/06_tic_tac_toe/tic_tac_toe.h"
#include "src/homework/06_tic_tac_toe/tic_tac_toe_4.h"

int main() {
    TicTacToe4 board;
    board.start_game("X");

    // Sequence from "Test win by fourth column 4"
    int moves[] = {4,1,8,2,12,3,16};
    for (int i = 0; i < 7; ++i) {
        board.mark_board(moves[i]);
    }
    std::cout << "Player after moves: " << board.get_player() << std::endl;
    std::cout << "Game over? " << board.game_over() << std::endl;
    std::cout << "Winner: " << board.get_winner() << std::endl;
    // display internal pegs via reflection not available; use display_board
    board.display_board();
    return 0;
}
