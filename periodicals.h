//----------------------------------------------------------------------------
// This header file defines the Periodicals object
// (subclass of book)
//----------------------------------------------------------------------------
#ifndef PERIODICALS_H
#define PERIODICALS_H
#include "book.h"
class Periodicals : public Book {
public:
public:
  // constructor: parameter is book genre
  Periodicals(char bookType, char format, 
  string title,int month , int year, int copies);
  ~Periodicals();
  // operator overloading
  virtual bool operator==(const Book &rhs) const;
  virtual bool operator!=(const Book &rhs) const;
  virtual bool operator>(const Book &rhs) const;
  virtual bool operator<(const Book &rhs) const;
};

#endif