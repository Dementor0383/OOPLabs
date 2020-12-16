//
// Created by dementor on 14.12.2020.
//

#include "ProgramParser.h"
#include <fstream>

#define EMPTY_FILE 1
#define NON_KEY_WORD 2
#define NON_ARGUMENT 3
#define NON_ARGUMENT_END 4
#define DUPLICATE_INDEX 5
#define WRONG_READER_WRITE 6

void checkError(ifstream& fileIn, int errorCode){
    switch (errorCode){
        case EMPTY_FILE:
            fileIn.close();
            throw invalid_argument("Error, empty workflow file");
        case NON_KEY_WORD:
            fileIn.close();
            throw invalid_argument("Non desk at workflow file");
        case NON_ARGUMENT:
            fileIn.close();
            throw invalid_argument("Non argument at workflow file");
        case NON_ARGUMENT_END:
            fileIn.close();
            throw invalid_argument("Non csed at workflow file");
        case DUPLICATE_INDEX:
            fileIn.close();
            throw invalid_argument("Duplicate index ar workflow file");
        case WRONG_READER_WRITE:
            fileIn.close();
            throw invalid_argument("Wrong reader block or writer");
    }
}

shared_ptr<Worker> parseBlockName(ifstream& fileIn, int& reader, int& writer, int indexOfBlock){
string firstStr, secondStr;
fileIn >> firstStr;

if (firstStr != "=") throw invalid_argument("Bad syntax of argument");

fileIn >> firstStr;
shared_ptr<Worker> blockOfProgram;
if(firstStr == "readfile"){
    fileIn >> secondStr;
    blockOfProgram = make_shared<ReaderBlock>(secondStr);
    reader = indexOfBlock;
    return blockOfProgram;
}
else if(firstStr == "writefile"){
    fileIn >> secondStr;
    blockOfProgram = make_shared<WriterBlock>(secondStr);
    writer = indexOfBlock;
    return blockOfProgram;
}
else if(firstStr == "grep"){
    fileIn >> secondStr;
    blockOfProgram = make_shared<GrepBlock>(secondStr);
    return blockOfProgram;
}
else if(firstStr == "sort"){
    blockOfProgram = make_shared<SortBlock>();
    return blockOfProgram;
}
else if(firstStr == "replace"){
    fileIn >> firstStr;
    fileIn >> secondStr;
    blockOfProgram = make_shared<ReplaceBlock>(firstStr, secondStr);
    return blockOfProgram;
}
else if(firstStr == "dump"){
    fileIn >> secondStr;
    blockOfProgram = make_shared<DumpBlock>(secondStr);
    return blockOfProgram;
}
throw invalid_argument("Error, bad block" + firstStr);
return nullptr;
}

int parseBlockPart(map<unsigned int, shared_ptr<Worker>>& blocksOfProgram, ifstream& fileIn, int& numberOfReadBlock, int& numberOfWriteBlock){
    if(fileIn.eof()) return EMPTY_FILE;
    string str;
    unsigned int errorOfCode;
    fileIn >> str;
    int indexOfBlock = 0;
    if(str != "desc") return NON_KEY_WORD;
    int check = 0;
    while(true){
     try{
         if(fileIn.eof()) return NON_ARGUMENT;
         fileIn >> str;
         check++;
         if (check == 1 && str == "csed") return NON_ARGUMENT_END;
         if (str == "csed") break;
         indexOfBlock = stoi(str);
         if(blocksOfProgram.count(indexOfBlock)) return DUPLICATE_INDEX;
         else blocksOfProgram[indexOfBlock] = parseBlockName(fileIn, numberOfReadBlock, numberOfWriteBlock, indexOfBlock);
     }
     catch (exception& except){
         throw invalid_argument(except.what());
     }
    }
    return 0;
}

int parseQueue(vector<int>& queueOfBlocks, ifstream& fileIn, int reader, int writer) {
    if (fileIn.eof()) return NON_ARGUMENT;
    string str;
    int checkReader = 0;
    unsigned int indexOfFile = 0;
    while (true) {
        try {
            if (fileIn.eof()) break;
            fileIn >> str;
            indexOfFile = stoi(str);
            if (checkReader == 0 && reader != indexOfFile) return WRONG_READER_WRITE;
            if(fileIn.eof() && writer != indexOfFile) return WRONG_READER_WRITE;
            queueOfBlocks.push_back(indexOfFile);
            checkReader++;
            fileIn >> str;
            if (fileIn.eof()) break;
            if (str != "->") return NON_KEY_WORD;
        }
        catch (exception &except) {
            throw invalid_argument(except.what());
        }
    }
    return 0;
}

Workflow ProgramParser::parseProgramByBlock(string file) {
    unsigned int errorOfCode = 1;
    ifstream fileIn(file);
    map<unsigned int, shared_ptr<Worker>> blocksOfProgram;
    int numberOfReadBlock = 0;
    int numberOfWriteBlock = 0;
    errorOfCode = parseBlockPart(blocksOfProgram, fileIn, numberOfReadBlock, numberOfWriteBlock);
    checkError(fileIn, errorOfCode);
    vector<int> queueOfBlocks;
    errorOfCode = parseQueue(queueOfBlocks, fileIn, numberOfReadBlock, numberOfWriteBlock);
    checkError(fileIn, errorOfCode);
    fileIn.close();
    return Workflow(blocksOfProgram, queueOfBlocks);
}