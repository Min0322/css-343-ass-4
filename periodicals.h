//----------------------------------------------------------------------------
// This header file defines the Periodicals object
// (subclass of book)
//----------------------------------------------------------------------------
#ifndef PERIODICALS_H
#define PERIODICALS_H
#include "book.h"
class Periodicals : public Book {
public:
  // toString: prints out the book
  void toString(ostream &stream) const;
  // constructor: parameter is book genre
  Periodicals(char genre);
  // set data from input
  void setData(ifstream &infile);
  // operator overloading
  bool operator==(const Book &rhs);
  bool operator>(const Book &rhs);
  bool operator<(const Book &rhs);
};

#endif