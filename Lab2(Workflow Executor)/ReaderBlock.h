//
// Created by dementor on 15.12.2020.
//

#ifndef CLION2_READERBLOCK_H
#define CLION2_READERBLOCK_H
#include "Worker.h"
#include <fstream>

class ReaderBlock: public Worker{
public:
    ReaderBlock(string input);
    bool execute(vector<string> &input, vector<string> &output, bool inputExists) override;
};

#endif //CLION2_READERBLOCK_H
