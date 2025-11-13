//h

#include<iostream>
#include<string>
#include<vector>

#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

class TicTacToeManager
{
public:
    void save_game(TicTacToe b);
    void get_winner_total(int& o, int& w, int&t);


private:
    std::vector<TicTacToe> games;
    int o_wins = 0;
    int x_wins = 0;
    int ties = 0;
};

#endif