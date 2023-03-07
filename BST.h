//----------------------------------------------------------------------------
// This header file defines the data structure BST to store Books
//----------------------------------------------------------------------------
#ifndef BST_H
#define BST_H
#include "book.h"
class BST {
public:
  // constructor
  BST();
  // destructor
  ~BST();
  // utilities functions
  void insert(Book *ins);
  void remove(Book *b);
  void inorderTraversal();
  bool getBook(Book *findB, Book *&returnB);

private:
  // BST Node: left ptr, right ptr, obj data book
  struct Node {
    Book *b;
    Node *left;
    Node *right;
  };
  Node *root;
};
#endif