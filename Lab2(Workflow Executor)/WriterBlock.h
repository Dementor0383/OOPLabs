//
// Created by dementor on 15.12.2020.
//

#ifndef CLION2_WRITERBLOCK_H
#define CLION2_WRITERBLOCK_H
#include "Worker.h"
#include <fstream>

class WriterBlock: public Worker{
public:
    WriterBlock(string input);
    bool execute(vector<string> &input, vector<string> &output, bool inputExists) override;
};
#endif //CLION2_WRITERBLOCK_H
