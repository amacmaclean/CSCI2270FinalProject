//
//  ChainingLL.hpp
//  

#include<math.h>
#include<stdio.h>
#include<ctime>
#include <iostream>


using namespace std;

struct LLnode
{
    int key; //index
    LLnode* next; //singly-linked list because not any faster to implement doubly linked list
};

class HashTable
{
private:
    int TABLE_SIZE = 10009;
    LLnode* *table; //hash Table
    int performHash(int key, bool func1);
public:
    
    HashTable();
    void hash(int key, bool func1);
    bool inTable(int key, bool func1);
    void deleteNode(int key, bool func1);
    
};



