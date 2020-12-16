//
// Created by dementor on 15.12.2020.
//

#include "SortBlock.h"

bool SortBlock::comparator(string firstStr, string secondStr) {
   return firstStr > secondStr;
}

bool SortBlock::execute(vector<string> &input, vector<string> &output, bool inputExists) {
    if (inputExists != false){
        throw invalid_argument("Bad use of SortBlock");
        return true;
    }
    sort(output.begin(), output.end(), SortBlock::comparator);
    return false;
}