//
// Created by dementor on 14.12.2020.
//

#ifndef CLION2_WORKER_H
#define CLION2_WORKER_H
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Worker{
protected:
    vector<string> arguments;
public:
    virtual ~Worker() = default;
    virtual bool execute(vector<string> &input, vector<string> &output, bool inputData) = 0;
};

#endif //CLION2_WORKER_H
