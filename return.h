//----------------------------------------------------------------------------
// This header file defines the Return action
// subclass of Action
//----------------------------------------------------------------------------
#ifndef RETURN_H
#define RETURN_H
#include "book.h"
#include "bookFactory.h"
class Return : public Action {
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