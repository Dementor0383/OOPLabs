//
// Created by Дима on 03.12.2020.
//
//x - по вертикали
//y - по горизонтали
#include "Ships.h"

vector <vector <string>> setGameField(){
    vector <vector<string>> map = {{" ", " ", " 1 ", " ", " 2 ", " ", " 3 ", " ", " 4 ", " ", " 5 ", " ", " 6 ", " ", " 7 ", " ", " 8 ", " ", " 9 ", " ", " 10 "},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",},
                                   {"A", "| ", " "," | ", " "," | ", " "," | ", " ", " | ", " "," | ", " "," | ", " "," | ", " "," | ", " "," | ", " ", " |"},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",},
                                   {"B", "| ", " "," | ", " "," | ", " "," | ", " ", " | ", " "," | ", " "," | ", " "," | ", " "," | ", " "," | ", " ", " |"},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",},
                                   {"C", "| ", " "," | ", " "," | ", " "," | ", " ", " | ", " "," | ", " "," | ", " "," | ", " "," | ", " "," | ", " ", " |"},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",},
                                   {"D", "| ", " "," | ", " "," | ", " "," | ", " ", " | ", " "," | ", " "," | ", " "," | ", " "," | ", " "," | ", " ", " |"},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",},
                                   {"E", "| ", " "," | ", " "," | ", " "," | ", " ", " | ", " "," | ", " "," | ", " "," | ", " "," | ", " "," | ", " ", " |"},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",},
                                   {"F", "| ", " "," | ", " "," | ", " "," | ", " ", " | ", " "," | ", " "," | ", " "," | ", " "," | ", " "," | ", " ", " |"},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",},
                                   {"G", "| ", " "," | ", " "," | ", " "," | ", " ", " | ", " "," | ", " "," | ", " "," | ", " "," | ", " "," | ", " ", " |"},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",},
                                   {"H", "| ", " "," | ", " "," | ", " "," | ", " ", " | ", " "," | ", " "," | ", " "," | ", " "," | ", " "," | ", " ", " |"},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",},
                                   {"I", "| ", " "," | ", " "," | ", " "," | ", " ", " | ", " "," | ", " "," | ", " "," | ", " "," | ", " "," | ", " ", " |"},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",},
                                   {"J", "| ", " "," | ", " "," | ", " "," | ", " ", " | ", " "," | ", " "," | ", " "," | ", " "," | ", " "," | ", " ", " |"},
                                   {"__", "____", "_", "____","_", "____","_","____","_","____","_","____","_","____","_","____","_",}};
    return map;
}

