//
// Created by Дима on 06.12.2020.
//

#include "GameCore.h"
#include <vector>
#include <iostream>
#include <string>
#include <random>
#include "Map.h"
#include "Player.h"
#include "Ships.h"
#include "Helpfunction.h"

void playGame(PlayerType firstPlayer, PlayerType secondPlayer, Player* first, Player *second, vector<vector<string>>& firstFiled, vector<vector<string>>& secondFiled, Map &map,
               int rounds, int currentRound, int &roundWonOne, int &roundWontwo, bool invisable) {
    int check = 0;
    int scoreFirst = 0;
    int scoreSecond = 0;
    int missFirst = 0;
    int missSecond = 0;
    int allShootsFirst = 0;
    int allShootsSecond = 0;
    while (scoreFirst != 20 && scoreSecond != 20) {
        while (check != MISS) {
            if (firstPlayer == Interactive) cout << "1st Player fire!" << endl;
            check = map.playerFire(secondFiled, first);
            if (check != EXIST) {
                allShootsFirst++;
            }
            if (check == EXIST){
                first->successFire(EXIST);
            }
            if (check == WOUND) {
                first->successFire(WOUND);
                if (firstPlayer == Interactive || secondPlayer == Interactive) {
                    cout << "1st Player wound enemy ship" << endl;
                    showTwoFields(firstFiled, secondFiled, invisable);
                }
                scoreFirst++;
                if (scoreFirst == 20) break;
            }
            if (check == MISS) {
                first->successFire(MISS);
                if (firstPlayer == Interactive || secondPlayer == Interactive)   cout << "1st player miss!" << endl;
                missFirst++;
            }
            if (firstPlayer == Interactive || secondPlayer == Interactive) {
                showTwoFields(firstFiled, secondFiled, invisable);
            }
        }
        check = 0;
        while (check != MISS){
            if (secondPlayer == Interactive) cout << "2nd Player fire!" << endl;
            check = map.playerFire(firstFiled, second);
            if (check != EXIST){
                allShootsSecond++;
            }
            if (check == EXIST){
                second->successFire(EXIST);
            }
            if (check == WOUND) {
                if (firstPlayer == Interactive || secondPlayer == Interactive) {
                    second->successFire(WOUND);
                    cout << "2nd player wound enemy ship" << endl;
                    showTwoFields(firstFiled, secondFiled, invisable);
                }
                scoreSecond++;
                if (scoreSecond == 20) break;
            }
            if (check == MISS) {
                second->successFire(MISS);
                if (firstPlayer == Interactive || secondPlayer == Interactive)   cout << "2nd player miss!" << endl;
                missSecond++;
            }
            if (firstPlayer == Interactive || secondPlayer == Interactive) {
                showTwoFields(firstFiled, secondFiled, invisable);
            }
        }
        check = 0;
    }
    if (scoreFirst == 20){
        showTwoFields(firstFiled, secondFiled, false);
        printWinnerInformation(rounds, currentRound, 1, allShootsFirst, missFirst);
       roundWonOne++;
    }
    else {
        showTwoFields(firstFiled, secondFiled, false);
        printWinnerInformation(rounds, currentRound, 2, allShootsSecond, missSecond);
        roundWontwo++;
    }
}

void runGame(int rounds, PlayerType firstPlayer, PlayerType secondPlayer) {
    Player *first = Player::createPlayer(firstPlayer);
    Player *second = Player::createPlayer(secondPlayer);

    vector<vector<string>> firstField = setGameField();
    vector<vector<string>> secondField = setGameField();

    Map map;

    int roundWonOne = 0;
    int roundWonTwo = 0;
    bool invisable = true;
    if (firstPlayer == Interactive) cout << "1st Player create ships" << endl;
    firstField = first->createShips();
    if (secondPlayer == Interactive) cout << "2nd Player create ships" << endl;
    secondField = second->createShips();
    if (firstPlayer != Interactive && secondPlayer != Interactive) invisable = false;
        showTwoFields(firstField, secondField, invisable);

for (int i = 0; i < rounds; i++){
playGame(firstPlayer, secondPlayer, first, second, firstField, secondField, map, rounds, i+1, roundWonOne, roundWonTwo, invisable);
if (i + 1 < rounds) {
    firstField = first->createShips();
    secondField = second->createShips();
    cout << "Next: " << i + 2 << "round!" << endl;
    showTwoFields(firstField, secondField, invisable);
}
}
if (roundWonOne > roundWonTwo){
    showWinner(1, roundWonOne, roundWonTwo);
}
else if(roundWonOne < roundWonTwo) {
    showWinner(2, roundWonOne, roundWonTwo);
}
else if (roundWonOne == roundWonTwo){
    showWinner(3, roundWonOne, roundWonTwo);
}

}