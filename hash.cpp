
#include<iostream>
#include "hash.hpp"
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

HashTable::HashTable(int bsize)
{
    this->TABLE_SIZE= bsize;
    table = new LLnode*[TABLE_SIZE];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}


unsigned int HashTable::hashFunction(int key)
{
    return (key % TABLE_SIZE);
}

void HashTable::printTable()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i <<"|| ";
        //TODO if needed
    }
 }

//Hash function 1
int HashTable::linearMod(int value)
{
    int hashvalue;
    hashvalue = (value%TABLE_SIZE);
    return hashvalue;

}

//Hash function 2
int HashTable::quadMod(int value)
{
    int hashvalue;
    int temp = floor(value/TABLE_SIZE);
    hashvalue = (temp%TABLE_SIZE);
    return hashvalue;
    
}

void HashTable::searchLL(int key){
    //first we find where index is in the list
    int hashIndex = hashFunction(key);
    bool found = false;
    // we use that index in order to initialize our element
    LLnode* element = table[hashIndex];
    
    // if the element itself is there
    if (element != NULL)
    {
        //to keep recursive properties
        while (element != NULL)
        {
            if (element->key == key)// if the element is not found {
                found = true;
            cout << "Element has been found at " << key << ":" << element << endl;
        }
        if (!found) {
            cout << "Element not found" << endl;
        }
    }
}

void HashTable::insertLL(int key){
    int hashIndex = hashFunction(key);
    LLnode* element = table[hashIndex];
    //if there is nothing in the linked list
    if (element == NULL) {
        element = createLLnode(key, NULL);
        element->prev = NULL;
    }
    //if there is something in the list then we add to the  next index.
    else{
        while (element != NULL) {
            element = element->next;
            element= createLLnode(key, NULL);
        }
    }
}

void HashTable::deleteLL(int key){
    int hashIndex = hashFunction(key);
    LLnode* element = table[hashIndex];
    
    while (element != NULL) {
        <#statements#>
    }
    
}

HashTable::BSTnode() {
    BSTnode *head = new BSTnode;
    head = NULL;
}

void HashTable::insertBST(int key){
    int hashIndex = hashFunction(key);
    node* element = table[hashIndex];

    
}
    







