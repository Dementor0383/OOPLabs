#include <iostream>
#include "ProgramParser.h"

using namespace std;

int main(int argc, char* argv[]) {
 if (argc < 2) throw invalid_argument("Wrong args, try again!");
 string file = argv[1];
 ProgramParser::parseProgramByBlock(file).execute();
return 0;
}
