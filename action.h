//----------------------------------------------------------------------------
// This header file defines the Action object
//----------------------------------------------------------------------------
#ifndef ACTION_H
#define ACTION_H
#include "BST.h"
#include "book.h"
#include "hashtable.h"
class Action {
public:
  // destructor
  ~Action();
  // setters
  void setID(int id);
  void setBookType(char bType);
  void setAction(char aType);
  void setFormat(char fType);
  void setBook(Book *newBook);
  // getters
  string getID() const;
  char getBookType() const;
  char getBookFormat() const;
  Book *getBook() const;
  char getAction() const;
  // constructor
  virtual void Action(BST books[], HashTable &patrons) = 0;
  // set data from input
  virtual bool setData(ifstream &infile, char aType) = 0;
  // get the action as string
  virtual string getString() const = 0;

private:
  // track patron ID
  int patronID;
  // book type
  char bookType;
  // char that represents action
  char action;
  // book format: hardcopy or
  char bookFormat;
  // book obj if neede
  Book *book;
};
#endif