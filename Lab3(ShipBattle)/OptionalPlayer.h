//
// Created by Дима on 06.12.2020.
//

#ifndef MAIN_CPP_OPTIONALPLAYER_H
#define MAIN_CPP_OPTIONALPLAYER_H
#include "Player.h"

class OptionalPlayer : public Player{
private:
int first = 0;//x-1,y
int second = 0;//x, y + 1
int third = 0;//x + 1, y
int fourth = 0;//x, y -1
int lastFire = 0;
int axis = -1; // 0 - x, 1 - y
vector <int> coordinate = {0, 0, 0, 0};
pair <int, int> lastCoord = make_pair<int, int>(0, 0);
pair <int, int> firstCoord = make_pair<int, int>(0, 0);
int xPrev = 0;
int yPrev = 0;
int xmove = 0;
int ymove = 0;
public:
vector<vector <string>> createShips() override;
pair<int, int> nextStep() override;
void updateField() override;
};
#endif //MAIN_CPP_OPTIONALPLAYER_H
