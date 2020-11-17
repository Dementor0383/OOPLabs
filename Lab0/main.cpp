#include <iostream>
#include <vector>
#include <fstream>

#include "ClassCpp.h"

using namespace std;

int main(int argv, char **argc) {
setlocale (LC_ALL, "rus");
classForCountingWords text;
text.openFStream(argc);
text.analyzeString();
text.printWord();
    return 0;
}
