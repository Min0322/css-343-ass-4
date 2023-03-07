//----------------------------------------------------------------------------
// This header file defines the ChildrenBook object
// (subclass of book)
//----------------------------------------------------------------------------
#ifndef CHILDRENBOOK_H
#define CHILDRENBOOK_H
#include "book.h"
class ChildrenBook : public Book {
public:
  // toString function to print out the book type
  void toString(ostream &stream) const;
  // constructor: parameter is book genre
  ChildrenBook(char genre);
  // set the data from input file
  void setData(ifstream &infile);
  // operator overloading
  bool operator==(const Book &rhs);
  bool operator>(const Book &rhs);
  bool operator<(const Book &rhs);
};
#endif