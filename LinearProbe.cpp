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
	TABLE_SIZE = 10009;
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

void HashTable::hash(int key, bool func1) {
	if(inTable(key, func1))
		cout << "Duplicate value. Please insert new value" << endl;
	else {
		int index = performHash(key, func1);
		if (table[index] >= 0) //if there is already a value in table[index]
			index = linearProbe(index);
		if (index >= 0) //if we find an empty index
			table[index] = key; //ADD VALUE TO TABLE HERE!
		else
			cout << "table Full" << endl;
	}
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
	else if (table[index] == -1)
		return false;
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

int main()
{

            // Time Taken in milliseconds
            
            int sampleSize = 100;
            int durartion[100];
            int totalTimeTaken = 0;
            int averageTime = 0;
            double deviationSum = 0;
            double standardDeviation = 0;
            
            //Collecting data for function times
            for (int i = 0 ; i < sampleSize; i++)
            {
                clock_t start;
                start = clock();
                
                //insert add/delete/search function call here******************************************
                
                duration[i] = (clock() - start / (double)(CLOCKS_PER_SEC ));
                totalTimeTaken = totalTimeTaken + duration[i];
                
            }
            
            //Finding average time
            averageTime = totalTimeTaken / sampleSize;
            
            // Make-shift equation for summation numerator of Standard Deviation
            for(i = 0; i < sampleSize; i++) {
                deviationSum = deviationSum + pow((duration[i] - averageTime), 2);
            }
            
            // Standard Deviation equation with proper computed variables
            standDev = sqrt(deviationSum / (sampleSize - 1));
            
            cout << "Average Time of function:  " << averageTime << endl;
            cout << "Standard Deviation of funciton:  " << standardDeviation << endl;

      
    
	return 0;
}





