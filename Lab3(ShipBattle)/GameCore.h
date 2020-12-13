//
// Created by Дима on 06.12.2020.
//

#ifndef MAIN_CPP_GAMECORE_H
#define MAIN_CPP_GAMECORE_H


using namespace std;

enum PlayerType
{
    Random,
    Optional,
    Interactive
};

void runGame(int rounds, PlayerType firstPlayer, PlayerType secondPlayer);

#endif //MAIN_CPP_GAMECORE_H
