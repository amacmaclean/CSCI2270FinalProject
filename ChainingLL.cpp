//
//  ChainingLL.cpp
//  
//
//  Created by Andrew Maclean on 12/2/19.
//

#include "ChainingLL.hpp"


LLnode* HashTable::search(int key){
     int hashIndex = hashFunction(key);
    LLnode* element = table[hashIndex];
    while(element != NULL && element->key != key) {
        element = element->next;
    }
    
    return element;
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
