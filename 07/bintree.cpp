/*********************
Name: Twee Shackelford
Coding 07
Purpose: create Binary Search Tree
**********************/

#include "bintree.h"

/*
* Tree structure
* right subtree always greater than root
* left subtree always lesser than root
* tree can take on a number of suboptimal shapes if it doesn't reorganize itself
*/

BinTree::BinTree() {
	root = NULL;
	count = 0;
}

BinTree::~BinTree() {
	clear();
}

bool BinTree::empty() {
    return (root == NULL);
}

int BinTree::getCount() {
	return count;
}

bool BinTree::getRootData(Data* ref) {
    bool success = false;
    if (root) {
        ref->id = root->data.id;
        ref->information = root->data.information;
        success = true;
    }
    else {
        ref->id = -1;
        ref->information = "";
    }
    return success;
}

void BinTree::displayTree() {
    cout << "DISPLAY TREE" << endl;
    cout << "==============================================" << endl;
    if (empty()) cout << "Tree is empty" << endl;
    else cout << "Tree is NOT empty" << endl;
    cout << "Height " << getHeight() << endl;
    cout << "Node count: " << getCount() << endl;
    cout << "\nPre-Order Traversal" << endl;
    displayPreOrder();
    cout << "\nIn-Order Traversal" << endl;
    displayInOrder();
    cout << "\nPost-Order Traversal" << endl;
    displayPostOrder();
    cout << "==============================================\n" << endl;
    return;
}

void BinTree::clear() { //deallocate the tree and set back to empty
    clear(root);
    root = NULL;
    count = 0;
    return;
}

void BinTree::clear(DataNode* ref) {
    if (ref) {
        clear(ref->left);
        clear(ref->right);
        ref->left = NULL;
        ref->right = NULL;
        delete ref;
    }
    return;
}

bool BinTree::addNode(int id, string info) { //adds Node in tree order
    bool success = false;
    if (id > -1 && info != "") {
        DataNode* newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = info;
        newNode->left = NULL;
        newNode->right = NULL;
        success = addNode(newNode, &root);
    }
    if (success) count++;
    return success;
}

bool BinTree::addNode(DataNode* node, DataNode** ref) {
    bool success = false;
    if (!(*ref)) {
        *ref = node;
        success = true;
    }
    else {        
        if ((*ref)->data.id > node->data.id) {
            success = addNode(node, &(*ref)->left);            
        }
        else if ((*ref)->data.id < node->data.id) {
            success = addNode(node, &(*ref)->right);            
        }
    }
    return success;
}

bool BinTree::removeNode(int id) { //removes Node (follows tree order to find)
    bool success = false;
    int tempCount = count;
    root = removeNode(id, root);
    if (count < tempCount) success = true;
    return success;
}

DataNode* BinTree::removeNode(int id, DataNode* ref) {
    
    if (ref) {
        if (ref->data.id > id) {
            ref->left = removeNode(id, ref->left);
        }
        else if (ref->data.id < id) {
            ref->right = removeNode(id, ref->right);
        }
        else {
            DataNode* temp;
            if (ref->left == NULL) {
                temp = ref->right;
                delete ref;
                ref = temp;
                count--;
            }
            else if (root->right == NULL) {
                temp = ref->left;
                delete ref;
                ref = temp;
                count--;
            }
            else {
                temp = minValueNode(ref->right);
                ref->data.id = temp->data.id;
                ref->data.information = temp->data.information;
                ref->right = removeNode(temp->data.id, ref->right);
            }
        }
    }
    return ref;
}

bool BinTree::getNode(Data* temp, int id) { //binary search, fills empty Data struct with data
    bool success = false;
    if (id > -1) {
        success = getNode(temp, id, root);
    }
    return success;
}

bool BinTree::getNode(Data* temp, int id, DataNode* ref) {
    bool success = false;
    if (ref) {
        if (ref->data.id > id) {
            success = getNode(temp, id, ref->left);
        }
        else if (ref->data.id < id) {
            success = getNode(temp, id, ref->right);
        }
        else {
            temp->id = id;
            temp->information = ref->data.information;
            success = true;
        }
    }
    return success;
}

bool BinTree::contains(int id) { //returns if id is present
    bool success = false;
    if (id > -1) {
        success = contains(id, root);
    }
    return success;
}

bool BinTree::contains(int id, DataNode* ref) {
    bool success = false;
    if (ref) {
        if (ref->data.id > id) {
            success = contains(id, ref->left);
        }
        else if (ref->data.id < id) {
            success = contains(id, ref->right);
        }
        else {            
            success = true;
        }
    }
    return success;
}

int BinTree::getHeight() { //calculate height of tree
    return getHeight(root);
}

int BinTree::getHeight(DataNode* ref) {
    int lh = 0, rh = 0, h =0;
    if (ref) {
        lh = getHeight(ref->left);
        rh = getHeight(ref->right);
        h = max(lh, rh) + 1;
    }
    return h;
}

DataNode* BinTree::minValueNode(DataNode* ref) {
    DataNode* current = ref;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

void BinTree::displayPreOrder() { //print pre-order traversal
    displayPreOrder(root);
    return;
}

void BinTree::displayPreOrder(DataNode* ref) {
    if (ref) {
        cout << ref->data.id << " " << ref->data.information << endl;
        displayPreOrder(ref->left);
        displayPreOrder(ref->right);
    }
    return;
}

void BinTree::displayPostOrder() { //print post-order traversal
    displayPostOrder(root);
    return;
}

void BinTree::displayPostOrder(DataNode* ref) {
    if (ref) {
        displayPostOrder(ref->left);        
        displayPostOrder(ref->right);
        cout << ref->data.id << " " << ref->data.information << endl;
    }
}

void BinTree::displayInOrder() { //print in-order traversal
    displayInOrder(root);
    return;
}

void BinTree::displayInOrder(DataNode* ref) {
    if (ref) {
        displayInOrder(ref->left);
        cout << ref->data.id << " " << ref->data.information << endl;
        displayInOrder(ref->right);
    }
    return;
}