//----------------------------------------------------------------------------
// This header file defines the patron obj
//----------------------------------------------------------------------------
#ifndef PATRON_H
#define PATRON_H
#include "book.h"
#include <queue>
#include <stack>
class Patron {
public:
  // constructor
  Patron();
  // set data from input file
  virtual void setPatronData(ifstream &in);
  // setters
  void setId(int num);
  void setFirstName(string fnameNew);
  void setLastName(string lnameNew);
  // getters
  int getId() const;
  string getFirstName() const;
  string getLastName() const;
  // actions that patron can perform
  //  borrow (or checkout) book
  void borrowBook(Book *&b);
  // display the history of books
  void displayHistory();
  // display the history of actions
  void actionsPerformed(string actions);
  // returning a book
  void returnBook(Book *&b, Book *&returnB);

private:
  // patron id
  int id;
  // patron first and last name
  string firstName;
  string lastName;
  // STL queue to store the history of books patron has
  queue<Book *> history;
  // STL stack to store the list of actions in string patron has
  stack<string> actions;
};
#endif