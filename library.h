#ifndef library_H
#define library_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "patron.h"
#include "patronInventory.h"
#include "book.h"
#include "bookFactory.h"
#include "bookInventory.h"
#include "action.h"
#include "actionFactory.h"
using namespace std;

class Library
{
public:
    Library();         // constructor
    ~Library();        // destructor
    
    void readPatronFile (ifstream&);             // load patrons into patronTable
    void readBookFile (ifstream&);                // load books into bookTree
    void readActionFile (ifstream&);          // read transactions and execute
    bool performAction (Action*);        // execute a transaction
    
private:
    BookInventory bookTree;                      // BST of books
    PatronInventory patronTable;               // hash table of patrons
    BookFactory bookFactory;                     // book factory
    ActionFactory actionFactory;               // transaction factory
    
    string readStringStream(stringstream&);        // helpers
};
#endif