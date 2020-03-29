#include <iostream>

using namespace std;

class GenStack{
  public:
    GenStack();
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); // destructor

    //core functions
    void push(char data); // insert an item
    char pop(); //remove

    //aux/helper functions
    char peek(); // aka top
    bool isEmpty();
    bool isFull();

    int top;
    int mSize;

    char *myArray; //memory address of the fisrt block

};
