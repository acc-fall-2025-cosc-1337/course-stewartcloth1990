//cpp
#include "tic_tac_toe.h"
#include <cmath>

using std::cout;

bool TicTacToe::game_over()
{
    // Use virtualized checks so derived board sizes (like 4x4) work correctly
    if (check_row_win() || check_column_win() || check_diagonal_win()) {
        return true;
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
    int size = static_cast<int>(std::sqrt(pegs.size()));
    for (int r = 0; r < size; ++r) {
        for (int c = 0; c < size; ++c) {
            if (c > 0) cout << "|";
            cout << pegs[r * size + c];
        }
        cout << "\n";
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
    int n = static_cast<int>(std::sqrt(pegs.size()));
    for (int c = 0; c < n; ++c) {
        const std::string &first = pegs[c];
        if (first == " " || first.empty()) continue;
        bool win = true;
        for (int r = 1; r < n; ++r) {
            if (pegs[c + r * n] != first) {
                win = false;
                break;
            }
        }
        if (win) {
            winner = first;
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_row_win()
{
    int n = static_cast<int>(std::sqrt(pegs.size()));
    for (int r = 0; r < n; ++r) {
        int start = r * n;
        const std::string &first = pegs[start];
        if (first == " " || first.empty()) continue;
        bool win = true;
        for (int c = 1; c < n; ++c) {
            if (pegs[start + c] != first) {
                win = false;
                break;
            }
        }
        if (win) {
            winner = first;
            return true;
        }
    }
    return false;
}

bool TicTacToe::check_diagonal_win()
{
    int n = static_cast<int>(std::sqrt(pegs.size()));
    // main diagonal
    const std::string &d1 = pegs[0];
    if (!(d1 == " " || d1.empty())) {
        bool win = true;
        for (int i = 1; i < n; ++i) {
            if (pegs[i * n + i] != d1) { win = false; break; }
        }
        if (win) { winner = d1; return true; }
    }

    // anti-diagonal: start at n-1, step by (n-1)
    const std::string &d2 = pegs[n - 1];
    if (!(d2 == " " || d2.empty())) {
        bool win = true;
        for (int i = 1; i < n; ++i) {
            if (pegs[(n - 1) + i * (n - 1)] != d2) { win = false; break; }
        }
        if (win) { winner = d2; return true; }
    }

    return false;
}