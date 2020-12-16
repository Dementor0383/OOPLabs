//
// Created by dementor on 15.12.2020.
//

#include "ReaderBlock.h"

ReaderBlock::ReaderBlock(string input) {
    arguments.push_back(input);
}

bool ReaderBlock::execute(vector<string> &input, vector<string> &output, bool inputExists) {
    if (inputExists != false) {
     throw invalid_argument("Bad use ReaderBlock");
        return false;
    }
    string line;
    ifstream fileIn(arguments[0]);
    if(!fileIn) {
        throw invalid_argument("File" + arguments[0] + "can't open");
        return false;
    }
    while (getline(fileIn, line))
        output.push_back(line);
    fileIn.close();
    return false;
}