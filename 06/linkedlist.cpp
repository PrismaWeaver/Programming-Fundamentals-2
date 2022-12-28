/*********************
Name: Twee Shackelford
Coding 06
Purpose: create Hash table
**********************/

#include "linkedlist.h"

LinkedList::LinkedList() {
	head = NULL;
}

LinkedList::~LinkedList() {
	clearList();
}

bool LinkedList::addNode(int id, string data) { //accepts id and data and inserts to the list in order
	bool success = false;
	if (id > 0 && !data.empty() && !exists(id)) {
		int caseNum = 0;
		Node* newNode = new Node; //dynamically allocate a new Node, put id and data in node
		newNode->data.id = id;
		newNode->data.data = data;
		newNode->next = NULL;
		if (head == NULL) { //skips case variance if head is empty
			newNode->prev = NULL;		//new->prev = NULL
			head = newNode;				//head = new
			success = true;
		}
		else {
			Node* currentNode = head; //begin at the head
			while (currentNode) {
				if (currentNode->next != NULL) currentNode = currentNode->next;
				else break;
			}
			if (currentNode->next == NULL) {
				newNode->prev = currentNode;
				currentNode->next = newNode;
				success = true;
			}
		}
	}
	return success;
}

bool LinkedList::deleteNode(int id) { //accepts an id and deletes the node
	bool success = false;
	if (id > 0 && exists(id)) {
		int caseNum;
		caseNum = caseDelete(id);
		switch (caseNum) {
			case 1:
				success = deleteHead();
				break;
			case 2:
				success = deleteMid(id);
				break;
			case 3:
				success = deleteTail(id);
				break;
			default: //this should only happen if something breaks
				break;
		}
	}
	return success;
}

int LinkedList::caseDelete(int id) {
	int caseNum = 0;
	Node* currentNode = head; //begin at the head
	if (head->data.id == id) caseNum = 1; //if first comparison is equal, stop
	else {
		while (currentNode) {
			if (currentNode->data.id == id) { //compare the id to the current node, if the id is equal, stop
				if (currentNode->next != NULL) caseNum = 2;
				else caseNum = 3;
			}
			currentNode = currentNode->next;
		}
	}
	return caseNum;
}

bool LinkedList::deleteHead() {
	bool success = false;
	Node* currentNode = head; //begin at the head
	int id = currentNode->data.id;
	if (currentNode->next != NULL) { //catches if there is only a head
		currentNode->next->prev = NULL;	//head->next->prev = NULL
		head = currentNode->next;		//head = head->next
	}
	else head = NULL;
	delete currentNode;				//deallocate the current node
	if (!exists(id)) success = true;
	return success;
}

bool LinkedList::deleteMid(int id) {
	Node* currentNode = head; //begin at the head
	bool success = false;
	while (currentNode) {
		if (currentNode->data.id == id) {
			currentNode->prev->next = currentNode->next;//current->prev->next = current->next
			currentNode->next->prev = currentNode->prev;//current->next->prev = current->prev
			delete currentNode;							//deallocate the current node
			break;
		}
		currentNode = currentNode->next;
	}
	if (!exists(id)) success = true;
	return success;
}

bool LinkedList::deleteTail(int id) {
	Node* currentNode = head; //begin at the head
	bool success = false;
	while (currentNode) {
		if (currentNode->next != NULL) currentNode = currentNode->next;
		else break;
	}
	currentNode->prev->next = NULL;	//current->prev->next = NULL
	delete currentNode;				//deallocate the current node
	if (!exists(id)) success = true;
	return success;
}

bool LinkedList::getNode(int id, Data *ref) { //retrieves the data from a node from a given id
	bool success = false;
	if (exists(id)) {
		Node* currentNode = head; //begin at the head
		while (currentNode) {
			if (currentNode->data.id == id) { //compare id to current node, if search id == current id, stop
				ref->id = currentNode->data.id; //fill passed Node with id and data
				ref->data = currentNode->data.data;
				success = true;
				break;
			}
			currentNode = currentNode->next;
		}
	}
	return success;
}

void LinkedList::printList() { //only included for accademic reasons
	if (head != NULL) { //skips if head is empty
		Node* currentNode = head; //begin at the head
		while (currentNode) {
			std::cout << currentNode->data.id << std::flush;
			if (currentNode->next != NULL) std::cout << "->" << std::flush;
			else std::cout << std::endl;
			currentNode = currentNode->next;
		}
	}
	else std::cout << "EMPTY" << std::endl;
}

int LinkedList::getCount() { //reports the count
	int count = 0;
	if (head != NULL) { //skips if head is empty
		Node* currentNode = head; //begin at the head
		while (currentNode) {
			count++;
			if (currentNode->next != NULL) currentNode = currentNode->next;
			else break;
		}
	}
	return count;
}

void LinkedList::clearList() { //deallocates all nodes and sets head to Null
	while (head) deleteHead();
}

bool LinkedList::exists(int id) { //tests for the existence of a node based on a given id
	bool success = false;
	if (head != NULL && id > 0) {
		Node* currentNode = head; //begin at the head
		while (currentNode) {
			if (currentNode->data.id == id) { //compare the id to the current node, if the id is equal, stop
				success = true;
				break;
			}
			else if (currentNode->next != NULL) currentNode = currentNode->next;
			else break;
		}
	}
	return success;
} 