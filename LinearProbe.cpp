//
//  LinearProbe.cpp
//  


#include "LinearProbe.hpp"
#include <iostream>
#include <vector>
#include<math.h>


using namespace std;

//Constructor
HashTable::HashTable() {
	TABLE_SIZE = 100;
	table = new int[TABLE_SIZE]; //int array hash table
	for (int i = 0; i < TABLE_SIZE; i++) //set all elements to -1
		table[i] = -1;
}

int HashTable::performHash1(int key) {
	return key % TABLE_SIZE;
}

int HashTable::performHash2(int key) {
    int floorVal = floor(key/TABLE_SIZE);
    return (floorVal%TABLE_SIZE);
}

//Hash Function 1 (can change)
int hash(int key) {
	int index = performHash1(key);
	if (table[index] >= 0) //if there is already a value in table[index]
		index = linearProbe(index);
	if (index >= 0) //if we find an empty index
		table[index] = key;
	else
		cout << "table Full" << endl;
}

int linearProbe(int key) {
	for (int i = key + 1; )
}

void printTable();

int main() {
	return 0;
}




