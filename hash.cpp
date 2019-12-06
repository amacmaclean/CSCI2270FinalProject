
#include<iostream>
#include "hash.hpp"
#include<math.h>
#include<stdio.h>
#include<ctime>

using namespace std;

node* HashTable::createNode(int key, node* next)
{
    node* nw = new node;
    nw->key = key;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int bsize)
{
    this->TABLE_SIZE= bsize;
    table = new node*[TABLE_SIZE];
    for(int i=0;i<bsize;i++)
        table[i] = nullptr;
}


unsigned int HashTable::hashFunction(int key)
{
    return (key % TABLE_SIZE);
}


//function to search
node* HashTable::searchItem(int key)
{
    //Compute the index by using the hash function
    int index = hashFunction(key);

    
    
    /*for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[key] == index) {
            cout << "Found" << endl;
            return NULL;
        }
    }
     */
    cout << "Not Found" << endl;
    return NULL;
}


//function to insert
bool HashTable::insertItem(int key)
{
    if(!searchItem(key))
    {
        
        int index = hashFunction(key);
       node* nw= createNode(key,nullptr);
        
        if (table[index]==NULL) {
            table[index] = nw;
        }
     }
    else{
        cout<<"duplicate entry: "<<key<<endl;
        return false;
    }
    return 0;
}




void HashTable::printTable()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i <<"|| ";
    }
 }

int HashTable::linearMod(int value)
{
    int hashvalue;
    hashvalue = (value%TABLE_SIZE);
    return hashvalue;

}

int HashTable::quadMod(int value)
{
    int hashvalue;
    int temp = floor(value/TABLE_SIZE);
    hashvalue = (temp%TABLE_SIZE);
    return hashvalue;
    
}

int main() {
    
    //Sample Code Given
    int startTime, endTime;
    double execTime;
    startTime = clock();
    /*
    EVALUATION CODE GOES HERE
    */
    endTime = clock();
    execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
    cout << "execution time: " << execTime << endl;
    return 0;
}




