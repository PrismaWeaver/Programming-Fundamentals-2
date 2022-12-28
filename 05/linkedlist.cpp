/*********************
Name: Twee Shackelford
Coding 05
Purpose: create linked list
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
		if (head == NULL) { //skips case variance if head is empty
			success = addHead(id, data);
		}
		else {
			caseNum = caseAdd(id);
			switch (caseNum) {
				case 1:
					success = addHead(id, data);
					break;
				case 2:
					success = addMid(id, data);
					break;
				case 3:
					success = addTail(id, data);
					break;
				default: //this should only happen if the id being added already exists
					break;
			}
		}
	}
	return success;
}

int LinkedList::caseAdd(int id) {
	Node* currentNode = head; //begin at the head
	int caseNum = 3;
	if (head->data.id > id) {
		caseNum = 1; //if first comparison is lesser, stop
	}
	else {
		while (currentNode) {
			if (currentNode->data.id > id) { //compare the id to the current node, if the id is lesser, stop
				caseNum = 2;
				break;
			}
			currentNode = currentNode->next;
		}
	}
	return caseNum;
}

bool LinkedList::addHead(int id, string data) {
	Node* currentNode = head; //begin at the head
	Node* newNode = new Node; //dynamically allocate new Node, put id and data in node
	newNode->data.id = id;
	newNode->data.data = data;
	if (head == NULL) { //prevents error with empty head
		newNode->next = NULL;
		newNode->prev = NULL;		//new->prev = NULL
		head = newNode;				//head = new
	}
	else {
		currentNode->prev = newNode;		//head->prev = new
		newNode->next = currentNode;		//new->next = head
		newNode->prev = NULL;		//new->prev = NULL
		head = newNode;				//head = new
	}
	return true;
}



bool LinkedList::addMid(int id, string data) {
	Node* currentNode = head; //begin at the head
	bool success = false;
	while (currentNode) {
		if (currentNode->data.id > id) {
			success = true;
			break;
		}
		currentNode = currentNode->next;
	}
	if (success) {
		Node* newNode = new Node;		//dynamically allocate a new Node and put the id and data in the Node
		newNode->data.id = id;
		newNode->data.data = data;
		newNode->next = currentNode;		//new->next = current
		newNode->prev = currentNode->prev;	//new->prev = current->prev
		currentNode->prev->next = newNode;	//current->prev->next=new
		currentNode->prev = newNode;		//current->prev = new
	}
	return success;
}

bool LinkedList::addTail(int id, string data) {
	Node* currentNode = head; //begin at the head
	bool success = false;
	while (currentNode) {
		if (currentNode->next != NULL) currentNode = currentNode->next;
		else break;
	}
	if (currentNode->next == NULL) {
		Node* newNode = new Node; //dynamically allocate a new Node, put id and data in node
		newNode->data.id = id;
		newNode->data.data = data;
		newNode->next = NULL;		//new->next = NULL
		newNode->prev = currentNode;//new->prev = current
		currentNode->next = newNode;//current->next = new
		success = true;
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

void LinkedList::printList(bool direction) { //only included for accademic reasons, prints forward (default), or backwards
	if (head != NULL) { //skips if head is empty
		std::cout << "\nprinting" << std::endl;
		Node* currentNode = head; //begin at the head
		if (!direction) {
			while (currentNode) { //if the list is not empty, print the head id and data
				std::cout << "id: " << currentNode->data.id << "\ndata: " << currentNode->data.data << std::endl;
				if (currentNode->next != NULL) currentNode = currentNode->next;
				else break;
			}
		}
		else { //for backwards printing, probably a better way to do this
			while (currentNode) {
				if (currentNode->next != NULL) currentNode = currentNode->next;
				else break;
			}
			while (currentNode) {
				std::cout << "id: " << currentNode->data.id << "\ndata: " << currentNode->data.data << std::endl;
				if (currentNode->prev != NULL) currentNode = currentNode->prev;
				else break;
			}
		}
	}
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
	if (head != NULL) { //skips if head is empty
		while (getCount() > 0) deleteHead();
	}
}

bool LinkedList::exists(int id) { //tests for the existence of a node based on a given id
	bool success = false;
	if (head != NULL) {
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