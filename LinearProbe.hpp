//
//  LinearProbe.hpp
//  

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

class HashTable {
private:
	int TABLE_SIZE = 10009;
	int* table;
	int performHash(int key, bool func1);
public:
	HashTable(int size);
	void hash(int key, bool func1);
	void printTable();
	int linearProbe(int index);
	bool inTable(int key, bool func1);
	void deleteKey(int key, bool func1);
};



