//
//  CuckooHash.hpp
//  

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

class HashTable {
private:
	int table_size; //can change!
	int* table1;
	int* table2;
	int performHash(int key, bool func1);
public:
	HashTable();
	void hash(int key);
	bool inTable(int key);
	void deleteKey(int key);
};

