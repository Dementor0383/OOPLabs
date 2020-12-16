//
// Created by dementor on 14.12.2020.
//

#ifndef CLION2_WORKFLOW_H
#define CLION2_WORKFLOW_H
#include "Worker.h"
#include <map>
#include <memory>

using namespace std;

class Workflow
{
private:
    map <unsigned int, shared_ptr<Worker>> blocksOfProgram;
    vector <int> queueOfBlocks;
public:
    Workflow(map<unsigned int, shared_ptr<Worker>> &inputBlocks, vector <int> &inputQueueBlocks){
        blocksOfProgram = move(inputBlocks);
        queueOfBlocks = move(inputQueueBlocks);
    }
    ~Workflow(){
        blocksOfProgram.clear();
        queueOfBlocks.clear();
    }
    void execute();
};
#endif //CLION2_WORKFLOW_H
