//
// Created by dementor on 15.12.2020.
//

#include "DumpBlock.h"

DumpBlock::DumpBlock(string output) {
    arguments.push_back(output);
}

bool DumpBlock::execute(vector<string> &input, vector<string> &output, bool inputExists) {
    if (inputExists != false){
        throw invalid_argument("Bad use DumpBlock");
        return true;
    }
    ofstream fileOut(arguments[0]);
    if(!fileOut){
        throw invalid_argument("File" + arguments[0] + "can't opened");
    }
    for (auto i : input){
        fileOut << i << endl;
    }
    fileOut.close();
    return false;
}
