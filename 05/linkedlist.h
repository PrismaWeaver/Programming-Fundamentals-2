/*********************
Name: Twee Shackelford
Coding 05
Purpose: create linked list
**********************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"

#include <iostream>

class LinkedList {

public:
	LinkedList();
	~LinkedList();

	bool addNode(int, string);
	bool deleteNode(int);
	bool getNode(int, Data*);
	void printList(bool = false); //only included for accademic reasons
	int getCount();
	void clearList();
	bool exists(int);

private:
	Node *head;

	int caseAdd(int);
	bool addHead(int, string);
	bool addMid(int, string);
	bool addTail(int, string);

	int caseDelete(int);
	bool deleteHead();
	bool deleteMid(int);
	bool deleteTail(int);
};

#endif /* LINKEDLIST_H */
