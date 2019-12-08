//
//  ChainingBST.cpp
//  

#include "ChainingBST.hpp"
#include<math.h>
#include<stdio.h>
#include<ctime>
#include <iostream>


using namespace std;

HashTable::HashTable(int size) {
	TABLE_SIZE = size;
	table = new BSTnode*[TABLE_SIZE]; // root BSTnode* array hash table, 
	for (int i = 0; i < TABLE_SIZE; i++) //set all elements to -1
		table[i] = NULL;
}


int HashTable::performHash1(int key) {
	return key % TABLE_SIZE;
}

int HashTable::performHash2(int key) {
    int floorVal = floor(key/TABLE_SIZE);
    return (floorVal%TABLE_SIZE);
}

//Hash Function 1 (can change to 2)
void HashTable::hash(int key) {
	int index = performHash1(key);
	
	table[index] = insertIntoBST(table[index], key); //table[index] = root	
}

//Recursive function
BSTnode* HashTable::insertIntoBST(BSTnode* currNode, int key) {
	if (currNode == NULL) {
		BSTnode* newNode = new BSTnode;
		newNode->key = key;
		return newNode;
	}
	else if (key < currNode->key) { //if lower than current, go left
		currNode->left = insertIntoBST(currNode->left, key);
	}
	else if (key > currNode->key) { //if greater than current, go right
		currNode->right = insertIntoBST(currNode->right, key);
	}
	else { //if key == currNode->key
		cout << "Duplicate Value -- Please insert different number" << endl;
		return NULL;
	}
}

//Lookup function
bool inTable(int key) {

}



void HashTable::deleteNode(int key) {

}



int main() {
	return 0;
}
