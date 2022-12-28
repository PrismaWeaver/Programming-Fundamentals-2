/*********************
Name: Twee Shackelford
Test 1
Purpose: create FIFO stack
**********************/

#include "fifo.h"

Stack::Stack() {
    top = -1;
}

Stack::~Stack() {
    //there is nothing to do to clean up this object, so this is blank
}

bool Stack::push(int i) {
    bool pushed = false;

    if (top < STACKSIZE - 1) {
        stack[++top] = i;
        pushed = true;
    }

    return pushed;
}

int Stack::pull() {

    if (top < 0) {
        //throw an int because we cannot return one
        throw -1;
    }
    int out = stack[0];
    for (int i = 0; i < top; i++) {
        stack[i] = stack[i + 1];
    }
    top--;
    return out;
}

int Stack::peek() {

    if (top < 0) {
        //throw an int because we cannot return one
        throw -1;
    }
    return stack[0];
}

bool Stack::isEmpty() {
    return (top < 0);
}