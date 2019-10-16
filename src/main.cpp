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
    exit(0);
  }
  do{
    Checker check(file);
    check.CheckDelimiters();
    cout << "Read another file? (yes/no)" << endl;
    cin >> ans;
    if(ans == "yes"){
      cout << "Please provide the file name: ";
      cin >> file;
    }
    else{
      cout << "Thanks for using!" << endl;
    }
  } while(ans == "yes");


}
