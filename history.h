//----------------------------------------------------------------------------
// This header file defines the History action: view history
// of a patron
// subclass of Action
//----------------------------------------------------------------------------
#ifndef CHECKOUT_H
#define CHECKOUT_H
#include "book.h"
#include "bookFactory.h"
class CheckOut : public Action {
public:
  // action constructor for Checkout
  void Action(BST books[], HashTable &patrons);
  // set the data from action
  bool setData(ifstream &infile, char aType);
  // get the string representation of the action
  string getString() const;

private:
  // patron id
  int id;
};
#endif