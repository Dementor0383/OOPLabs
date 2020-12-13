//
// Created by Дима on 06.12.2020.
//

#include "OptionalPlayer.h"

vector<vector <string>> OptionalPlayer::createShips(){
    return setRandomShip();
}


pair<int, int> OptionalPlayer::nextStep(){
    int x = 0;
    int y = 0;
    if(successOnLastStep == WOUND || saveLastStep == WOUND){
        if (successOnLastStep == WOUND && lastFire == 0) {
            xPrev = lastCoord.first;
            yPrev = lastCoord.second;
            saveLastStep = WOUND;
        }
        if (axis == -1) {
            for (int i = 0; i < 1; i++) {
                if (lastFire == 0 && xPrev - 2 > 0 && xPrev - 2 < 22) {
                    x = xPrev - 2;
                    y = yPrev;
                    lastFire++;
                    first = 1;
                    break;
                } else if (lastFire < 1) lastFire++;
                if (first == 1 && successOnLastStep == saveLastStep){
                    axis = 0;
                    coordinate[0] = xPrev;
                    coordinate[1] = xPrev - 2;
                    x = lastCoord.first;
                    y = lastCoord.second;
                    break;
                }
                if (lastFire == 1 && yPrev + 2 > 0 && yPrev + 2 < 22) {
                    x = xPrev;
                    y = yPrev + 2;
                    lastFire++;
                    second = 1;
                    break;
                } else if (lastFire < 2) lastFire++;
                if (second == 1 && successOnLastStep == saveLastStep){
                    axis = 1;
                    coordinate[0] = yPrev;
                    coordinate[1] = yPrev + 2;
                    x = lastCoord.first;
                    y = lastCoord.second;
                    break;
                }
                if (lastFire == 2 && xPrev + 2 > 0 && xPrev + 2 < 22) {
                    x = xPrev + 2;
                    y = yPrev;
                    lastFire++;
                    third = 1;
                    break;
                } else if (lastFire < 3) lastFire++;
                if (third == 1 && successOnLastStep == saveLastStep){
                    axis = 0;
                    coordinate[0] = xPrev;
                    coordinate[1] = xPrev + 2;
                    x = lastCoord.first;
                    y = lastCoord.second;
                    break;
                }
                if (lastFire == 3 && yPrev - 2 > 0 && yPrev - 2 < 22) {
                    x = xPrev;
                    y = yPrev - 2;
                    lastFire++;
                    fourth = 1;
                    break;
                } else if (lastFire < 4) lastFire++;
                if (fourth == 1 && successOnLastStep == saveLastStep){
                    axis = 1;
                    coordinate[0] = yPrev;
                    coordinate[1] = yPrev - 2;
                    x = lastCoord.first;
                    y = lastCoord.second;
                    break;
                }
                if (lastFire == 4) {
                    x = 1 + rand() % 10;
                    y = 1 + rand() % 10;
                    x = xCoord(x);
                    y = yCoord(y);
                    updateField();
                    break;
                }
            }
        }
        else{
            if (axis == 0){//значит сдвиг по x
                y = yPrev;
                if (xmove == 0) {
                    if (coordinate[1] + 2 > 0 && coordinate[1] + 2 < 22 && coordinate[1] + 2 != coordinate[0]) {
                        x = coordinate[1] + 2;
                        xmove++;
                    }
                     else if (coordinate[1] + 2 > 0 && coordinate[1] + 2 < 22 && coordinate[1] + 2 == coordinate[0]) {
                            if (coordinate[1] - 2 > 0 && coordinate[1] - 2 < 22) x = coordinate[1] - 2;
                            xmove--;
                        }
                    }
                else{
                    if (xmove == 1){
                        if (coordinate[0] - 2 > 0 && coordinate[0] - 2 < 22) x = coordinate[0] - 2;
                    }
                    if (xmove == -1){
                        if (coordinate[0] + 2 > 0 && coordinate[0] + 2 < 22) x = coordinate[0] + 2;
                    }
                    updateField();
                }
            }
            else {//сдвиг по y
                x = xPrev;
                if (ymove == 0) {
                    if (coordinate[1] + 2 > 0 && coordinate[1] + 2 < 22 && coordinate[1] + 2 != coordinate[0]) {
                        y = coordinate[1] + 2;
                        ymove++;
                    }
                    else if (coordinate[1] + 2 > 0 && coordinate[1] + 2 < 22 && coordinate[1] + 2 == coordinate[0]) {
                        if (coordinate[1] - 2 > 0 && coordinate[1] - 2 < 22) y = coordinate[1] - 2;
                        ymove--;
                    }
                }
                else{
                    if (ymove == 1){
                        if (coordinate[0] - 2 > 0 && coordinate[0] - 2 < 22) y = coordinate[0] - 2;
                    }
                    if (ymove == -1){
                        if (coordinate[0] + 2 > 0 && coordinate[0] + 2 < 22) y = coordinate[0] + 2;
                    }
                    updateField();
                }
            }
        }
    }
    else{
        x = 1 + rand() % 10;
        y = 1 + rand() % 10;
        x = xCoord(x);
        y = yCoord(y);
    }
    lastCoord.first = x;
    lastCoord.second = y;
    return make_pair(x, y);
}

void OptionalPlayer::updateField() {
    successOnLastStep = MISS;
    saveLastStep = MISS;
    lastFire = 0;
    axis = -1;
    first = 0;
    second = 0;
    third = 0;
    fourth = 0;
    lastCoord = make_pair<int, int>(0, 0);
    firstCoord = make_pair<int, int>(0, 0);
    coordinate = {0, 0, 0, 0};
    xPrev = yPrev = 0;
    xmove = ymove = 0;
}
