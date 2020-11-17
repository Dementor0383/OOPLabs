//
// Created by dementor on 22.10.2020.
//

#ifndef LAB1_TRIT_H
#define LAB1_TRIT_H

#include <iostream>

using namespace std;

enum class trit: short {
 False = 0, // -1 = 00
 Unknown = 1, // 0 = 01
 True = 3, // 1 = 11
};

trit operator!(trit a);
trit operator|(trit a, trit b);
trit operator&(trit a, trit b);
ostream& operator<<(ostream& out, trit a);
#endif //LAB1_TRIT_H
