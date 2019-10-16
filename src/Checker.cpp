#include <iostream>
#include <fstream>
#include "Checker.h"
#include "GenStack.h"
using namespace std;

Checker::Checker(){
  line = 0; //defaults line number to 0
  file = " "; //puts a blank string
}
Checker::Checker(string filename){
  line = 0;
  file = filename; //stores the passed file name into the variable

}
Checker::~Checker(){
  //delete this;
  //no idea what goes here, not like i have any arrays to delete lol
}

void Checker::CheckDelimiters(){
  ifstream source(file);

  if(source){ //if the given file exists
    GenStack<char> myStack(100); //myStack is a stack of chars, length 100
    while(getline(source, currentLine)){
      line++; //increment line number at start of every line
      for(int i = 0; i < currentLine.length(); ++i){
        letter = currentLine[i]; //take every character at a time

        if(letter == '{' || letter == '(' || letter == '['){
          myStack.push(letter); //push opening delimiter into stack

        }
         else if(letter == '}' || letter == ')' || letter == ']'){
           //otherwise, if it is a closing delimiter, then
           if(!myStack.isEmpty()){
             //as long as stack isnt empty, check if
             //the closing delimiter matches the last pushed delimiter
             //if matching, pop it
             if(myStack.peek() == '(' && letter == ')'){
               myStack.pop();
             } else if(myStack.peek() == '{' && letter == '}'){
               myStack.pop();
             } else if(myStack.peek() == '[' && letter == ']'){
               myStack.pop();
             }
             else{ //if no match, it is unexpected and fails task successfully
               cout << "Line " << line << ":" << i << ": Expected '" << Closer(myStack.peek()) << "', found '" << letter << "'"<< endl;
               exit(0);
             }
           }
           else{
             //if a closing delimiter is found when stack is empty
             //or there is no opening delimiter for it to match
             cout << "Line " << line << ":" << i << ": Unexpected symbol '" << letter << "'" << endl;
             exit(0);
           }
        }

      }
    }
    while(!myStack.isEmpty()){
      cout << "Reached end of file: Missing " << Closer(myStack.pop()) << endl;
      exit(0); //if reaches end of file and there are unmatched delimiters
      //it will state the first one and exit
    }

    source.close();
    cout << "File '" << file << "' successfully read with correct syntax." << endl;
    //should reach here only if all is good
  }
  else{ //if the given file doesnt exist
    cout << "ERROR: The file '" << file << "' could not be found." << endl;
    exit(0);
  }
}

//makes it easier for returning the closer given opener delimiter
//less typing
char Checker::Closer(char c){
  switch(c){
    case '(':
    return ')';
    break;
    case '[':
    return ']';
    break;
    case '{':
    return '}';
    break;

  }
}
