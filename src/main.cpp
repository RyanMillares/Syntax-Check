#include <iostream>
#include "Checker.h"
using namespace std;
int main(int argc, char **argv){
  string file;
  string ans = "yes";
  if(argc > 1){

    file = argv[1];
  }
  else{
    cout << "No command line arguments provided" << endl;
    exit(0);
  }
  do{ //do once with command line arg file
    Checker check(file);
    check.CheckDelimiters();
    cout << "Read another file? (yes/no)" << endl;
    cin >> ans; //check if want to read another file
    if(ans == "yes"){
      cout << "Please provide the file name: ";
      cin >> file;
    }
    else{
      cout << "Thanks for using!" << endl;
    }
  } while(ans == "yes"); //repeat with manually inputted file


}
