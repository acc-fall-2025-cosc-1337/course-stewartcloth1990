//cpp
#include "tic_tac_toe.h"

using std::cout;

bool TicTacToe::game_over()
{
    // concise, robust win detection using explicit winning triplets
    const int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // rows
        {0,3,6}, {1,4,7}, {2,5,8}, // columns
        {0,4,8}, {2,4,6}           // diagonals
    };

    for (const auto &w : wins) {
        int a = w[0];
        int b = w[1];
        int c = w[2];
        if (pegs[a] == pegs[b] && pegs[b] == pegs[c] && pegs[a] != " ") {
            set_winner(pegs[a]);
            return true;
        }
    }

    if (check_board_full()) {
        set_winner("C");
        return true;
    }

    return false;
}

void TicTacToe::start_game(std::string first_player)
{
    player = first_player;
    clear_board();
}

void TicTacToe::mark_board(int position)
{
    pegs[position - 1] = player;
    set_next_player();
}

void TicTacToe::display_board() const
{
    for(long unsigned int i=0; i < pegs.size(); i+=3)
    {
        cout<<pegs[i]<<"|"<<pegs[i+1]<<"|"<<pegs[i+2]<<"\n";
    }
}

void TicTacToe::set_next_player()
{
    if(player == "X") 
    {
        player = "O";
    }
    else 
    {
        player = "X";
    }
}

bool TicTacToe::check_board_full()
{
    auto full = true;

    for(auto &peg: pegs)
    {
        if(peg == " ")
        {
            full = false;
            break;
        }
    }

    return full;
}

void TicTacToe::clear_board()
{
    for(auto &peg: pegs)
    {
        peg = " ";
    }
}

void TicTacToe::set_winner(std::string winner)
{
    // store the winner value ("X", "O", or "C" for cat's game / tie)
    this->winner = winner;
}

// Provide default (base-class) definitions for the virtual win-check
// methods so the vtable is emitted. Derived classes override these.
bool TicTacToe::check_column_win()
{
    return false;
}

bool TicTacToe::check_row_win()
{
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    return false;
}