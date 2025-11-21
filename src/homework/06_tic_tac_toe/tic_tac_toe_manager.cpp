//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(TicTacToe b)
{
    games.push_back(b);
    std::string winner = b.get_winner();
    if (winner == "X")
    {
        x_wins++;
    }
    else if (winner == "O")
    {
        o_wins++;
    }
    else if (winner == "C")
    {
        ties++;
    }
}

void TicTacToeManager::get_winner_total(int& o, int& w, int& t)
{
    o = o_wins;
    w = x_wins;
    t = ties;
}

