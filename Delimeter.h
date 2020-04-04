//Andy Anguiano
//2316199
//aanguiano@champman.edu
//CPSC 350-02
//Assignemnt 3

#include "GenStack.h"
#include <iostream>

using namespace std;

template <class T>
class Delimeter{
  public:
    Delimeter();//constructor
    ~Delimeter();//destructor

    char Checker(GenStack<T>* stack, string line, int* delimPosition, int delimCount);

  private:
    bool m_check; //check for errors
    char m_current;//current char looking at
    int m_posError;//position of the error
    char m_topElement;//top element of stack
    char m_expectedChar;//expected char when error checking
    char m_again; //check if user wants to run again
};

//default constructor
template <class T>
Delimeter<T>::Delimeter(){
  m_check = false;
  m_current = '\0';
  m_posError = 0;
  m_topElement = '\0';
  m_expectedChar = '\0';
  m_again = '\0';
}

template <class T>
Delimeter<T>::~Delimeter(){

}

//goes through each line and adds all delimeters to stack and removes and checks for error when it reads an end delimeter
//prints the error message
template <class T>
char Delimeter<T>::Checker(GenStack<T>* stack, string line, int* delimPosition, int delimCount){
  //loops through length of the delimeter string
  for(int i = 0; i < delimCount; ++i){
    //sets current value to character
    m_current = line[i];
    //if current is a delimeter than it pushes to stack
    if(m_current == '(' || m_current == '{' || m_current == '['){
      stack->push(m_current);
    }
    //if current is an ending delimeter than pops the char and checks to see if right one
    //prints error message
    if(m_current == ')' || m_current == '}' || m_current == ']'){
      m_topElement = stack->pop();
      if(m_topElement == '('){
        m_expectedChar = ')';
        if(m_expectedChar != m_current){
          m_posError = delimPosition[i];
          cout << "Line: " << m_posError << " expected " << m_expectedChar << " and found " << m_current << endl;
          m_check = true;
          break;
        }else{
          continue;
        }
      }else if(m_topElement == '{'){
        m_expectedChar = '}';
        if(m_expectedChar != m_current){
          m_posError = delimPosition[i];
          cout << "Line: " << m_posError << " expected " << m_expectedChar << " and found " << m_current << endl;
          m_check = true;
          break;
        }else{
          continue;
        }
      }else if(m_topElement == '['){
        m_expectedChar = ']';
        if(m_expectedChar != m_current){
          m_posError = delimPosition[i];
          cout << "Line: " << m_posError << " expected " << m_expectedChar << " and found " << m_current << endl;
          m_check = true;
          break;
        }else{
          continue;
        }
      }
    }
  }
  //if the stack is not empty than says error
  if(!(stack->isEmpty())){
    m_topElement = stack->pop();
    if(m_topElement = '('){
      cout << "Reached end of file and expected: )" << endl;
    }else if(m_topElement = '{'){
      cout << "Reached end of file and expected: }" << endl;
    }else if(m_topElement = '['){
      cout << "Reached end of file and expected: ]" << endl;
    }
    m_check = true;
  }
  //only goes through this is there were no errors
  if(!m_check){
    cout << "Delimiters look good." << endl;
    cout << "Would you ike to check another file? (y/n):";
    cin >> m_again;
  }
  return m_again;
}
