//----------------------------------------------------------------------------
// This header file defines the Display option: view the library
// three categories of book
//----------------------------------------------------------------------------
#ifndef CHECKOUT_H
#define CHECKOUT_H
#include "book.h"
#include "bookFactory.h"
class Display : public Action {
public:
  // action constructor for Checkout
  void Action(BST books[], HashTable &patrons);
  // set the data from action
  bool setData(ifstream &infile, char aType);
  // get the string representation of the action
  string getString() const;
};
#endif