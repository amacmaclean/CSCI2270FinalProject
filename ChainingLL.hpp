




using namespace std;

struct LLnode
{
    int key; //index
    int repeatValue; //number
    LLnode* next;
    LLnode* prev;
};

class HashTable
{
private:
    int TABLE_SIZE = 10009;
    int* valueArray; //from csv
    LLnode* *table; //hash Table
    LLnode* createNode(int key);
    LLnode* head; //pointer to head of linked list
    int hashFunction(int key)
public:
    
    HashTable();
    int hashFunction(int key);
    bool searchLL(int key);
    void insertLL(int key);
    void deleteLL(int key);
    LLnode* search(int key);
    LLnode* createLLnode(int key);
};



