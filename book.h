//----------------------------------------------------------------------------
// This header file defines the Book object
//----------------------------------------------------------------------------
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Book {
public:

  Book();
  Book(char bookType, char format, string author, string title, int year, int copies);
  Book(char bookType, char format, string title, int month, int year, int copies);
  virtual ~Book();

  // getters
  // get the book tyope
  char getBookType() const;
  // get the title
  string getTitle() const;
  // get the author
  string getAuthor() const;

  // get the year
  int getYear() const;
  // get the month (periodicals)
  int getMonth() const;
  // get the number of copies in stock
  int getCopies() const;
  // operator overloading
  // assignment operator
  virtual Book& operator=(Book &rhs);
  // comparison operator
  virtual bool operator==(const Book &rhs) const;
  virtual bool operator!=(const Book &rhs) const;
  virtual bool operator>(const Book &rhs) const;
  virtual bool operator<(const Book &rhs) const;

  virtual void display() const;                                         
    
  // Mutators
  bool addToCopies(int);                              // add to stock
  virtual bool subtractFromCopies(int);               // subtract from stock
                         

private:
  // book type: presents if it is Children, Fiction or Periodicals
  char bookType;
  char format;
  // book author name
  string author;
  // book title
  string title;
  // year of publishment
  int year;
  // month of publishment
  int month;
  // number of copies in stock at the library
  int copies;
};
#endif