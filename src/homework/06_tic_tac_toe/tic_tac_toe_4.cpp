#include "tic_tac_toe_4.h"

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/




/*
class function check_row_win
Win by row if
0, 1,  2,  3 are equal
4, 5,  6,  7 are equal
8, 9, 10, 11 are equal 
12,13,14, 15 are equal
*/



/*
class function check_diagonal_win
Win diagonally
0, 1,  2,  3
4, 5,  6,  7
8, 9, 10, 11
12,13,14, 15

*/

inline bool TicTacToe4::check_column_win() {
    // board is 4x4, stored in a vector of 16 elements (row-major)
    // columns start at 0..3, step by 4
    for (int col = 0; col < 4; ++col) {
        const std::string &first = pegs[col];
        if (first == " " || first.empty()) continue;
        bool win = true;
        for (int r = 1; r < 4; ++r) {
            if (pegs[col + r * 4] != first) {
                win = false;
                break;
            }
        }
        if (win) {
            winner = first;
            return true;
        }
    }

    // If no winner, check for full board (cat's game)
    bool full = true;
    for (const auto &p : pegs) {
        if (p == " " || p.empty()) {
            full = false;
            break;
        }
    }
    if (full) {
        winner = "C";
        return true;
    }

    return false;
}

inline bool TicTacToe4::check_row_win() {
    // rows start at 0,4,8,12
    for (int row = 0; row < 4; ++row) {
        int start = row * 4;
        const std::string &first = pegs[start];
        if (first == " " || first.empty()) continue;
        bool win = true;
        for (int c = 1; c < 4; ++c) {
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

    // If no winner, check for full board
    bool full = true;
    for (const auto &p : pegs) {
        if (p == " " || p.empty()) {
            full = false;
            break;
        }
    }
    if (full) {
        winner = "C";
        return true;
    }

    return false;
}

inline bool TicTacToe4::check_diagonal_win() {
    // main diagonal indices: 0, 5, 10, 15
    const std::string &d1 = pegs[0];
    if (!(d1 == " " || d1.empty())) {
        if (pegs[5] == d1 && pegs[10] == d1 && pegs[15] == d1) {
            winner = d1;
            return true;
        }
    }

    // anti-diagonal indices: 3, 6, 9, 12
    const std::string &d2 = pegs[3];
    if (!(d2 == " " || d2.empty())) {
        if (pegs[6] == d2 && pegs[9] == d2 && pegs[12] == d2) {
            winner = d2;
            return true;
        }
    }

    // If no winner, check for full board
    bool full = true;
    for (const auto &p : pegs) {
        if (p == " " || p.empty()) {
            full = false;
            break;
        }
    }
    if (full) {
        winner = "C";
        return true;
    }

    return false;
}