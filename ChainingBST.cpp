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
	root = NULL;
	TABLE_SIZE = size;
	table = new BSTnode*[TABLE_SIZE]; //int array hash table
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
void hash(int key) {
	int index = performHash1(key);
	if (table[index] >= 0) //if there is already a value in table[index]
		index = linearProbe(index);
	if (index >= 0) //if we find an empty index
		table[index] = key;
	else
		cout << "table Full" << endl;
}

BSTnode* searchTable(int key); //returns BST node if found

bool inTable(int key); //return whether it is in table
void deleteNode(int key);

//void HashTable::insertBST(int num){
    //int hashIndex = hashFunction(num);
    //BSTnode* element = table[hashIndex];




int main() {
	return 0;
}
