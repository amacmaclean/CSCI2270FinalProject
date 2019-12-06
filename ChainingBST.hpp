//
//  ChainingBST.hpp
//  

#include<math.h>
#include<stdio.h>
#include<ctime>
#include <iostream>

struct BSTnode {
	int key;
	int count = 0;
	BSTnode* left = NULL;
	BSTnode* right = NULL;
};

class HashTable {
private:
	int TABLE_SIZE;
	int performHash1(int key);
	int performHash2(int key);
	BSTnode* table[]; //double pointer
	BSTnode* insertIntoBST(BSTnode* currNode, int index);
public:
	HashTable(int size);
	BSTnode
	void hash(int key); //insert BST function
	void deleteNode(int key);
};


