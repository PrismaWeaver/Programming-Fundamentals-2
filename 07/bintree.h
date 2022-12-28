/*********************
Name: Twee Shackelford
Coding 07
Purpose: create Binary Search Tree
**********************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <iostream>     /* cout, endl */
#include <string>       /* string */
#include <algorithm>	/* max */
#include "data.h"

using std::max;
using std::cout;
using std::endl;
using std::string;

class BinTree {

public:
	BinTree(); //constructor
	~BinTree(); //destructor

	bool empty(); //test for empty
	int getCount(); //return count
	bool getRootData(Data*); //fills empty Data struct with root data, or -1 "" if empty
	void displayTree(); //display stats for tree

	//have overloads
	void clear(); //deallocate the tree and set back to empty
	bool addNode(int, string); //adds Node in tree order
	bool removeNode(int); //removes Node (follows tree order to find)
	bool getNode(Data*, int); //binary search, fills empty Data struct with data
	bool contains(int); //returns if id is present
	int getHeight(); //calculate height of tree
	void displayPreOrder(); //print pre-order traversal
	void displayPostOrder(); //print post-order traversal
	void displayInOrder(); //print in-order traversal

private:
	//thing for removeNode
	DataNode* minValueNode(DataNode*);

	//overload for recursion
	void clear(DataNode*);
	bool addNode(DataNode*, DataNode**);
	DataNode* removeNode(int, DataNode*);
	bool getNode(Data*, int, DataNode*);
	bool contains(int, DataNode*);
	int getHeight(DataNode*);
	void displayPreOrder(DataNode*);
	void displayPostOrder(DataNode*);
	void displayInOrder(DataNode*);
	
	//variables
	DataNode* root; //vertex
	int count; //number of nodes

};

#endif /* BINTREE_BINTREE_H */

