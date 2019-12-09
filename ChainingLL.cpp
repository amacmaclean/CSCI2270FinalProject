
#include "ChainingLL.hpp"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <ctime>
#include <fstream>

using namespace std;

//constructor
HashTable::HashTable()
{
    TABLE_SIZE = 10009;
    table = new LLnode*[TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++) {
        table[i] = NULL;
    }
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

//Insert function
void HashTable::hash(int key, bool func1) {
    int index = performHash(key, func1);
    if(table[index] == NULL) {
        //Create node
        LLnode* nw = new LLnode;
        nw->key = key;
        nw->next = NULL;
        table[index] = nw;
        return; 
    }
    LLnode* crawler = table[index]; //table[index] = head
    while(crawler->next != NULL) {
        if (crawler->key == key) { //if already there
            cout << "Duplicate Value -- Please insert different number" << endl;
            return;
        }
        
        crawler = crawler->next; //iterate
    }

    //Create node
        crawler->key = key;
        crawler->next = NULL;
        return;
}

//Lookup function
bool HashTable::inTable(int key, bool func1) {
    int index = performHash(key, func1);
    if (table[index] == NULL) //if LL empty
        return false;
    LLnode* crawler = table[index]; //table[index] = head
    do {
        if (crawler->key == key) //if found
            return true;
        crawler = crawler->next; //iterate
    } while (crawler != NULL); //(see above line)

    return false; //if reach end of LL without finding it
}

//delete function
void HashTable::deleteNode(int key, bool func1){
    int index = performHash(key, func1);
    LLnode* crawler = table[index];

    //if not empty
    if(crawler != NULL) {
        //if delete head
        if (crawler->key == key) {
            table[index] = crawler->next;
            delete crawler;
            return;
        }
    
        //iterate
        while (crawler->next != NULL) {
            //if delete one ahead
            if (crawler->next->key == key) {
                LLnode* temp = crawler->next;
                crawler->next = temp->next; //pass the arrow past temp
                delete temp;
                return;
            }
            crawler = crawler->next;
        }
    }
    
    //if no node with countryName (or empty)
    //cout << "Delete failed. Value not found." << endl;
}




int main(int argc, char const *argv[]) {
    
    //input file declarations OUTSIDE else loop to avoid error
    string dataFile = "";
    string LFinput = "";
    string functionInput = "";


    //if incorrect number of command line args
    if (argc != 4) {
        cout << "Usage: FinalProject <<function -- 1 or 2>> <<loadFactor -- 0.1 to 1>> <<dataSet.csv>" << endl;
        return 0;
    }
    
    //input initializations from command line
    functionInput = argv[1];
    LFinput = argv[2];
    dataFile = argv[3];

    float loadFactor = stof(LFinput); //string to float
    int hashFunction = stoi(functionInput); //string to int
    bool func1;
    if (hashFunction == 1)
        func1 = true;
    else if (hashFunction == 2)
        func1 = false;
    else {
        cout << "Hash function must be 1 or 2" << endl;
        return 0;
    }


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
        hash_table.hash(dataSet[i], func1); //insert into Hash Table
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
        hash_table.deleteNode(dataSet[i], func1);

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
        hash_table.hash(dataSet[i], func1);

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
        hash_table.inTable(dataSet[i], func1);

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


