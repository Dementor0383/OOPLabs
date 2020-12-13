//
// Created by Дима on 02.12.2020.
//

#ifndef MAIN_CPP_MAP_H
#define MAIN_CPP_MAP_H
#include "Player.h"

using namespace std;

class Map{
protected:
public:
int playerFire(vector<vector<string>> &map, Player* player);
};

#endif //MAIN_CPP_MAP_H
