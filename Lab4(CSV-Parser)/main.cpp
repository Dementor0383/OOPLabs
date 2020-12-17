#include <iostream>
#include "CSVParser.h"
#include <fstream>

using namespace std;

int main(int argc, char ** argv) {
    ifstream file("in.csv");
    CSVParser<int, string> parser(file, 0);

//    parser.setDelimiter('Your variant', field);
//    parser.setDelimiter('Your variant', column);
//    parser.setDelimiter('Your variant', line);

    for(tuple<int, string> rs : parser)
        cout << rs << endl;
    return 0;
}
