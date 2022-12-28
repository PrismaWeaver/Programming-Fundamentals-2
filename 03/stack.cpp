/*********************
Name: Jade Shackelford
Coding 03
Purpose: create and test a simple stack
**********************/

#include "stack.h"

/*altered class config to incorperate header file

this constructor makes it so when attempting to push
the first incrimented value is 0*/
Stack::Stack() {
	top = -1;
}

/*changed >= 10 to >= 9 as 9 would be the last value the stack could take
added bool return

push should check if the stack is full or not
if not then increase the top value and add the new element*/
bool Stack::push(int in) {
	bool success;
	if (top >= (STACK_SIZE-1)) {
		success = false;
	}
	else {
		size[++top] = in;
		success = true;
	}
	return success;
}



/*fixed dual return here by returning variable
throws error that main try/catches

pop should check if stack is empty or not
if its not then decrement top*/
int Stack::pop() {
	int out;
	if (isEmpty()) {
		throw - 2;
	}
	else {
		out = size[top--];
	}
	return out;
}

//simplified and changed to return bool
bool Stack::isEmpty() {
	return (top < 0);
}

//added peak() function
//essentially a double of pop
int Stack::peek() {
	int show;
	if (isEmpty()) {
		throw - 2;
	}
	else {
		show = size[top];
	}
	return show;
}
