//
// Created by Дима on 06.12.2020.
//

#ifndef MAIN_CPP_PLAYER_H
#define MAIN_CPP_PLAYER_H
#include <iostream>
#include <cstdlib>
#include "GameCore.h"
#include "Ships.h"

using namespace std;

class Player{
protected:
    int successOnLastStep = MISS;
    int saveLastStep = MISS;
public:
virtual vector<vector <string>> createShips() = 0;
virtual pair<int, int> nextStep() = 0;
virtual void updateField() = 0;
void successFire(int success)
    {
        successOnLastStep = success;
    }
static Player *createPlayer(PlayerType Type);
};
#endif //MAIN_CPP_PLAYER_H
