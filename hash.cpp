
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

HashTable::HashTable()
{
    valueArray = new int[100]; //100 random values inputed from csv
    table = new LLnode*[TABLE_SIZE];
    for(int i=0; i<TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

LLnode* HashTable::search(int key){
    int hashIndex = hashFunction(key);
    LLnode* element = table[hashIndex];
    while(element != NULL && element->key != key) {
        element = element->next;
    }
    
    return element;
}


//Linear Mod
int HashTable::hashFunction(int key)
{
    return (key % TABLE_SIZE);
}

//Quad Mod
int HashTable::hashFunction2(int value)
{
    int hashvalue;
    int temp = floor(value/TABLE_SIZE);
    hashvalue = (temp%TABLE_SIZE);
    return hashvalue;
}

void HashTable::printTable()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i <<"|| ";
        //TODO if needed
    }
}

bool HashTable::searchLL(int key){

    LLnode* element = search(key);
    
    // if the element itself is there
    if (element != NULL)
    {
        return true;
    }
    return false;
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

void HashTable::insertBST(int num){
    int hashIndex = hashFunction(num);
    LLnode* element = table[hashIndex];

    if (head == NULL) {
        head = new BSTnode;
        head->value = num;
        //not nearly done
    }
}

int HashTable::linearProbing(int key) {
    for (int i = key+1; i != key; i++) { //iterate starting at key + 1
        if (i >= 100) { //wrap around at end of hash table
            i = -1; //will become i = 0 after i++
            continue; //no index 100, continue in the for loop
        }
        if (table[i] )
    }
}
    







