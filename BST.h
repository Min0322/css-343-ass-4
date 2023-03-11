//----------------------------------------------------------------------------
// This header file defines the data structure BST to store Book type
//----------------------------------------------------------------------------
#ifndef BST_H
#define BST_H
#include "book.h"
#include <iostream>
class BST {
  friend ostream& operator << (ostream& out , const BST& tree); // operation overriding
public:
  // constructor
  BST();
  // destructor
  ~BST();

  
  // utilities functions
  bool insert(Book *ins);
  bool remove(Book *rem);
  bool getBook(const Book &findB, Book *&returnB) const;
  

private:
  // BST Node: left ptr, right ptr, obj data book
  struct Node {
    Book *b;
    Node *left;
    Node *right;
  };
  Node *root;

  void clearHelper (Node* &);             // private functions
  void printHelper (Node* cur, ostream& out) const;
  bool insertHelper (Node *&root, Book* b);
  bool removeHelper (Node *&root, Book* b);
  bool retrieveHelper (const Book&, Book*& , Node*) const;
};
#endif