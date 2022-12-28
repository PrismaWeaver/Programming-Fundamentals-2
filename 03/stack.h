/*********************
Name: Jade Shackelford
Coding 03
Purpose: create and test a simple stack
**********************/

#ifndef STACK_STACK_H
#define STACK_STACK_H

#define STACK_SIZE 10

class Stack {
	
	public:
		//contstructor
		Stack();
		
		//functions
		bool push(int);
  		int pop();
 		bool isEmpty();
 		int peek();
 		
protected: 
		//private variables
		int top;
		int size[STACK_SIZE];
};


#endif //STACK_STACK_H
