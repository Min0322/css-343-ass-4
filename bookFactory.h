//----------------------------------------------------------------------------
// This header file defines the BookFactory class 
//----------------------------------------------------------------------------
#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H
#include "book.h"
class BookFactory {
    //create a book
    bool createBook(ifstream& infile, char genre, Book*& book);
};
#endif