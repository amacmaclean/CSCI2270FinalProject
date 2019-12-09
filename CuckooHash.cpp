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
		insertCuckoo(key, 0, true);
	}
}

void HashTable::insertCuckoo(int key, int count, bool tabl1) {

	if(count >= (2*table_size)) { //cycle
		rehash(); //Increase Table Size!
		return;
	}


	if(tabl1) {
		int index = performHash(key, true); //Hash Function 1
		if (table1[index] >= 0) { //already filled
			int oldKey = table1[index];
			table1[index] = key;
			insertCuckoo(oldKey, count+1, false);
			return;
		}
		else { //spot open
			table1[index] = key;
			return;
		}
	}
	else {
		int index = performHash(key, false); //Hash Function 2
		if (table2[index] >= 0) { //already filled
			int oldKey = table2[index];
			table2[index] = key;
			insertCuckoo(oldKey, count+1, false);
			return;
		}
		else { //spot open
			table2[index] = key;
			return;
		}

	}
}

void HashTable::rehash() {
	int oldSize = table_size;
	int* oldTable1 = table1;
	int* oldTable2 = table2;

	bool isPrime = false;
	while(!isPrime) {
		table_size = table_size + 2; //add two b/c no primes are even (except 2)
		for (int i=3; i < table_size; i = i+2) {
			if (table_size % i == 0) {
				break; //go to next table_size, this one not prime
			}
		}
		isPrime = true;
	}

	table1 = new int[table_size];
	table2 = new int[table_size];

	for (int i=0; i<table_size; i++) {
		table1[i] = -1;
		table2[i] = -1;
	}

	for (int i=0; i<oldSize; i++) {
		if (oldTable1[i] != -1) { //if not empty
			insertCuckoo(oldTable1[i], 0, true); //rehash
		}
		if (oldTable2[i] != -1) {
			insertCuckoo(oldTable2[i], 0, true);
		}
	}

	delete [] oldTable1;
	delete [] oldTable2;

}

//Lookup Function
bool HashTable::inTables(int key) {
	int index = performHash(key, true);
	if (table1[index] == key)
		return true;
	
	index = performHash(key, false);
	if (table2[index] == key)
		return true;

	return false;
}

void HashTable::deleteKey(int key) {
	int index = performHash(key, true);
	if (table1[index] == key) {
		table1[index] = -1;
		return;
	}
		
	index = performHash(key, false);
	if (table2[index] == key) {
		table2[index] = -1;
		return;
	}

	cout << "Delete failed. Key not found." << endl;
}

int main() {
	return 0;
}
	










