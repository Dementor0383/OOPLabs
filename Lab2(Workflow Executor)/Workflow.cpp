//
// Created by dementor on 14.12.2020.
//

#include "Workflow.h"

void Workflow::execute() {
    vector<string> input;
    vector<string> output;
    bool inputExists = false;
    for (auto i : queueOfBlocks){
        inputExists = blocksOfProgram[i]->execute(input, output, inputExists);
        input = output;
    }
}