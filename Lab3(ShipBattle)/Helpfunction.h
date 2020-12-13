//
// Created by Дима on 03.12.2020.
//

#ifndef MAIN_CPP_HELPFUNCTION_H
#define MAIN_CPP_HELPFUNCTION_H
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int xCoord(int numOfCells);
int yCoord(int numOfCells);
vector <vector <string>> checkCells(vector <vector <string>> map, int x, int y);
void printWinnerInformation(int rounds, int numberRound, int numberPlayer, int allShoots, int missedShoot);
void showWinner(int numberPlayer, int wonRoundsOne, int wonRoundsTwo);
#endif //MAIN_CPP_HELPFUNCTION_H
