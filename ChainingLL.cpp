
#include "ChainingLL.hpp"
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <ctime>

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
        return; 
    }
    LLnode* crawler = table[index]; //table[index] = head
    do {
        if (crawler->key == key) { //if already there
            cout << "Duplicate Value -- Please insert different number" << endl;
            return;
        }
        crawler = crawler->next; //iterate
    } while (crawler != NULL); //until end of LL
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
    cout << "Delete failed. Value not found." << endl;
}

int main() {
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


