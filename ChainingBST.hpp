//
//  ChainingBST.hpp
//  

#include<math.h>
#include<stdio.h>
#include<ctime>
#include <iostream>

struct BSTnode {
	int key;
	BSTnode* left = NULL;
	BSTnode* right = NULL;
};

class HashTable {
private:
	int TABLE_SIZE;
	int performHash1(int key);
	int performHash2(int key);
	BSTnode** table; //double pointer because array
	BSTnode* insertIntoBST(BSTnode* currNode, int key);
public:
	HashTable(int size);
	void hash(int key); //insert BST function
	void deleteNode(int key);
	bool inTable(int key); //Lookup
};


