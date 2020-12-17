//
// Created by dementor on 17.12.2020.
//

#ifndef LAB4_CSV_PARSER__CSVPARSER_H
#define LAB4_CSV_PARSER__CSVPARSER_H
#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <limits>
#include <sstream>
#include <string>

using namespace std;


template<size_t i, typename... Arguments>
typename std::enable_if<(i >= sizeof...(Arguments))>::type
printTuple(std::ostream &, const std::tuple<Arguments...> &) { return; }

template<size_t i, typename... Arguments>
typename std::enable_if<(i < sizeof...(Arguments))>::type
printTuple(std::ostream &os, const std::tuple<Arguments...> &tup) {
    if (i != 0)
        os << "' ";
    os << std::get<i>(tup);
    printTuple<i + 1>(os, tup);
}

template<typename... Arguments>
std::ostream &operator<<(std::ostream &os, const std::tuple<Arguments...> &tup) {
    printTuple<0>(os, tup);
    return os << std::endl;
}

enum DelimiterType{
    field,
    column,
    line
};

template<class ... Arguments>
class CSVParser {
private:
    ifstream &input;
    size_t startNumberLine;
    int lengthFile = -1;
    char fieldDelimiter = '"';
    char columnDelimiter = ',';
    char lineDelimiter = '\n';

    template<typename C, typename T, typename A>
    void getLine(basic_istream<C, T> &is, basic_string<C, T, A> &str)
    {
        str.clear();

        char c;
        while(is.get(c))
        {
            if(c == lineDelimiter)
                break;
            str.push_back(c);
        }
    }

    void update(){
        input.clear();
        input.seekg(0, ios::beg);
    }

    int getLength(){
        if (lengthFile == -1){
            update();
            string line;
            while(getline(input, line)) lengthFile++;
            update();
        }
        return lengthFile;
    }

    class Iterator {
    private:
        string bufferLine;
        ifstream &input;
        size_t linePosition;
        CSVParser<Arguments ...> &parentClass;
        bool fileEOF = false;
        friend class CSVParser;
        void update(){
            input.clear();
            input.seekg(0, ios::beg);
        }
    public:
        Iterator(ifstream &fileIn, size_t linePosition, CSVParser<Arguments ...> &parentClass) : linePosition(linePosition), parentClass(parentClass), input(fileIn) {
            update();
            for(int i = 0; i <= linePosition; i++){
                parentClass.getLine(input, bufferLine);
                if (!input) throw invalid_argument("Bad argument");
            }
        }

        Iterator operator++(){
            if (linePosition < parentClass.lengthFile){
                linePosition++;
                update();
                for(int i = 0; i < linePosition; i++) parentClass.getLine(input, bufferLine);
            }
            else {
                bufferLine = "";
                fileEOF = true;
            }
            return *this;
        }

        bool operator==(Iterator &it){
            return this->fileEOF == it.fileEOF && this -> linePosition == it.linePosition && this->bufferLine == it.bufferLine;
        }

        bool operator!=(Iterator &it){
            return !(*this == it);
        }

        tuple<Arguments ...> operator*(){
            return parentClass.lineParser(bufferLine, linePosition);
        }
    };
public:
  explicit CSVParser(ifstream &fileIn, size_t startNumberLine) : input(fileIn), startNumberLine(startNumberLine) {
      if(fileIn.is_open() != true)
          throw invalid_argument("Can't open file!");
  }

  void setDelimiter(char Delimiter, DelimiterType typeOfDelimiter){
      switch(typeOfDelimiter){
          case field:
              fieldDelimiter = Delimiter;
              break;
          case column:
              columnDelimiter = Delimiter;
              break;
          case line:
              lineDelimiter = Delimiter;
              break;
      }
  }

  Iterator begin(){
      Iterator arg(input, startNumberLine + 1, *this);
      return arg;
  }

  Iterator end(){
      Iterator arg(input, 1, *this);
      arg.fileEOF = true;
      arg.bufferLine = "";
      arg.linePosition = getLength();
      return arg;
  }

  tuple<Arguments ...> lineParser(string &line, int position){
      size_t size = sizeof...(Arguments);
      if(line.empty()) throw invalid_argument("Line" + to_string(position) + "is empty");
      string saveLine;
      bool delimiterExsist = false;
      tuple<Arguments ...> table;
      for(char symbol : line){
          if (symbol == fieldDelimiter && delimiterExsist == false) {
              delimiterExsist = true;
          }
          else if(symbol == fieldDelimiter && delimiterExsist == true){
              delimiterExsist = false;
          }
          else if(symbol == columnDelimiter && delimiterExsist == false){
              saveLine += "|";
          }
          else {
              saveLine += symbol;
          }
      }
      return make_tuple(position, saveLine);
  }

};
#endif //LAB4_CSV_PARSER__CSVPARSER_H
