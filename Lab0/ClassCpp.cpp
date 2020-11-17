//
// Created by dementor on 16.09.2020.
//

#include "ClassCpp.h"

bool classForCountingWords::comparatorSort(const pair<string, int> &a, const pair<string, int> &b){
    return a.second > b.second;
}

void classForCountingWords::closeFStream() {
    inFile.close();
    outFile.close();
}

classForCountingWords::classForCountingWords() {
    counterOfAllWords = 0;
};

void classForCountingWords::openFStream(char **arg){
inFile.open(arg[1]);
outFile.open(arg[2]);
}

string classForCountingWords::wordCheck(string word){
    mapForCountWords[word]++;
    counterOfAllWords++;
    word = "";
    return word;
}

void classForCountingWords::printWord(){
    vector <pair<string,int>> vectorOfWords(mapForCountWords.begin(), mapForCountWords.end());
    sort(vectorOfWords.begin(), vectorOfWords.end(), classForCountingWords::comparatorSort);
    auto iterator = vectorOfWords.begin();
    outFile <<"Word, Freq, Freq(%)"<<endl;
    while (iterator != vectorOfWords.end()){
        outFile << iterator->first << ", " << iterator->second <<", "<< round(((double)iterator->second / (double)counterOfAllWords) * 100) <<"%" << endl;
    iterator++;
    }
 closeFStream();
}

void classForCountingWords::analyzeString(){
    string word;
    string line;
    while (getline(inFile, line)) {
        if (word != ""){
            if (word.length() > 0) {
                word = wordCheck(word);
            }
        }
        for (char symbol : line) {
            if (((int) symbol >= '0' && (int) symbol <= '9') || ((int) symbol >= 'A' &&
            (int) symbol <= 'Z') || ((int) symbol >= 'a' && (int) symbol <= 'z')) {
                word += symbol;
            }
            else {
                if (word.length() > 0) {
                    word = wordCheck(word);
                }
            }
        }
    }
    if (word != "") {
        if (word.length() > 0) {
            word = wordCheck(word);
        }
    }
}