//
// Created by dementor on 14.12.2020.
//

#ifndef CLION2_PROGRAMPARSER_H
#define CLION2_PROGRAMPARSER_H
#include <iostream>
#include "Workflow.h"
#include "ReaderBlock.h"
#include "WriterBlock.h"
#include "GrepBlock.h"
#include "SortBlock.h"
#include "ReplaceBlock.h"
#include "DumpBlock.h"

class ProgramParser
{
public:
    static Workflow parseProgramByBlock(string file);
};
#endif //CLION2_PROGRAMPARSER_H
