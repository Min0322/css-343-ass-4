#ifndef patronInventory_h
#define patronInventory_h
#include "patron.h"
#include <iostream>

using namespace std;


class PatronInventory
{
    public:
        static const int MAX = 10000;

        PatronInventory();
        ~PatronInventory();

        Patron* getPatron(int id);

        bool patronCheck(int id);
        bool addPatron(int id, string firstName, string lastName);
        bool removePatron(int id);

    private:

        struct patronNode
        {
            Patron* patron;
            patronNode* next;
        };
        patronNode* hashTable[MAX];

        int hashFunction(int ID);
        void deleteHelper(patronNode*);
};
#endif