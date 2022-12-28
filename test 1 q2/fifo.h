/*********************
Name: Twee Shackelford
Test 1
Purpose: create FIFO stack
**********************/

#ifndef FIFO_H
#define FIFO_H

#define STACKSIZE 10

class Stack {

public:

    Stack();  // constructor
    ~Stack();  // destructor

    int pull();
    int peek();
    bool push(int);
    bool isEmpty();

private:

    int top;  //do not initialize here, that's what the constructor is for
    int stack[STACKSIZE];

};


#endif //FIFO_H