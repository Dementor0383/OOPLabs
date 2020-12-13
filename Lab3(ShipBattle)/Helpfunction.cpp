//
// Created by Дима on 03.12.2020.
//

#include "Helpfunction.h"

int xCoord(int numOfCells){
    return numOfCells * 2;
}

int yCoord(int numOfCells){
    return numOfCells * 2;
}

vector <vector <string>> checkCells(vector <vector <string>> map, int x, int y){
        if (x - 2 > 0 && y > 0 && y < map[x - 2].size()) {
            if (map[x - 2][y] == " ") map[x - 2][y] = "'";
        }
        if (x - 2 > 0 && y - 2 > 0) {
            if (map[x - 2][y - 2] == " ") map[x - 2][y - 2] = "'";
        }
        if (x - 2 > 0 && y + 2 < map[x - 2].size()) {
            if (map[x - 2][y + 2] == " ") map[x - 2][y + 2] = "'";
        }
    if (x > 0 && x < map.size() && y - 2 > 0) {
        if (map[x][y - 2] == " ") map[x][y - 2] = "'";
    }
    if (x > 0 && x < map.size() && y + 2 < map[x].size()) {
        if (map[x][y + 2] == " ") map[x][y + 2] = "'";
    }
        if (x + 2 < map.size() && y > 0 && y < map[x + 2].size()) {
            if (map[x + 2][y] == " ")  map[x + 2][y] = "'";
        }
        if (x + 2 < map.size() && y - 2 > 0) {
            if (map[x + 2][y - 2] == " ") map[x + 2][y - 2] = "'";
        }
        if (x + 2 < map.size() && y + 2 < map[x + 2].size()) {
            if (map[x + 2][y + 2] == " ") map[x + 2][y + 2] = "'";
        }
    return map;
}

void printWinnerInformation(int rounds, int numberRound, int numberPlayer, int allShoots, int missedShoot){
int roundsLeft = rounds - numberRound;
cout << "The " << rounds << " round was endeed!" << endl;
    cout << "Total number of shots fired: " << allShoots << endl;
    cout << "Number of missed shots fired: " << missedShoot << endl;
if (numberPlayer == 1) {
    cout << R"(
 __    _                  _
/  |  (_)                (_)
`| |   _  ___  __      __ _  _ __   _ __    ___  _ __
 | |  | |/ __| \ \ /\ / /| || '_ \ | '_ \  / _ \| '__|
_| |_ | |\__ \  \ V  V / | || | | || | | ||  __/| |
\___/ |_||___/   \_/\_/  |_||_| |_||_| |_| \___||_|
)" << endl;
}
    else if (numberPlayer == 2){
    cout << R"(
  ___    _                  _
 |__ \  (_)                (_)
    ) |  _  ___  __      __ _  _ __   _ __    ___  _ __
   / /  | |/ __| \ \ /\ / /| || '_ \ | '_ \  / _ \| '__|
  / /_  | |\__ \  \ V  V / | || | | || | | ||  __/| |
 |____| |_||___/   \_/\_/  |_||_| |_||_| |_| \___||_|
)" << endl;
}
    cout << "Remaining number of rounds: " << roundsLeft << endl;
}

void showWinner(int numberPlayer, int wonRoundsOne, int wonRoundsTwo)
{
    cout << "Total score : " << wonRoundsOne << " : " << wonRoundsTwo << endl;
    if(numberPlayer == 1)
        cout << R"(
  __   _         __  _                _             _
 /_ | (_)       / _|(_)              | |           (_)
  | |  _  ___  | |_  _  _ __    __ _ | | __      __ _  _ __   _ __    ___  _ __
  | | | |/ __| |  _|| || '_ \  / _` || | \ \ /\ / /| || '_ \ | '_ \  / _ \| '__|
  | | | |\__ \ | |  | || | | || (_| || |  \ V  V / | || | | || | | ||  __/| |
  |_| |_||___/ |_|  |_||_| |_| \__,_||_|   \_/\_/  |_||_| |_||_| |_| \___||_|
)" << endl;
    else if (numberPlayer == 2){
        cout << R"(
  ___    _         __  _                _             _
 |__ \  (_)       / _|(_)              | |           (_)
    ) |  _  ___  | |_  _  _ __    __ _ | | __      __ _  _ __   _ __    ___  _ __
   / /  | |/ __| |  _|| || '_ \  / _` || | \ \ /\ / /| || '_ \ | '_ \  / _ \| '__|
  / /_  | |\__ \ | |  | || | | || (_| || |  \ V  V / | || | | || | | ||  __/| |
 |____| |_||___/ |_|  |_||_| |_| \__,_||_|   \_/\_/  |_||_| |_||_| |_| \___||_|
)" << endl;
    }
    else if (numberPlayer == 3){
        cout << "Friendship won!!!" << endl;
        cout<< R"(
```````````````````````````````````````¶¶¶¶¶¶¶¶
````````````````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
`````````````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
``````````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶`¶``````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
````````````````````````¶¶¶¶¶¶¶¶¶¶¶```````````````¶¶`¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
```````````````````````¶¶¶¶¶¶¶¶`¶¶¶````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
`````````````¶¶¶¶¶¶¶``¶¶¶¶¶¶¶```````````````````¶¶¶¶¶``¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
`````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶````````¶``````````¶¶¶¶¶¶¶``¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
```````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶``````¶¶¶¶¶¶¶```````¶¶¶¶¶¶¶``¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
`````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶`````¶¶¶¶¶¶¶¶````````¶¶¶¶¶```¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶``````¶¶¶¶¶¶¶`````¶¶¶````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
```¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶````````¶``````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶`
``¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶```````````````````¶``````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
`¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶``````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
`¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶````````````¶¶¶¶¶`¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
``¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
``¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶`¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
```¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶`¶¶`¶¶`¶``¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶```¶`¶¶¶¶¶¶¶````¶¶`¶¶¶¶¶¶¶¶¶¶¶¶
`````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶```¶¶¶¶¶¶¶¶``````¶`¶¶¶¶¶¶¶¶¶¶¶¶¶¶
````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶`````¶¶¶¶¶¶¶¶¶¶````¶``¶¶¶¶¶`¶¶¶¶¶¶¶
``````````````¶¶¶``````````¶¶¶¶`¶¶¶¶``¶¶`¶`¶¶¶¶¶`¶¶¶¶¶
````````````````````````````¶¶¶¶`¶¶¶``¶```¶`¶¶`¶¶¶¶`¶¶
````````````````````````````¶¶¶¶¶¶¶`````¶`¶`¶¶¶¶¶¶¶¶¶¶¶
`````````````````````````````¶¶¶¶¶¶`¶¶¶``¶`¶¶¶¶¶¶¶¶¶¶¶¶
```````````````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
````````````````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
``````````````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶`¶¶¶¶
````````````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶`¶¶¶¶¶¶¶¶¶¶¶¶
```````````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶
```````````````````````````¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶)" << endl;

    }
}