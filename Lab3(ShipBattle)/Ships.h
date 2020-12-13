//
// Created by Дима on 03.12.2020.
//

#ifndef MAIN_CPP_SHIPS_H
#define MAIN_CPP_SHIPS_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <random>
#include "Helpfunction.h"
#include "Define.h"

using namespace std;

enum ShipType{
    fourDeck,
    threeDeck,
    twoDeck,
    oneDeck,
    unknown
};

typedef struct ShipCoordinate{
int shipLength;
int axis; // 0 - x, 1 - y
int otherAxis;
vector <int> coordinate;
int coordinateNumber;
}ShipCoordinate;

vector <vector<string>> setGameField();
void showGameField(vector <vector<string>> map);
void showTwoFields(vector <vector<string>> map, vector <vector<string>> map1, bool invisable);
int shipLength(ShipType type);
int goodAxis(vector <vector <string>> map, int startX, int startY, int shipLength);
int goodCoordinate(vector <vector <string>> map, int startX, int startY, int axis);
vector <vector <string>> setShips(vector <vector <string>> map, ShipType type);
vector <vector <string>> surroundShip(vector <vector <string>> map, ShipCoordinate ship);
vector <vector <string>> setRandomShip();
bool checkFirstCoord (vector<vector<string>>, string firstCoord);
bool checkCoordinate (vector<vector<string>> map, string firstCoord, string secondCoord, ShipType type);
vector <vector <string>> setShipByPlayer(vector <vector <string>> map, string firstCoord, string secondCoord, ShipType type);

#endif //MAIN_CPP_SHIPS_H
