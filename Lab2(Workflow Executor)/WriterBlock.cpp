//
// Created by dementor on 15.12.2020.
//

#include "WriterBlock.h"

WriterBlock::WriterBlock(string input) {
    arguments.push_back(input);
}

bool WriterBlock::execute(vector<string> &input, vector<string> &output, bool inputExists) {
    if (inputExists != false) {
        throw invalid_argument("Bad use WriterBlock");
        return false;
    }
    ofstream fileOut(arguments[0]);
    if(!fileOut){
        throw invalid_argument("File" + arguments[0] + "can't opened");
        return false;
    }
    for(auto &i : input){
        fileOut << i << endl;
    }
    fileOut.close();
    return true;
}