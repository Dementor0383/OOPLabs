//
// Created by dementor on 16.09.2020.
//

#ifndef LAB1_CLASSCPP_H
#define LAB1_CLASSCPP_H
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <list>
#include <string>
#include <algorithm>
#include<cmath>
using namespace std;

class classForCountingWords{
private:
    int counterOfAllWords;//хранится общее количество всех слов
    map<string, int> mapForCountWords;//контейнер для счетчика частоты слов
ifstream inFile;
ofstream outFile;
static bool comparatorSort(const pair<string, int> &a, const pair<string, int> &b);
void closeFStream();

public:
    classForCountingWords();
void openFStream(char **arg);

string wordCheck(string word);

void printWord();

void analyzeString();
};


#endif //LAB1_CLASSCPP_H
