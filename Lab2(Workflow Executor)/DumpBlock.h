//
// Created by dementor on 15.12.2020.
//

#ifndef CLION2_DUMPBLOCK_H
#define CLION2_DUMPBLOCK_H
#include "Worker.h"
#include <fstream>

class DumpBlock: public Worker{
public:
    DumpBlock(string output);
    bool execute(vector<string> &input, vector<string> &output, bool inputExists) override;
};
#endif //CLION2_DUMPBLOCK_H
