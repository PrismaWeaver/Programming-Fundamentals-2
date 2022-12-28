/*********************
Name: Twee Shackelford
Test 1
Purpose: create Hash table with array of heads
**********************/

#include "hash.h"

Hashtable::Hashtable() {
	hashCount = 0;
	for (int i = 0; i < HASH_SIZE; i++) {
		hashtable[i] = NULL;
	}
}

Hashtable::~Hashtable() {
	for (int i = 0; i < HASH_SIZE; i++) {
		if (hashtable[i]) {
			delete hashtable[i];
		}
	}
}

bool Hashtable::addEntry(int id, string data) {
	bool success = false, exists = false;
	if (id > 0 && !data.empty()) {
		int position = hash(id);
		Node* newNode = new Node; //dynamically allocate a new Node, put id and data in node
		newNode->data.id = id;
		newNode->data.data = data;
		newNode->next = NULL;
		if (hashtable[position] == NULL) { //skips case variance if head is empty
			hashtable[position] = newNode;				//head = new
			success = true;
		}
		else {
			Node* currentNode = hashtable[position]; //begin at the head
			while (currentNode) {
				if (currentNode->data.id == id) {
					exists = true;
					break;
				}
				else if (currentNode->next != NULL) currentNode = currentNode->next;
				else break;
			}
			if (!exists) {
				currentNode->next = newNode;
				success = true;
			}
		}
	}
	if (success) hashCount++;
	return success;
}

string Hashtable::getEntry(int id) {
	string data = ""; //will be filled with data if found via search
	if (id > 0) {
		int position = hash(id);
		Node* currentNode = hashtable[position]; //begin at the head
		while (currentNode) {
			if (currentNode->data.id == id) {
				data = currentNode->data.data;
				break;
			}
			else if (currentNode->next != NULL) currentNode = currentNode->next;
			else break;
		}
	}
	return data;
}

bool Hashtable::removeEntry(int id) {
	bool success = false;
	if (id > 0) {
		int position = hash(id);
		Node* currentNode = hashtable[position], *prevNode = currentNode; //begin at the head
		if (hashtable[position] != NULL) {
			if (hashtable[position]->data.id == id) {
				if (currentNode->next != NULL) { //catches if there is only a head
					hashtable[position] = currentNode->next;
				}
				else hashtable[position] = NULL;
				delete currentNode; //deallocate the current node
				success = true;	
			}
			else {
				while (currentNode) {
					if (currentNode->data.id == id) {
						if (currentNode->next != NULL) {
							prevNode->next = currentNode->next;
						}
						else prevNode->next = NULL;
						delete currentNode; //deallocate the current node
						success = true;	
						break;
					}
					prevNode = currentNode;
					currentNode = currentNode->next;
				}
			}
		}
	}
	if (success) hashCount--;
	return success;
}

int Hashtable::count() {
	return hashCount;
}

void Hashtable::displayTable() {
	Node* currentNode;
	for (int i = 0; i < HASH_SIZE; i++) {
		currentNode = hashtable[i];
		cout << "Entry " << i << ": " << flush;
		if (hashtable[i] != NULL) { //skips if head is empty
			while (currentNode) {
				cout << currentNode->data.id << flush;
				if (currentNode->next != NULL) cout << "->" << flush;
				else cout << endl;
				currentNode = currentNode->next;
			}
		}
		else std::cout << "EMPTY" << std::endl;
	}
}

int Hashtable::hash(int id) { 
	return id % HASH_SIZE; //returns a value between 0 and the SIZE of the hash table
}
