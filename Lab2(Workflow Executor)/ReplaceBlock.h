//
// Created by dementor on 15.12.2020.
//

#ifndef CLION2_REPLACEBLOCK_H
#define CLION2_REPLACEBLOCK_H
#include "Worker.h"

class ReplaceBlock: public Worker{
public:
    ReplaceBlock(string oldWorld, string newWorld);
    bool execute(vector<string> &input, vector<string> &output, bool inputExists) override;
};

#endif //CLION2_REPLACEBLOCK_H
