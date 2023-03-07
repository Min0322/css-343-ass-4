//----------------------------------------------------------------------------
// This header file defines the FictionBook object
// (subclass of book)
//----------------------------------------------------------------------------
#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H
#include "book.h"
class FictionBook : public Book {
public:
  // toString function: prints out the Book type
  void toString(ostream &stream) const;
  // constructor: parameter is book genre
  FictionBook(char genre);
  // set data from input file
  void setData(ifstream &infile);
  // operator overloading
  bool operator==(const Book &rhs);
  bool operator>(const Book &rhs);
  bool operator<(const Book &rhs);
};
#endif