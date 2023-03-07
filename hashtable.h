//----------------------------------------------------------------------------
// This header file defines hashtable data structure to store Patrons obj
//----------------------------------------------------------------------------
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "patron.h"
// assume table has 999 nodes
const int MAX_SIZE = 999;
class HashTable {
public:
  // constructor
  HashTable();
  // destructor
  ~HashTable();
  // insert a patron to table
  void insert(Patron *p);
  // search for a patron from table
  bool getPatron(int id, Patron *findP, Patron *&returnP);
  // build table from input file
  void buildHashTable(ifstream &infile);

private:
  // struct for hashnode
  // hold patron and next ptr
  struct HashNode {
    HashNode *next;
    Patron *p;
  };
  HashNode *table[MAX_SIZE];
  // hash function
  int hash(int patronID);
};
#endif