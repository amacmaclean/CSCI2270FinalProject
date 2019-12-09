//
//  ChainingBST.cpp
//  

#include "ChainingBST.hpp"
#include<math.h>
#include<stdio.h>
#include<ctime>
#include <iostream>

using namespace std;

HashTable::HashTable() {
	TABLE_SIZE = 10009;
	table = new BSTnode*[TABLE_SIZE]; // root BSTnode* array hash table, 
	for (int i = 0; i < TABLE_SIZE; i++) //set all elements to -1
		table[i] = NULL;
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
	int index = performHash(key, func1);
	
	table[index] = insertIntoBST(table[index], key); //table[index] = root	
}

//Recursive insert function
BSTnode* HashTable::insertIntoBST(BSTnode* currNode, int key) {
	if (currNode == NULL) {
		BSTnode* newNode = new BSTnode;
		newNode->key = key;
		return newNode;
	}
	else if (key < currNode->key) { //if lower than current, go left
		currNode->left = insertIntoBST(currNode->left, key);
	}
	else if (key > currNode->key) { //if greater than current, go right
		currNode->right = insertIntoBST(currNode->right, key);
	}
	else { //if key == currNode->key
		cout << "Duplicate Value -- Please insert different number" << endl;
		return NULL;
	}
	return currNode;
}

//Lookup function
bool HashTable::inTable(int key, bool func1) {
	int index = performHash(key, func1);

	if (lookupNode(table[index], key)) //if found
		return true;
	else //if NULL
		return false;
}

//Recursive lookup function
BSTnode* HashTable::lookupNode(BSTnode* currNode, int key) {
	if (currNode == NULL) {
		return NULL; //key not in BST
	}
	else if (key == currNode->key) { //key found
		return currNode;
	}
	else if (key < currNode->key) { //if lower than current, go left
		currNode->left = lookupNode(currNode->left, key);
	}
	else { //if greater than current, go right
		currNode->right = lookupNode(currNode->right, key);
	}
	return currNode;
}


void HashTable::deleteKey(int key, bool func1) {
	int index = performHash(key, func1);
	table[index] = deleteNode(table[index], key);
}

BSTnode* HashTable::deleteNode(BSTnode* currNode, int key) {
  if(currNode == NULL)
  {
  	cout << "Delete failed. Value not found." << endl;
  	return NULL;
  }
  else if(key < currNode->key) {
    currNode->left = deleteNode(currNode->left, key);
  }
  else if(key > currNode->key) {
    currNode->right = deleteNode(currNode->right, key);
  }
  // We found the node with the key
  else {
    //TODO Case : No child
    if(currNode->left == NULL && currNode->right == NULL) {
        delete currNode;
        currNode = NULL; //will return NULL
    }
    //TODO Case : Only right child
    else if(currNode->left == NULL) {
        BSTnode* toReturn = currNode->right;
        delete currNode;
        return toReturn;

    }
    //TODO Case : Only left child
    else if(currNode->right == NULL) {
        BSTnode* toReturn = currNode->left;
        delete currNode;
        return toReturn;
    }
    //TODO Case: Both left and right child
    else {
      ///Replace with Minimum from right subtree
      BSTnode* rightMin = getMinBSTNode(currNode->right);
      delete currNode;
      return rightMin;
    }
  }
  return currNode;
}

BSTnode* HashTable::getMinBSTNode(BSTnode* currNode){

    if(currNode->left == NULL){
      return currNode;
    }
    return getMinBSTNode(currNode->left);
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
