//
// Created by dementor on 15.12.2020.
//

#ifndef CLION2_SORTBLOCK_H
#define CLION2_SORTBLOCK_H
#include "Worker.h"
#include <algorithm>

class SortBlock: public Worker{
public:
    static bool comparator(string firstStr, string secondStr);
    bool execute(vector<string> &input, vector<string> &output, bool inputExists) override;
};
#endif //CLION2_SORTBLOCK_H
