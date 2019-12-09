//
//  CuckooHash.cpp
//  

#include "CuckooHash.hpp"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

//Constructor
HashTable::HashTable() {
	table_size = 10009; //can CHANGE!
	table1 = new int[table_size]; //int array hash table
	table2 = new int[table_size]; //int array hash table
	for (int i = 0; i < table_size; i++) {
		table1[i] = -1;
		table2[i] = -1;
	}
}

int HashTable::performHash(int key, bool func1) {
    //Hash Function 1
    if(func1)
        return key % table_size;
    //Hash Function 2
    else { 
        int floorVal = floor(key/table_size);
        return (floorVal%table_size);
    }
}

void HashTable::hash(int key) {
	if (inTables(key)) {
		cout << "Duplicate value. Please insert new value" << endl;
	}
	else {
		int index = performHash(key, true); //Perform Hash 1
		if (table1[index] >= 0) { //if there is already a value in table1[index]
			insertCuckoo(key, 0);
		}
	}
}

void HashTable::insertCuckoo(int key, int count) {

	if(count >= table_size) //cycle
		rehash(); //Increase Table Size!

	if (table1[index1] >= 0) { //if there is already a value in table1[index]
		int index2 = performHash(key, false); //Perform Hash 2

		if (table2[index2] >= 0) {
			//Replace, call function again with key from table2
			int oldKey = table1[index1];
			table1[index1] = key;
			insertCuckoo(oldKey, count+1);
		}	
	}
	else {
		table1[index1] = key;
	}
}

void HashTable::rehash(int key, int origT2index) {

}

//Lookup Function
bool HashTable::inTables(int key) {
	
}
	










