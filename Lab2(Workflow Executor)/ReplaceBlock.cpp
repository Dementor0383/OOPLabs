//
// Created by dementor on 15.12.2020.
//

#include "ReplaceBlock.h"

ReplaceBlock::ReplaceBlock(string oldWorld, string newWorld) {
arguments.push_back(oldWorld);
arguments.push_back(newWorld);
}

bool ReplaceBlock::execute(vector<string> &input, vector<string> &output, bool inputExists) {
if (inputExists != false){
    throw invalid_argument("Bad use ReplaceBlock");
    return true;
}
size_t findCheck;
for (auto &i : output){
    while((findCheck = i.find(arguments[0])) != string::npos){
        i.replace(findCheck, arguments[0].size(), arguments[1]);
    }
}
return false;
}