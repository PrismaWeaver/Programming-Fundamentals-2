/*********************
Name: Twee Shackelford
Coding 06
Purpose: create Hash table
**********************/

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>     /* cout, endl */
#include <string>       /* string */
#include "linkedlist.h"

#define HASH_SIZE 15

using std::cout;
using std::endl;
using std::string;

class Hashtable {

public:
	Hashtable();
	~Hashtable();

	bool insertEntry(int, string);
	string getData(int);
	bool removeEntry(int);
	int getCount();
	void printTable();

private:
	int hash(int); // return id % SIZE
	void constructHelp(int);


	//variables
	LinkedList* hashtable[HASH_SIZE];
	int count;
};

#endif /* HASH_TABLE_H */