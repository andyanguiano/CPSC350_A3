#include "Delimeter.h"
#include <fstream>

template <class T>

class FileIO{
  public:
    FileIO();
    ~FileIO();

    string ReadFile(string file);

  private:
    int m_delimCount;
};

template <class T>
FileIO<T>:FileIO(){
  m_delimCount = 0;
}

template <class T>
FileIO<T>::~FileIO(){

}

template <class T>
string FileIO<T>::ReadFile(string file){
  ifstream infs;
  string line = "";
  int lineCount = 0;



  infs.open(file);
  if(!infs.is_open()){
    count << "Could not open file." << endl;
  }

  while(!infs.eof()){
    if(!infs.fail()){
      while(getline(infs, line)){
        for(int i = 0; i < line.size(); ++i){
          
        }
      }
    }





  }

}
