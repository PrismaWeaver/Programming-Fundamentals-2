/*********************
Name: Twee Shackelford
Test 1
Purpose: create Hash table with array of heads
**********************/

#ifndef HASH_H
#define HASH_H

#include <iostream>     /* cout, endl */
#include <string>       /* string */

#define HASH_SIZE 15

using std::cout;
using std::endl;
using std::flush;
using std::string;

struct Data {
	int id;
	string data;
};

struct Node {
	Data data;
	Node* next;
};

class Hashtable {

public:
	Hashtable();
	~Hashtable();

	bool addEntry(int, string);
	string getEntry(int);
	bool removeEntry(int);
	int count();
	void displayTable();

private:
	int hash(int); // return id % SIZE


	//variables
	Node* hashtable[HASH_SIZE];
	int hashCount;
};

#endif /* HASH_H */
