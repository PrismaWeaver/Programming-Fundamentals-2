/*********************
Name: Twee Shackelford
Coding 06
Purpose: create Hash table
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
	void printList(); //only included for accademic reasons
	int getCount();
	void clearList();
	bool exists(int);

private:
	Node *head;

	int caseDelete(int);
	bool deleteHead();
	bool deleteMid(int);
	bool deleteTail(int);
};

#endif /* LINKEDLIST_H */
