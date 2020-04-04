//Andy Anguiano
//2316199
//aanguiano@champman.edu
//CPSC 350-02
//Assignemnt 3

#include "Delimeter.h"
#include <fstream>

template <class T>
class FileIO{
  public:
    FileIO();//default constructor
    ~FileIO();//destructor

    string ReadFile(string file);//reads the file
    char getAgainCheck();//returns if the user wants to go again
    int* allocateMemory(int* curr, int size);//allocates memory if stack is full

  private:
    int m_delimCount;
    char m_againCheck;
};
//default constructor
template <class T>
FileIO<T>::FileIO(){
  m_delimCount = 0;
  m_againCheck = '\0';
}
//destructor
template <class T>
FileIO<T>::~FileIO(){

}
//opens file, creats stack, creates string with all delimeters
template <class T>
string FileIO<T>::ReadFile(string file){
  ifstream infs;
  string line = "";
  int lineCount = 0;
  string delimStr = "";
  int delimError = 0;
  //error checks open file
  infs.open(file);
  if(!infs.is_open()){
    cout << "Could not open file." << endl;
  }
  //creates stack
  GenStack<T> *stack = new GenStack<T>();
  int stackSize = stack->getSize();
  int *delimPosition = new int[stackSize];
  //adds all delimeters to string
  while(!infs.eof()){
    if(!infs.fail()){
      while(getline(infs, line)){
        lineCount += 1;
        for(int i = 0; i < line.size(); ++i){

          if(m_delimCount == stackSize - 1){
            delimPosition = allocateMemory(delimPosition, m_delimCount);
            stack = stack->allocateMemory();
            stackSize = stack->getSize();
          }

          if(line.at(i) == '('){
            delimStr.push_back('(');
            m_delimCount += 1;
            delimPosition[delimError] = lineCount;
            delimError += 1;
          }else if(line.at(i) == ')'){
              delimStr.push_back(')');
              m_delimCount += 1;
              delimPosition[delimError] = lineCount;
              delimError += 1;
          }else if(line.at(i) == '{'){
              delimStr.push_back('{');
              m_delimCount += 1;
              delimPosition[delimError] = lineCount;
              delimError += 1;
          }else if(line.at(i) == '}'){
              delimStr.push_back('}');
              m_delimCount += 1;
              delimPosition[delimError] = lineCount;
              delimError += 1;
          }else if(line.at(i) == '['){
              delimStr.push_back('[');
              m_delimCount += 1;
              delimPosition[delimError] = lineCount;
              delimError += 1;
          }else if(line.at(i) == ']'){
              delimStr.push_back(']');
              m_delimCount += 1;
              delimPosition[delimError] = lineCount;
              delimError += 1;
          }
        }
      }
    }
    infs.close();
    //creates delimeter and runs cehcker function
    Delimeter<T> *delimeter = new Delimeter<T>();
    m_againCheck = delimeter->Checker(stack, delimStr, delimPosition, m_delimCount);
    return delimStr;
    break;
  }
}
//alllocates new memory is stack is full
template <class T>
int* FileIO<T>::allocateMemory(int* curr, int size){
  int newSize = size * 2;
  int* array = new int[newSize];
  for(int i = 0; i < size; ++i){
    array[i] = curr[i];
  }
  return array;
}

template <class T>
char FileIO<T>::getAgainCheck(){
  return m_againCheck;
}
