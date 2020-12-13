//
// Created by Дима on 06.12.2020.
//

#include "ConsolePlayer.h"

 pair <int , int> ConsolePlayer::nextStep() {
    cout << "Input  next coordinate to fire" << endl;
    cout << "For example A5 or G10" << endl;
    int y = 0, x = 0;
    string coord;
    while (true){
        cin >> coord;
        x = xCoord(coord[0] - 'A' + 1);
        if(coord[1] == '1' && coord[2] == '0') y = yCoord(10);
        else y = yCoord(coord[1] - '0');
        if (!cin || !(x > 0 || x < 11) || !(y > 0 || y < 11)){
            cout << "Sorry, wrong coord, try again please" << endl;
            continue;
        }
        return make_pair(x, y);
    }
}

vector <vector <string>> ConsolePlayer::createShips() {
    char answer = 0;
    bool check = false;
    string firstCoord, secondCoord;
    int x, y;
    vector<vector<string>> map;
    map = setGameField();
    showGameField(map);
    while (tolower(answer, locale()) != 'y' &&
           tolower(answer, locale()) != 'n')//проверяем, хочет ли человек сам поставить корабли
    {
        cout << "Do you want to set the ships yourself? y/n" << endl;
        answer = getchar();
    }
    if (tolower(answer, locale()) == 'n'){
        map = setRandomShip();
    showGameField(map);
    return map;
}
    else {
        cout << "Please, type the coordinates of FourDeck ship." << endl;
        while (check != true) {
            cout << "First position:";
            cin >> firstCoord;
            check = checkFirstCoord(map, firstCoord);
            if (check == true) cout << "Last position:";
            else cout << "Sorry, wrong coord, try again please" << endl;
        }
        check = false;
        while (check != true){
         cin >> secondCoord;
         check = checkCoordinate(map, firstCoord, secondCoord, ShipType::fourDeck);
         if (check != true) cout << "Sorry, wrong coord, try again please" << endl << "Last position:";
        }
      map = setShipByPlayer(map, firstCoord, secondCoord, ShipType::fourDeck);
      showGameField(map);
      for (int i = 0; i < 2; i++){
          cout << "Please, type the coordinates of ThreeDeck ship." << endl;
          check = false;
          while (check != true) {
              cout << "First position:";
              cin >> firstCoord;
              check = checkFirstCoord(map, firstCoord);
              if (check == true) cout << "Last position:";
              else cout << "Sorry, wrong coord, try again please" << endl;
          }
          check = false;
          while (check != true){
              cin >> secondCoord;
              check = checkCoordinate(map, firstCoord, secondCoord, ShipType::threeDeck);
              if (check != true) cout << "Sorry, wrong coord, try again please" << endl << "Last position:";
          }
          map = setShipByPlayer(map, firstCoord, secondCoord, ShipType::threeDeck);
          showGameField(map);
      }
      for(int i = 0; i < 3; i++){
          cout << "Please, type the coordinates of TwoDeck ship." << endl;
          check = false;
          while (check != true) {
              cout << "First position:";
              cin >> firstCoord;
              check = checkFirstCoord(map, firstCoord);
              if (check == true) cout << "Last position:";
              else cout << "Sorry, wrong coord, try again please" << endl;
          }
          check = false;
          while (check != true){
              cin >> secondCoord;
              check = checkCoordinate(map, firstCoord, secondCoord, ShipType::twoDeck);
              if (check != true) cout << "Sorry, wrong coord, try again please" << endl << "Last position:";
          }
          map = setShipByPlayer(map, firstCoord, secondCoord, ShipType::twoDeck);
          showGameField(map);
      }
      for (int i = 0; i < 4; i++){
          cout << "Please, type the coordinate of OneDeck ship." << endl;
          check = false;
          while (check != true) {
              cout << "First position:";
              cin >> firstCoord;
              check = checkFirstCoord(map, firstCoord);
              if (check != true) cout << "Sorry, wrong coord, try again please" << endl;
          }
          x = xCoord(firstCoord[0] - (int)'A' + 1);
          if(firstCoord[1] == '1' && firstCoord[2] == '0') y = yCoord(10);
          else y = yCoord(firstCoord[1] - (int)'0');
          map[x][y] = "#";
          map = checkCells(map, x, y);
          showGameField(map);
      }
    }
    return map;
}
