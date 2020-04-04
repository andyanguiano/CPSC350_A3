//Andy Anguiano
//2316199
//aanguiano@champman.edu
//CPSC 350-02
//Assignemnt 3

#include "FileIO.h"
#include <string>
//runs the program
int main(int argc, char **argv){
  //creates char to go again
  char again = 'y';
  //while the user still wants to check
  while(again != 'n'){
    //takes command line argument and creats a fileIO object and runs readfile
    //checks if user wants to go through another file
    if(argc > 1){
      string file = argv[1];
      string delim = "";
      FileIO<char> *fileIO = new FileIO<char>();
      delim = fileIO->ReadFile(file);
      again = fileIO->getAgainCheck();
      delete fileIO;
      if(again == 'y'){
        cout << "Enter the next file name: ";
        cin >> file;
        continue;
      }else{
        break;
      }
    }else{
      cout << "Enter the file name when compiling the program." << endl;
      return 0;
    }
  }
  return 0;
}
