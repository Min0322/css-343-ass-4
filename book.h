//----------------------------------------------------------------------------
// This header file defines the Book object
//----------------------------------------------------------------------------
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <fstream>
using namespace std;
class Book {
public:
  // read input file
  virtual void setData(ifstream &inputfile);
  // setters
  // set the book type: children, fiction, or periodicals
  void setBookType(char type);
  // set the book title
  void setTitle(string titleNew);
  // set the year published
  void setYear(int yearNew);
  // set the month published (only periodicals)
  void setMonth(int monthNew);
  // set the number of copies in stock
  void setCopies(int numOfCopies);

  // getters
  // get the book tyope
  char getType() const;
  // get the title
  string getTitle() const;
  // get the year
  int getYear() const;
  // get the month (periodicals)
  int getMonth() const;
  // get the number of copies in stock
  int getCopies() const;
  // operator overloading
  // assignment operator
  virtual Book &operator=(Book &rhs);
  // comparison operator
  virtual bool operator==(const Book &rhs) = 0;
  virtual bool operator>(const Book &rhs) = 0;
  virtual bool operator<(const Book &rhs) = 0;

private:
  // book type: presents if it is Children, Fiction or Periodicals
  char bookType;
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