//
// Created by Дима on 06.12.2020.
//

#include "RandomPlayer.h"

vector<vector<string>> RandomPlayer::createShips() {
    return setRandomShip();
}

pair<int, int> RandomPlayer::nextStep(){
    int x = 1 + rand() % 10;
    int y = 1 + rand() % 10;
    x = xCoord(x);
    y = yCoord(y);
    return make_pair(x, y);
}