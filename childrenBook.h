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
  ChildrenBook(const string& author, const string& title,
                const int year, const int month);
  // toString function to print out the book type
  void toString(ostream &stream) const;
  
  // set the data from input file
  void setData(ifstream &infile);
  // operator overloading
  bool operator==(const Book &rhs);
  bool operator>(const Book &rhs);
  bool operator<(const Book &rhs);


  private:
    const char CHILDRENBOOK = 'C';
};
#endif