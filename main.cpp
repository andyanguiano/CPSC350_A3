#include "FileIO.h"
#include <string>

int main(int argc, char **argv){
  char again = 'y';
  while(again != 'n'){
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
