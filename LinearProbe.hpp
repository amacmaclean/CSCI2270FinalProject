//
//  LinearProbe.hpp
//  



#include <stdio.h>
#include <iostream>
#include <vector>
#include <ctime>

class HashTable {
private:
	int TABLE_SIZE;
	int* table;
	int performHash1(int key);
	int performHash2(int key);
public:
	HashTable(int size);
	int hash(int key);
	void printTable();
	int linearProbe(int key);
};



