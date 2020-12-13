//
// Created by Дима on 02.12.2020.
//

#include "Map.h"

int Map::playerFire(vector<vector<string>> &map, Player* player){
pair<int, int> coord;
coord = player->nextStep();
int x = coord.first;
int y = coord.second;
if (map[x][y] == "#"){
    map[x][y] = "*";
    return WOUND;
}
if (map[x][y] == "*" || map[x][y] == "-") return EXIST;
if (map[x][y] == " " || map[x][y] == "'") {
    map[x][y] = "-";
    return MISS;
}
return -1;
}

