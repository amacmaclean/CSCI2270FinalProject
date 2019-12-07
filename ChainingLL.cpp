
#include "ChainingLL.hpp"
#include<iostream>
#include<math.h>
#include<stdio.h>
#include<ctime>

using namespace std;
//function to create node
LLnode* HashTable::createLLnode(int key)
{
    LLnode* nw = new LLnode;
    nw->key = key;
    nw->next = NULL;
    return nw;
}
//constructor
HashTable::HashTable()
{
    int collision = 0;
    valueArray = new int[100]; //100 random values inputed from csv
    table = new LLnode*[TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}
//hash fucntion
int HashTable::hashFunction(int key)
{
    return (key % TABLE_SIZE);
}
//search function
LLnode* HashTable::search(int key){
     int hashIndex = hashFunction(key);
    LLnode* element = table[hashIndex];
    while(element != NULL && element->key != key) {
        element = element->next;
    }
    
    return element;
}
//insert function
void HashTable::insertLL(int key){
    bool found = searchLL(key);
    if (found == false) {
        LLnode* node = createLLnode(key);
        node->prev = NULL;
        int hashIndex = hashFunction(key);
        if (table[hashIndex] == NULL) {
            table[hashIndex] = node;
        }
        else
            collision++;
            node->next = table[hashIndex];
            table[hashIndex] = node;
    }
     if(found == true)
        search(key)->repeatValue++;
}
//delete function
void HashTable::deleteLL(int key){
    int hashIndex = hashFunction(key);
    LLnode* element = table[hashIndex];
    
    while (element != NULL) {
        <#statements#>
    }
}
//traverse function
bool HashTable::searchLL(int key){
    LLnode* element = search(key);
    // if the element itself is there
    if (element != NULL)
    {
        return true;
    }
    return false;
}

