/*********************
Name: Twee Shackelford
Coding 03
Purpose: create and test a simple stack using pointers
**********************/

#ifndef STACK_H
#define STACK_H

#include "data.h"
#define STACK_SIZE 10 // do not modify this define

class Stack {

public:

    //constructor
    Stack();

    //destructor
    ~Stack();

    //functions
    bool push(int, string);
    bool pop(Data*);
    bool peek(Data*);
    bool isEmpty();
    
private:

    // these are the only attributes you need. do not modify them or add any
    int top; // this is your top index
    Data *stack[STACK_SIZE]; // this is your stack, it is an array of Data pointers
};

#endif //STACK_H