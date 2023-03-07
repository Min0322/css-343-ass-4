//----------------------------------------------------------------------------
// This header file defines the Checkout action
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
  // book type: hardcopy or ..
  string mediaType;
  // book factory
  BookFactory bFactory;
};
#endif