//----------------------------------------------------------------------------
// This header file defines the FictionBook object
// (subclass of book)
//----------------------------------------------------------------------------
#ifndef FICTIONBOOK_H
#define FICTIONBOOK_H

#include "book.h"
#include <string>

class FictionBook : public Book {
public:
  // constructor: parameter is book genre
  FictionBook(char bookType, char format, string author, 
  string title, int year, int copies);

  // operator overloading
  bool operator==(const Book &rhs) const;
  bool operator!=(const Book &rhs) const;
  bool operator>(const Book &rhs) const;
  bool operator<(const Book &rhs) const;
};
#endif
