#include "tic_tac_toe_3.h"
#include <cmath>

bool check_column_win() 
{
    int dimension = static_cast<int>(std::sqrt(pegs.size()));
    for (int col = 0; col < dimension; ++col) 
    {
        std::string first = pegs[col];
        if (first == " ") continue;
        bool win = true;
        for (int row = 1; row < dimension; ++row) 
        {
            if (pegs[row * dimension + col] != first) { win = false; break; }
        }
        if (win) return true;
    }
    return false;
}
    

bool check_row_win() 
{
    int dimension = static_cast<int>(std::sqrt(pegs.size()));
    for (int row = 0; row < dimension; ++row) 
    {
        std::string first = pegs[row * dimension];
        if (first == " ") continue;
        bool win = true;
        for (int col = 1; col < dimension; ++col) 
        {
            if (pegs[row * dimension + col] != first) { win = false; break; }
        }
        if (win) return true;
    }
    return false;
}

bool check_diagonal_win() 
{
    int dimension = static_cast<int>(std::sqrt(pegs.size()));
    // main diagonal
    std::string first = pegs[0];
    if (first != " ") 
    {
        bool win = true;
        for (int i = 1; i < dimension; ++i) 
        {
            if (pegs[i * dimension + i] != first) { win = false; break; }
        }
        if (win) return true;
    }
        // anti-diagonal
    first = pegs[dimension - 1];
    if (first != " ") 
    {
        bool win = true;
        for (int i = 1; i < dimension; ++i) 
        {
            if (pegs[i * dimension + (dimension - 1 - i)] != first) { win = false; break; }
        }
        if (win) return true;
    }
        return false;
    }