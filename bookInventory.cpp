#include "bookInventory.h"


BookInventory :: BookInventory()
{
    BST childrenBook, fictionBook, periodicals;
    bookType.push_back(childrenBook);
    bookType.push_back(fictionBook);
    bookType.push_back(periodicals);
}

BookInventory::~BookInventory()
{
    bookType.clear();
}

Book* BookInventory::getBook(Book* b)
{
        Book *foundPtr = NULL;
    switch (b->getBookType())
    {
        case 'C':
            bookType[0].getBook(*b, foundPtr);
            return foundPtr;
            break;
        
        case 'H':
            bookType[1].getBook(*b, foundPtr);
            return foundPtr;
            break;
            
        case 'P':
            bookType[2].getBook(*b, foundPtr);
            return foundPtr;
            break;
            
        default:
            foundPtr = NULL;
            break;
    }
    return foundPtr;
}