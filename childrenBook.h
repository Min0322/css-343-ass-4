//----------------------------------------------------------------------------
// This header file defines the ChildrenBook object
// (subclass of book)
//----------------------------------------------------------------------------
#ifndef CHILDRENBOOK_H
#define CHILDRENBOOK_H
#include "book.h"
#include <string>

class ChildrenBook : public Book {
public:
  // constructor: parameter is book genre
  ChildrenBook(char bookType, char format, string author, string title,
              int year, int copies);
  ~ChildrenBook();
  // operator overloading
  virtual bool operator==(const Book &rhs) const;
  virtual bool operator!=(const Book &rhs) const;
  virtual bool operator>(const Book &rhs) const;
  virtual bool operator<(const Book &rhs) const;



};
#endif