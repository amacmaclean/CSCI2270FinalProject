#ifndef HASH_HPP
#define HASH_HPP

#include <string>


using namespace std;

struct LLnode
{
    int key;
    LLnode* next;
    LLnode* prev;
};

struct BSTnode
{
    int key;
    BSTnode* left;
    BSTnode* right;
};

class HashTable
{
private:
    int TABLE_SIZE = 10009;
    node* *table;
    node* createNode(int key, node* next);
public:
    HashTable(int bsize);
    bool insertItem(int key);
    unsigned int hashFunction(int key);
    void printTable();
    node* searchItem(int key);
    int linearMod(int value);
    int quadMod(int value);
    void searchLL(int key);
    void insertLL(int key);
    void deleteLL(int key);
    void insertBST(int key);
    void insertBST(int key);
    void deleteBST(int key);
};

#endif
