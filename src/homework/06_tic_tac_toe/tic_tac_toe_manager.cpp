//cpp
#include "tic_tac_toe_manager.h"

void TicTacToeManager::save_game(TicTacToe& b)
{
    // Ensure game_over is called to determine the winner before saving
    b.game_over();
    
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
    o = x_wins;
    w = o_wins;
    t = ties;
}

