//
// Created by Дима on 06.12.2020.
//

#ifndef MAIN_CPP_CONSOLEPLAYER_H
#define MAIN_CPP_CONSOLEPLAYER_H
#include "Player.h"

class ConsolePlayer : public Player{
public:
vector <vector<string>> createShips() override;
pair <int , int> nextStep() override;
void updateField() override {};
};
#endif //MAIN_CPP_CONSOLEPLAYER_H
