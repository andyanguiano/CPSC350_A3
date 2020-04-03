#include "Delimeter.h"
#include <fstream>

template <class T>
class FileIO{
  public:
    FileIO();
    ~FileIO();

    string ReadFile(string file);
    char getAgainCheck();
    int* allocateMemory(int* curr, int size);

  private:
    int m_delimCount;
    char m_againCheck;
};

template <class T>
FileIO<T>::FileIO(){
  m_delimCount = 0;
  m_againCheck = '\0';
}

template <class T>
FileIO<T>::~FileIO(){

}

template <class T>
string FileIO<T>::ReadFile(string file){
  ifstream infs;
  string line = "";
  int lineCount = 0;
  string delimStr = "";
  int delimError = 0;

  infs.open(file);
  if(!infs.is_open()){
    cout << "Could not open file." << endl;
  }

  GenStack<T> *stack = new GenStack<T>();
  int stackSize = stack->getSize();
  int *delimPosition = new int[stackSize];

  while(!infs.eof()){
    if(!infs.fail()){
      while(getline(infs, line)){
        for(int i = 0; i < line.size(); ++i){

          if(m_delimCount == stackSize - 1){
            delimPosition = allocateMemory(delimPosition, m_delimCount);
            stack = stack->allocateMemory();
            stackSize = stack->getSize();
          }
          if(line.at(i) == '('){
            delimStr.push_back('(');
            m_delimCount += 1;
          }else if(line.at(i) == ')'){
              delimStr.push_back(')');
              m_delimCount += 1;
          }else if(line.at(i) == '{'){
              delimStr.push_back('{');
              m_delimCount += 1;
          }else if(line.at(i) == '}'){
              delimStr.push_back('}');
              m_delimCount += 1;
          }else if(line.at(i) == '['){
              delimStr.push_back(']');
              m_delimCount += 1;
          }
        }
      }
    }
    infs.close();
  }

  infs.open(file);
  while(!infs.eof()){
    if(!infs.fail()){
      while(getline(infs, line)){
        lineCount += 1;
        for(int i = 0; i < line.size(); ++i){
          if(line.at(i) = '('){
            delimPosition[delimError] = lineCount;
            delimError += 1;
          }else if(line.at(i) = ')'){
            delimPosition[delimError] = lineCount;
            delimError += 1;
          }else if(line.at(i) = '{'){
            delimPosition[delimError] = lineCount;
            delimError += 1;
          }else if(line.at(i) = '}'){
            delimPosition[delimError] = lineCount;
            delimError += 1;
          }else if(line.at(i) = '['){
            delimPosition[delimError] = lineCount;
            delimError += 1;
          }else if(line.at(i) = ']'){
            delimPosition[delimError] = lineCount;
            delimError += 1;
          }
        }
      }
    }
    infs.close();
  }

  Delimeter<T> *delimeter = new Delimeter<T>();
  m_againCheck = delimeter->Checker(stack, delimStr, delimPosition, m_delimCount);
  return delimStr;
}

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
