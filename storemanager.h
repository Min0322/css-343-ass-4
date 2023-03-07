//----------------------------------------------------------------------------
// This header file defines the StoreManager obj
//----------------------------------------------------------------------------
#ifndef STOREMANAGER_H
#define STOREMANAGER_H
#include "BST.h"
#include "action.h"
#include "book.h"
#include "bookFactory.h"
#include "hashtable.h"
class StoreManager {
public:
  // constructor
  StoreManager();
  // input action from data file
  void inputActions(ifstream &inputFile);
  // input library book from data file
  void inputBooks(ifstream &inputFile);
  // input patrons from data file
  void inputPatrons(ifstream &inputFile);
  // perform actions
  void performActions();

private:
  // store actions in the queue STL
  queue<Action> actions;
  // store books in bst
  BST books;
  // store patrons in hashtable
  HashTable patrons;
  // bookfactory
  BookFactory bFactory;
};
#endif