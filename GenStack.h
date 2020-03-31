#include <iostream>

using namespace std;

template <class T>

class GenStack{
  public:
    GenStack();//default constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); // destructor

    //core functions
    void push(T data); // insert an item
    T pop(); //remove

    //aux/helper functions
    T peek(); // aka top
    bool isEmpty();
    bool isFull();

    int top;
    int mSize;

    T *myArray; //memory address of the fisrt block

};


//default constructor
template <class T>
GenStack<T>::GenStack(){
  myArray = new T[128];
  mSize = 128;
  top = -1;
}

//overloaded constructor
template <class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  mSize = maxSize;
  top = -1;
}
//destructor
template <class T>
GenStack<T>::~GenStack(){
  delete myArray;
}
//changes top
template <class T>
void GenStack<T>::push(T data){
  // check is full before attempting to push/insert
  myArray[++top] = data;
}

template <class T>
T GenStack<T>::pop(){
  //check is full empty attempting to remove
  if(isEmpty()){
    cout << "Stack is already empty";
    return '\0';
  }else{
  return myArray[top--];
  }
}

template <class T>
T GenStack<T>::peek(){
  return myArray[top];
}
template <class T>
bool GenStack<T>::isFull(){
  return (top == mSize - 1);
}
template <class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}
