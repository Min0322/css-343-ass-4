//----------------------------------------------------------------------------
// This header file defines the patron obj
//----------------------------------------------------------------------------
#ifndef PATRON_H
#define PATRON_H
#include "book.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
using namespace std;
class Patron {
public:
  // constructor
  Patron();
  Patron(string FirstName, string lastName, int id);
  ~Patron();
  // set data from input file
  // virtual void setPatronData(ifstream &in);
  // setters
  void setId(int num);
  void setFirstName(string fnameNew);
  void setLastName(string lnameNew);
  void setHistory(vector<string> history);

  int getId() const;
  string getFirstName() const;
  string getLastName() const;
  void addHistory(string a);
  void displayHistory();


private:
  // patron id
  int id;
  // patron first and last name
  string firstName;
  string lastName;
  // STL queue to store the history of books patron has
  vector<string> history;
};
#endif