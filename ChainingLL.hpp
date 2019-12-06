
#include <string>
#include "ChainingLL.cpp"


using namespace std;

struct LLnode
{
    int key; //index
    int value; //number
    LLnode* next;
    LLnode* prev;
};


class HashTable
{
private:
    int TABLE_SIZE = 10009;
    int* valueArray; //from csv
    LLnode* *table; //hash Table
    LLnode* createNode(int key, node* next);
    LLnode* head; //pointer to head of linked list
    
    
public:
    HashTable(int bsize);
    int hashFunction(int key);
    void printTable();
    int linearMod(int value);
    int quadMod(int value);
    bool searchLL(int key);
    void insertLL(int key);
    void deleteLL(int key);
    LLnode* search(int key);
};

#endif

