#include "GenStack.h"
#include <iostream>

using namespace std;

template <class T>
class Delimeter{
  public:
    Delimeter();//constructor
    ~Delimeter();//destructor

    char Checker(GenStack<T> stack, string line, int* delimPosition, int delimCount);

  private:
    bool m_check; //check for errors
    char m_current;//current char looking at;
    int m_posError;//position of error
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

template <class T>
char Delimeter<T>::Checker(GenStack<T> stack, string line, int* delimPosition, int delimCount){

  for(int i = 0; i < delimCount; ++i){
    m_current = line[i];
    if(m_current == '(' || m_current == '{' || m_current == '['){
      stack->push(m_current);
    }

    if(m_current == ')' || m_current == '}' || m_current == ']'){
      m_topElement = stack->pop();
      if(m_topElement == '('){
        m_expectedChar = ')';
      }else if(m_topElement == '{'){
        m_expectedChar = '}';
      }else{
        m_expectedChar = ']';
      }
    }

    if(m_expectedChar != m_current){
      m_posError = delimPosition[i];
      cout << "Line: " << m_posError << " expected " << m_expectedChar << " and found " << m_current << endl;
      m_check = true;
    }
  }

  if(!m_check){
    cout << "Delimiters look good." << endl;
    cout << "Would you ike to check another file? (y/n): ";
    cin >> m_again;
  }
}
