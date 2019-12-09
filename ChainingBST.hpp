//
//  ChainingBST.hpp
//  

#include<math.h>
#include<stdio.h>
#include<ctime>
#include <iostream>

using namespace std;

struct BSTnode {
	int key;
	BSTnode* left = NULL;
	BSTnode* right = NULL;
};

class HashTable {
private:
	int TABLE_SIZE = 10009;
	int performHash(int key, bool func1);
	BSTnode** table; //double pointer because array
	BSTnode* insertIntoBST(BSTnode* currNode, int key);
	BSTnode* lookupNode(BSTnode* currNode, int key);
	BSTnode* deleteNode(BSTnode* currNode, int key);
	BSTnode* getMinBSTNode(BSTnode* currNode);
public:
	HashTable(int size);
	void hash(int key, bool func1); //insert BST function
	void deleteKey(int key, bool func1);
	bool inTable(int key, bool func1); //Lookup
};


