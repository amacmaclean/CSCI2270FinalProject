//
//  ChainingBST.hpp
//  

#include<math.h>
#include<stdio.h>
#include<ctime>
#include <iostream>

struct BSTnode {
	int num;
	int count;
	BSTnode* left;
	BSTnode* right;
};

class HashTable {
private:
	int TABLE_SIZE;
	BSTnode* root; //pointer to root of BST
	int performHash1(int key);
	int performHash2(int key);
	BSTnode* searchTable(int key); //returns BST node if found
	BSTnode* table[]; //double pointer
public:
	HashTable(int size);
	void hash(int key);
	bool inTable(int key); //return whether it is in table
	void deleteNode(int key);
};


