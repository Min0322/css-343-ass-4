#include "patronInventory.h"

// --------------------------------------------------------------------------------------
// default constructor
// intialize hash table of dummy patron nodes
// --------------------------------------------------------------------------------------
PatronInventory::PatronInventory()
{
    for (int i = 0; i < MAX; i++)
    {
        hashTable[i] = new patronNode;
        hashTable[i] -> patron = NULL;
        hashTable[i] -> next = NULL;
    }
}

// --------------------------------------------------------------------------------------
// destructor
// --------------------------------------------------------------------------------------
PatronInventory::~PatronInventory()
{
    for (int i = 0; i < MAX; i++)
    {
        deleteHelper(hashTable[i] -> next);   // delete list of patrons in bucket
        
        delete hashTable[i] -> patron;      // delete dummy node patron
        hashTable[i] -> patron = NULL;
        
        delete hashTable[i];                  // delete dummy node
        hashTable[i] = NULL;
    }
}

// --------------------------------------------------------------------------------------
// return patron ptr or NULL if patron doesn't exist
// --------------------------------------------------------------------------------------
Patron* PatronInventory::getPatron (int patronID)
{
    int bucket = hashFunction(patronID);
    patronNode* cur = hashTable[bucket] -> next;
    if (cur == NULL)
        return NULL; 
    
    // traverse the bucket to get patron
    while (cur != NULL)
    {
        if (cur -> patron -> getId() == patronID)
            return cur -> patron;
        cur = cur -> next;
    }
    return NULL;
}

// --------------------------------------------------------------------------------------
// returns true if the patron is in the hash table
// --------------------------------------------------------------------------------------
bool PatronInventory::patronCheck (int patronID)
{
    int bucket = hashFunction(patronID);
    patronNode* cur = hashTable[bucket] -> next;
    if (cur == NULL)
        return false; // patron does not exist
    
    // traverse the bucket
    while (cur != NULL)
    {
        if (cur -> patron -> getId() == patronID)
            return true;
        cur = cur -> next;
    }
    return false;
}

// --------------------------------------------------------------------------------------
// returns true if the patron was added to the hash table
// --------------------------------------------------------------------------------------
bool PatronInventory::addPatron(int patronID, string firstName, string lastName)
{
    if (patronCheck(patronID)) {
        return false;
    }

    int bucket = hashFunction(patronID);
    patronNode* cur = hashTable[bucket]->next;
    if (cur == nullptr) {
        hashTable[bucket]->next = new patronNode;
        cur = hashTable[bucket]->next;
    } else {
        patronNode* temp = new patronNode;
        temp->next = cur;
        hashTable[bucket]->next = temp;
        cur = temp;
    }
    cur->patron = new Patron(firstName, lastName, patronID);
    return true;
}


// --------------------------------------------------------------------------------------
// returns true if the patron was removed from the hash table
// --------------------------------------------------------------------------------------
bool PatronInventory::removePatron(int id)
{
    if (!patronCheck(id)) { // check if patron exists
        return false; // patron not found
    }

    int bucket = hashFunction(id);
    patronNode* cur = hashTable[bucket]->next;
    patronNode* prev = hashTable[bucket];

    if (cur == NULL) {
        return false; // empty bucket
    }

    while (cur != NULL) {
        if (cur->patron->getId() == id) { // found patron to remove
            prev->next = cur->next;
            delete cur->patron; // delete patron object
            delete cur; // delete patron node
            return true;
        }
        prev = cur;
        cur = cur->next;
    }

    return false; // patron not found
}

// --------------------------------------------------------------------------------------
// returns the index where to store the patron in the hash table
// --------------------------------------------------------------------------------------
int PatronInventory::hashFunction(int id)
{
    return id % MAX;
}

// --------------------------------------------------------------------------------------
// recursive helper function for destructor
// reletes dynamic memory created by hash table
// --------------------------------------------------------------------------------------
void PatronInventory::deleteHelper(patronNode* cur)
{
    while (cur != NULL)
    {
        patronNode* nextNode = cur->next;
        delete cur->patron;
        cur->patron = NULL;
        delete cur;
        cur = nextNode;
    }
}
