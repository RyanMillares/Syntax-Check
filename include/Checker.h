#include <iostream>
using namespace std;
class Checker{
public:
  Checker(); //default constructor
  Checker(string filename); //overloaded constructor
  ~Checker(); //deconstructor

  void CheckDelimiters();
  char Closer(char c);
private:
  char letter; //used to extract chars from strings one at a time
  string currentLine; //used to extract lines one at a time
  string file; //name of file
  int line; //used to keep track of the line number
};
