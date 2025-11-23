//h
#include "tic_tac_toe.h"
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

// tic_tac_toe_manager.h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class TicTacToeManager
{
public:
    void save_game(std::unique_ptr<TicTacToe>& game);
    void get_winner_total(int& o, int& w, int& t);
    void display_games() const;

private:
    std::vector<std::unique_ptr<TicTacToe>> games;
    int o_wins = 0;
    int x_wins = 0;
    int ties = 0;

    void update_winner_count(const std::string& winner);
};

#endif