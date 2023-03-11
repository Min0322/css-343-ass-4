//----------------------------------------------------------------------------
// This header file defines the BookFactory class 
//----------------------------------------------------------------------------
#ifndef BOOKFACTORY_H
#define BOOKFACTORY_H
#include "book.h"
#include "childrenBook.h"
#include "fictionBook.h"
#include "periodicals.h"
class BookFactory {
    public:
        BookFactory();
        ~BookFactory();
        //create a book
        Book* createBook(char bookType, string author, string title, int month, int year);
};
#endif