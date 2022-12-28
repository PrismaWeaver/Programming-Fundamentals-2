/*********************
Name: Twee Shackelford
Coding 06
Purpose: create Hash table
**********************/

#include "hashtable.h"

Hashtable::Hashtable() {
	count = 0;
	for (int i = 0; i < HASH_SIZE; i++) {
		constructHelp(i);
	}
}

Hashtable::~Hashtable() {
	for (int i = 0; i < HASH_SIZE; i++) {
		if (hashtable[i]) {
			delete hashtable[i];
		}
	}
}

void Hashtable::constructHelp(int i) {
	LinkedList* newlist = new LinkedList;
	hashtable[i] = newlist;
}

bool Hashtable::insertEntry(int id, string data) {
	bool success = false;
	int position = hash(id); 
	success = hashtable[position]->addNode(id, data);	//passes data to linked list via addNode()
	if (success) count++;	
	return success;
}

string Hashtable::getData(int id) {
	bool success = false;
	string data = ""; //will be filled with data if found via search
	int position = hash(id);
	Data tmpData;
	success = hashtable[position]->getNode(id, &tmpData);
	if (success) data = tmpData.data;
	return data;
}

bool Hashtable::removeEntry(int id) {
	bool success = false;
	int position = hash(id);
	success = hashtable[position]->deleteNode(id);
	if (success) count--;
	return success;
}

int Hashtable::getCount() {
	return count;
}

void Hashtable::printTable() {
	for (int i = 0; i < HASH_SIZE; i++) {
		cout << "Entry " << i << ": " << std::flush;
		hashtable[i]->printList();
	}
	cout << endl;
}

int Hashtable::hash(int id) {
	int hash = 0;
	if (id > 0) hash = id % HASH_SIZE; //returns a value between 0 and the SIZE of the hash table
	return hash;
}