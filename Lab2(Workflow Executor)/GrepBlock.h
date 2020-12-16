//
// Created by dementor on 15.12.2020.
//

#ifndef CLION2_GREPBLOCK_H
#define CLION2_GREPBLOCK_H
#include "Worker.h"

class GrepBlock: public Worker{
public:
    GrepBlock(string substring);
    bool execute(vector<string> &input, vector<string> &output, bool inputExists) override;
};
#endif //CLION2_GREPBLOCK_H
