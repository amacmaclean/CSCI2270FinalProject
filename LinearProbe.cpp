//
//  LinearProbe.cpp
//  

#include "LinearProbe.hpp"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

//Constructor
HashTable::HashTable() {
	table = new int[TABLE_SIZE]; //int array hash table
	for (int i = 0; i < TABLE_SIZE; i++) //set all elements to -1
		table[i] = -1;
}

int HashTable::performHash(int key, bool func1) {
    //Hash Function 1
    if(func1)
        return key % TABLE_SIZE;
    //Hash Function 2
    else { 
        int floorVal = floor(key/TABLE_SIZE);
        return (floorVal%TABLE_SIZE);
    }
}

//Hash Function 1 (can change to 2)
void HashTable::hash(int key, bool func1) {
	int index = performHash(key, func1);
	if (table[index] >= 0) //if there is already a value in table[index]
		index = linearProbe(index);
	if (index >= 0) //if we find an empty index
		table[index] = key; //ADD VALUE TO TABLE HERE!
	else
		cout << "table Full" << endl;
}

int HashTable::linearProbe(int index) {
	for (int i = index+1; i != index; i++) { //iterate starting at key + 1
        if (i >= TABLE_SIZE) { //wrap around at end of hash table
            i = -1; //will become i = 0 after i++
            continue; //no index 100, continue in the for loop
        }
        if (table[i] == -1) //if empty index
        	return i;
    }
    return -1; //no empty indicies
}

//Lookup Function
bool HashTable::inTable(int key, bool func1) {
	int index = performHash(key, func1);
	if (table[index] == key)
		return true;
	else {
		for(int i = index+1; i != index; i++) { //search
			if (i >= TABLE_SIZE) { //wraparound
				i = -1;
				continue;
			}
			if (table[i] == -1) //if empty index found, key not in table
				return false;
			if (table[i] == key)
				return true;
		}
		return false; //not found through linear probing, table full
	}
}

void HashTable::deleteKey(int key, bool func1) {
	int index = performHash(key, func1);
	if (table[index] == key)
		table[index] = -1; //DELETE
	else {
		for(int i = index+1; i != index; i++) { //seach
			if (i >= TABLE_SIZE) { //wraparound
				i = -1;
				continue;
			}
			if (table[i] == -1) //if empty index found, key not in table
				cout << "Key not in table. Delete failed." << endl;
				return;
			if (table[i] == key)
				table[index] = -1; //DELETE
		}
		cout << "Key not in table. Delete failed." << endl;
		return; //not found through linear probing, table full
	}
}

void HashTable::printTable() {
	for (int i = 0; i < TABLE_SIZE; i++) {
		cout << table[i] << ", ";
	}
	cout << endl;
}

int main() {
	return 0;
}





