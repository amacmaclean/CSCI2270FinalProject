
#include "ChainingLL.hpp"
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<ctime>

using namespace std;

LLnode* HashTable::createLLnode(int key, LLnode* next)
{
    LLnode* nw = new LLnode;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable()
{
    valueArray = new int[100]; //100 random values inputed from csv
    table = new LLnode*[TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

HashTable::~HashTable(){}

LLnode* HashTable::search(int key){
     int hashIndex = hashFunction(key);
    LLnode* element = table[hashIndex];
    while(element != NULL && element->key != key) {
        element = element->next;
    }
    
    return element;
}

void HashTable::insertLL(int key){
    bool found = searchLL(key);
    
    if (found == FALSE) {
        <#statements#>
    }
}

void HashTable::deleteLL(int key){
    int hashIndex = hashFunction(key);
    LLnode* element = table[hashIndex];
    
    while (element != NULL) {
        <#statements#>
    }
    
}
