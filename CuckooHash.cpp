//
//  CuckooHash.cpp
//  

#include "CuckooHash.hpp"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <math.h>
#include <fstream>

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
		//cout << "Duplicate value. Please insert new value" << endl;
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

	//cout << "Delete failed. Key not found." << endl;
}

int main(int argc, char const *argv[]) {
    
    //input file declarations OUTSIDE else loop to avoid error
    string dataFile = "";
    string LFinput = "";


    //if incorrect number of command line args
    if (argc != 3) {
        cout << "Usage: FinalProject <<loadFactor -- 0.1 to 1>> <<dataSet.csv>" << endl;
        return 0;
    }
    
    //input initializations from command line
    LFinput = argv[1];
    dataFile = argv[2];

    float loadFactor = stof(LFinput); //string to float
    


    int loadNumbers = 10009 * loadFactor;
    int dataSet[loadNumbers]; //array to hold dataSet

    HashTable hash_table; //declare HashTable object

    string numberInputs = "";
    int i = 0;

    ifstream filestream;
    filestream.open(dataFile);

    //read data from CSV
    while (getline(filestream, numberInputs, ',') && i < loadNumbers) {
        //insert data until reaching load factor
        dataSet[i] = stoi(numberInputs);
        hash_table.hash(dataSet[i]); //insert into Hash Table
        i++;
    }
    filestream.close();


    //REPEAT BELOW CODE 3 TIMES FOR DELETE, INSERT, and LOOKUP

    //Delete:

    // Time Taken in milliseconds
    int sampleSize = 100;
    int timePerDelete[100];
    int totalTimeTaken = 0;
    int averageTime = 0;
    double deviationSum = 0;
    double standardDeviation = 0;
    
    //Collecting data for function times
    for (int i = 0 ; i < sampleSize; i++)
    {
        clock_t start;
        start = clock();
        
        //DELETE FUNCTION CALL
        hash_table.deleteKey(dataSet[i]);

        timePerDelete[i] = (clock() - start / (double)(CLOCKS_PER_SEC ));
        totalTimeTaken = totalTimeTaken + timePerDelete[i];
        
    }
    
    //Finding average time
    averageTime = totalTimeTaken / sampleSize;
    
    // Make-shift equation for summation numerator of Standard Deviation
    for(i = 0; i < sampleSize; i++) {
        deviationSum = deviationSum + pow((timePerDelete[i] - averageTime), 2);
    }
    
    // Standard Deviation equation with proper computed variables
    standardDeviation = sqrt(deviationSum / (sampleSize - 1));
    
    cout << "Average Time of Delete function:  " << averageTime << endl;
    cout << "Standard Deviation of Delete funciton:  " << standardDeviation << endl;

    //Insert:

    //Reset values
    sampleSize = 100;
    int timePerInsert[100];
    totalTimeTaken = 0;
    averageTime = 0;
    deviationSum = 0;
    standardDeviation = 0;
    
    //Collecting data for function times
    for (int i = 0 ; i < sampleSize; i++)
    {
        clock_t start;
        start = clock();
        
        //INSERT FUNCTION CALL
        hash_table.hash(dataSet[i]);

        timePerInsert[i] = (clock() - start / (double)(CLOCKS_PER_SEC ));
        totalTimeTaken = totalTimeTaken + timePerInsert[i];
        
    }
    
    //Finding average time
    averageTime = totalTimeTaken / sampleSize;
    
    // Make-shift equation for summation numerator of Standard Deviation
    for(i = 0; i < sampleSize; i++) {
        deviationSum = deviationSum + pow((timePerInsert[i] - averageTime), 2);
    }
    
    // Standard Deviation equation with proper computed variables
    standardDeviation = sqrt(deviationSum / (sampleSize - 1));
    
    cout << "Average Time of Insert function:  " << averageTime << endl;
    cout << "Standard Deviation of Insert funciton:  " << standardDeviation << endl;
    

    //Lookup:

    //Reset values
    sampleSize = 100;
    int timePerLookup[100];
    totalTimeTaken = 0;
    averageTime = 0;
    deviationSum = 0;
    standardDeviation = 0;
    
    //Collecting data for function times
    for (int i = 0 ; i < sampleSize; i++)
    {
        clock_t start;
        start = clock();
        
        //LOOKUP FUNCTION CALL
        hash_table.inTables(dataSet[i]);

        timePerLookup[i] = (clock() - start / (double)(CLOCKS_PER_SEC ));
        totalTimeTaken = totalTimeTaken + timePerLookup[i];
        
    }
    
    //Finding average time
    averageTime = totalTimeTaken / sampleSize;
    
    // Make-shift equation for summation numerator of Standard Deviation
    for(i = 0; i < sampleSize; i++) {
        deviationSum = deviationSum + pow((timePerLookup[i] - averageTime), 2);
    }
    
    // Standard Deviation equation with proper computed variables
    standardDeviation = sqrt(deviationSum / (sampleSize - 1));
    
    cout << "Average Time of Lookup function:  " << averageTime << endl;
    cout << "Standard Deviation of Lookup funciton:  " << standardDeviation << endl;

    return 0;
}