void showGameField(vector <vector<string>> map) {
    int arraySize = map.size();
    for (int i = 0; i < arraySize; i++) {
        int inArraySize = map[i].size();
        for (int j = 0; j < inArraySize; j++) {
            if (map[i][j] == "'") cout << " ";
            else cout << map[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

void showTwoFields(vector <vector<string>> map, vector <vector<string>> map1, bool invisable){
    int arraySize = map.size();
    for (int i = 0; i < arraySize; i++) {
        int inArraySize = map[i].size();
        for (int j = 0; j < inArraySize; j++) {
            if (map[i][j] == "'" || (invisable == true && map[i][j] == "#")) cout << " ";
            else cout << map[i][j];
        }
        cout << "                      ";
        for (int j = 0; j < inArraySize; j++) {
            if (map1[i][j] == "'" || (invisable == true && map1[i][j] == "#")) cout << " ";
            else cout << map1[i][j];
        }
        cout << endl;
    }
    cout << endl;
    cout << endl;
}

int shipLength(ShipType type){
    switch(type)
    {
        case fourDeck:
            return 4;
        case threeDeck:
            return 3;
        case twoDeck:
            return 2;
        case oneDeck:
            return 1;
        case unknown:
            return 0;
    }
    return -1;
}

int goodAxis(vector <vector <string>> map, int startX, int startY, int shipLength){
    int count = 0;
    for (int i = 1; i < shipLength; i++) {
        if (startX + xCoord(i + 1) >= map.size()) break;
        if (map[startX + xCoord(i)][startY] == " ") {
            count++;
            if (count == shipLength - 1) break;
        } else break;
    }
    if (count == shipLength - 1) return AXIS_X;//ось x подходит
    else {
        for (int i = 1; i < shipLength; i++) {
            if (startX - xCoord(i + 1) <= 0) break;
            if (map[startX - xCoord(i)][startY] == " ") {
                count++;
                if (count == shipLength - 1) break;
            } else break;
        }
    }
    if (count == shipLength - 1) return AXIS_X;
    count = 0;
    for (int i = 1; i < shipLength; i++) {
        if (startY + yCoord(i + 1) >= map[startX].size()) break;
        if (map[startX][startY + yCoord(i)] == " ") {
            count++;
            if (count == shipLength - 1) return AXIS_Y;
        } else break;
    }
    if (count == shipLength - 1) return AXIS_Y;//ось y подходит
    else {
        for (int i = 1; i < shipLength; i++) {
            if (startY - yCoord(i + 1) <= 0) break;
            if (map[startX][startY - yCoord(i)] == " ") {
                count++;
                if (count == shipLength - 1) return AXIS_Y;;
            } else break;
        }
    }
    return NO_AXIS;
}

int goodCoordinate(vector <vector <string>> map, int startX, int startY, int axis){
    if (axis == 0){//ось
        if (startX + 2 < map.size())
            if (map[startX + 2][startY] == " ") return RIGHT_MOVE;
        if (startX - 2 > 0)
            if (map[startX - 2][startY] == " ") return LEFT_MOVE;
    }
    else if (axis == 1){//ось y
        if (startY + 2 < map[startX].size())
            if (map[startX][startY + 2] == " ") return UP_MOVE;
        if (startY - 2 > 0)
            if (map[startX][startY - 2] == " ") return DOWN_MOVE;
    }
    return NO_VARIANT;
}

vector <vector <string>> surroundShip(vector <vector <string>> map, ShipCoordinate ship) {
    int length = ship.shipLength;
    int x, y;
    if (ship.axis == 0) {//x
        y = ship.otherAxis;
        for (int i = 0; i < length; i++) {
            x = ship.coordinate[i];
            map = checkCells(map, x, y);
        }
    } else {
        x = ship.otherAxis;
        for (int i = 0; i < length; i++) {
            y = ship.coordinate[i];
            map = checkCells(map, x, y);
        }
    }
    return map;
}

vector <vector <string>> setShips(vector <vector <string>> map, ShipType type){
    int length = shipLength(type);
    ShipCoordinate ship;
    ship.coordinate.resize(length);
    ship.shipLength = length;
    ship.coordinateNumber = 0;
    int x = 1 + rand() % 10;
    int y = 1 + rand() % 10;
    x = xCoord(x);
    y = yCoord(y);
    //int axis = rand() % 2;
    int checkAxis = goodAxis(map, x, y, length);
    while (map[x][y] != " " || checkAxis == NO_AXIS) {//???
        x = 1 + rand() % 10;
        y =  1 + rand() % 10;
        x = xCoord(x);
        y = yCoord(y);
        checkAxis = goodAxis(map, x, y, length);
    }
    int saveX = x, saveY = y;
    map[x][y] = "#";
    int i = 1;
    if (checkAxis == AXIS_X) {
        ship.coordinate[ship.coordinateNumber] = x;
        ship.otherAxis = y;
        ship.coordinateNumber++;
        ship.axis = 0;
        while(i < length){
            int checkCoordinate = goodCoordinate(map, x, y, 0);
            if( checkCoordinate == NO_VARIANT){
                x = saveX;
            }
            if(checkCoordinate == RIGHT_MOVE){
                x = x + 2;
                map[x][y] = "#";
                ship.coordinate[ship.coordinateNumber] = x;
                ship.coordinateNumber++;
                i++;
            }
            else {
                x = x - 2;
                map[x][y] = "#";
                ship.coordinate[ship.coordinateNumber] = x;
                ship.coordinateNumber++;
                i++;
            }
        }
    }
    else {
        ship.coordinate[ship.coordinateNumber] = y;
        ship.otherAxis = x;
        ship.coordinateNumber++;
        ship.axis = 1;
        while(i < length){
            int checkCoordintae = goodCoordinate(map, x, y, 1);
            if(checkCoordintae == NO_VARIANT){
                y = saveY;
            }
            if(checkCoordintae == DOWN_MOVE){
                y = y - 2;
                map[x][y] = "#";
                ship.coordinate[ship.coordinateNumber] = y;
                ship.coordinateNumber++;
                i++;
            }
            else{
                y = y + 2;
                map[x][y] = "#";
                ship.coordinate[ship.coordinateNumber] = y;
                ship.coordinateNumber++;
                i++;
            }
        }
    }
    map = surroundShip(map, ship);
    return map;
}

vector <vector <string>> setRandomShip(){
    vector<vector<string> > map = setGameField();
    map = setShips(map, ShipType::fourDeck);
    map = setShips(map, ShipType::threeDeck);
    map = setShips(map, ShipType::threeDeck);
    map = setShips(map, ShipType::twoDeck);
    map = setShips(map, ShipType::twoDeck);
    map = setShips(map, ShipType::twoDeck);
    map = setShips(map, ShipType::oneDeck);
    map = setShips(map, ShipType::oneDeck);
    map = setShips(map, ShipType::oneDeck);
    map = setShips(map, ShipType::oneDeck);
    return map;
}

bool checkFirstCoord (vector <vector <string>> map, string firstCoord){
    int x, y;
    x = xCoord(firstCoord[0] - (int)'A' + 1);
    if(firstCoord[1] == '1' && firstCoord[2] == '0') y = yCoord(10);
    else y = yCoord(firstCoord[1] - (int)'0');
    if (x < 2 || x > 20 || y < 2 || y > 20) return false;
    if (map[x][y] == " ") return true;
    else return false;
}

bool checkCoordinate (vector<vector<string>> map, string firstCoord, string secondCoord, ShipType type){
    int xt, yt, xo, yo;
    int length = shipLength(type);
    xt = xCoord(secondCoord[0]- (int)'A' + 1);
    if(secondCoord[1] == '1' && secondCoord[2] == '0') yt = yCoord(10);
    else yt = yCoord(secondCoord[1] - (int)'0');
    if (xt < 2 || xt > 20 || yt < 2 || yt > 20) return false;
    if (map[xt][yt] != " ") return false;
    xo = xCoord(firstCoord[0] - (int)'A' + 1);
    if(firstCoord[1] == '1' && firstCoord[2] == '0') yo = yCoord(10);
    else yo = yCoord(firstCoord[1] - (int)'0');
    if(xt != xo && yt != yo) return false;
    if (xt == xo){
        if(abs(yt - yo) != 2 * (length-1)) return false;
        if (yo > yt)
        {for (int i = 1; i < length - 1; i++) if (map[xo][yt + yCoord(i)] != " ") return false;}
        else
        {for (int i = 1; i < length - 1; i++) if (map[xo][yo + yCoord(i)] != " ") return false;}
    }
    else {
        if(abs(xt - xo) != 2 * (length-1)) return false;
        if (xo > xt)
        {for (int i = 1; i < length - 1; i++) if (map[xt + xCoord(i)][yo] != " ") return false;}
        else
        {for (int i = 1; i < length - 1; i++) if (map[xo + xCoord(i)][yo] != " ") return false;}
    }
    return true;
}

vector <vector <string>> setShipByPlayer(vector <vector <string>> map, string firstCoord, string secondCoord, ShipType type){
    int length = shipLength(type);
    int xt, yt, xo, yo;
    ShipCoordinate ship;
    ship.shipLength = length;
    ship.coordinateNumber = 0;
    ship.coordinate.resize(length);
    xt = xCoord(secondCoord[0]- (int)'A' + 1);
    if(secondCoord[1] == '1' && secondCoord[2] == '0') yt = yCoord(10);
    else yt = yCoord(secondCoord[1] - (int)'0');
    xo = xCoord(firstCoord[0] - (int)'A' + 1);
    if(firstCoord[1] == '1' && firstCoord[2] == '0') yo = yCoord(10);
    else yo = yCoord(firstCoord[1] - (int)'0');
    map[xo][yo] = "#";
    map[xt][yt] = "#";
    for (int i = 1; i < length - 1; i++){
        if (xt == xo){
            ship.axis = 1;
            ship.otherAxis = xo;
            if (yo > yt) {
                ship.coordinate[0] = yt; ship.coordinate[length - 1] = yo;
                ship.coordinate[i] = yt + yCoord(i);
                map[xo][yt + yCoord(i)] = "#";
            }
            else{
                ship.coordinate[0] = yo; ship.coordinate[length - 1] = yt;
                ship.coordinate[i] = yo + yCoord(i);
                map[xo][yo + yCoord(i)] = "#";
            }
        }
        else {
            ship.axis = 0;
            ship.otherAxis = yo;
            if (xo > xt) {
                ship.coordinate[0] = xt; ship.coordinate[length - 1] = xo;
                ship.coordinate[i] = xt + xCoord(i);
                map[xt + xCoord(i)][yo] = "#";
            }
            else {
                ship.coordinate[0] = xo; ship.coordinate[length - 1] = xt;
                ship.coordinate[i] = xo + xCoord(i);
                map[xo + xCoord(i)][yo] = "#";
            }
        }
    }
    if (length == 2) {
        if (xt == xo) {
            ship.axis = 1;
            ship.otherAxis = xo;
            if (yo > yt) {
                ship.coordinate[0] = yt;
                ship.coordinate[length - 1] = yo;
            } else {
                ship.coordinate[0] = yo;
                ship.coordinate[length - 1] = yt;
            }
        } else {
            ship.axis = 0;
            ship.otherAxis = yo;
            if (xo > xt) {
                ship.coordinate[0] = xt;
                ship.coordinate[length - 1] = xo;
            } else {
                ship.coordinate[0] = xo;
                ship.coordinate[length - 1] = xt;
            }
        }
    }
    map = surroundShip(map, ship);
    return map;
}