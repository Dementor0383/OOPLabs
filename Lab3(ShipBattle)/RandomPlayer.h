//
// Created by Дима on 06.12.2020.
//

#ifndef MAIN_CPP_RANDOMPLAYER_H
#define MAIN_CPP_RANDOMPLAYER_H
#include "Player.h"

class RandomPlayer: public Player{
public:
vector<vector<string>> createShips() override;
pair<int, int> nextStep() override;
void updateField() override {};
};
#endif //MAIN_CPP_RANDOMPLAYER_H
