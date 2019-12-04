#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct node
{
    int key;
    struct node* next;
};

class HashTable
{
    int tableSize;
    node* *table;
    node* createNode(int key, node* next);
public:
    HashTable(int bsize);
    bool insertItem(int key);
    unsigned int hashFunction(int key);
    void printTable();
    node* searchItem(int key);
};

#endif
