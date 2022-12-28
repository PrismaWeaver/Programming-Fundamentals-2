/*********************
Name: Twee Shackelford
Coding 03
Purpose: create and test a simple stack using pointers
**********************/

// each cpp includes ONLY it's header directly!
#include "stack.h"

Stack::Stack() {
	this->top = -1;
}

Stack::~Stack() {
	//deallocate pointer array
	for (int i = top; i < 0; i--) {
		delete stack[i];
	}
}

bool Stack::push(int ident, string info) {
	bool success = false;
	//test if stack not full, id possitive, and string not empty
	if (top < STACK_SIZE - 1 && ident > 0 && !info.empty()) {
		//dynamically allocate Data struct
		Data* ptr = new Data;
		//fill struct
		ptr->id = ident;
		ptr->information = info;
		//increment stack and push pointer to stack
		stack[++top] = ptr;
		success = true;
	}
	return success;
}


bool Stack::pop(Data *point) {
	bool success = false;
	if (!isEmpty()) {
		//fill point with data from stack
		point->id = stack[top]->id;
		point->information = stack[top]->information;
		//deallocate pointer and decrement top
		delete stack[top--];
		success = true;
	}
	//fills passed struct with bunk data
	else {
		point->id = -1;
		point->information = "";
		success = false;
	}
	return success;
}

bool Stack::peek(Data *point) {
	bool success = false;
	if (!isEmpty()) {
		//fill point with data from stack
		point = stack[top];
		success = true;
	}
	//fills passed struct with bunk data
	else {
		point->id = -1;
		point->information = "";
		success = false;
	}
	return success;
}

bool Stack::isEmpty() {
	return (top < 0);
}