//
// Created by dementor on 15.12.2020.
//

#include "GrepBlock.h"

GrepBlock::GrepBlock(string substring) {
    arguments.push_back(substring);
}

bool GrepBlock::execute(vector<string> &input, vector<string> &output, bool inputExists) {
    if(inputExists != false) {
        throw invalid_argument("No file for grep");
        return false;
    }
    output.clear();
    size_t findCheck = 0;
    for(auto i : input){
        findCheck = i.find(arguments[0]);
        if(findCheck != string::npos)
        output.push_back(i);
    }
    return false;
}