#include "GenStack.h"
#include <iostream>

using namespace std;
//default constructor
GenStack::GenStack(){
  myArray = new char[128];
  mSize = 128;
  top = -1;
}
//overloaded constructor
GenStack::GenStack(int maxSize){
  myArray = new char[maxSize];
  mSize = maxSize;
  top = -1;
}
//destructor
GenStack::~GenStack(){
  delete myArray;
}
//changes top
void GenStack::push(char data){
  // check is full before attempting to push/insert
  myArray[++top] = data;
}

char GenStack::pop(){
  // check is full before attempting to push/insert
  if(isEmpty()){
    cout << "Stack is already empty";
    return '\0';
  }else{
  return myArray[top--];
  }
}

char GenStack::peek(){
  return myArray[top];
}

bool GenStack::isFull(){
  return (top == mSize - 1);
}

bool GenStack::isEmpty(){
  return (top == -1);
}
