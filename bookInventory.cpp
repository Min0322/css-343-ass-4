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

bool BookInventory::bookCheck (Book* bookPtr)
{
    Book* foundPtr = getBook (bookPtr);
    if (foundPtr!= NULL)
        return true;
    else
        return false;
}

void BookInventory::displayAll()
{
    for (int i = 0; i < bookType.size(); i++)
    {
        switch (i)
        {
            case 0:
                cout << "Children's Books" << endl;
                cout << "AVAIL" << setw(1) << "AUTHOR" << setw(20)
                << "TITLE" << setw(30) << "YEAR" << endl;
                break;

            case 1:
                cout << "Fiction Books" << endl;
                cout << "AVAIL" << setw(1) << "AUTHOR" << setw(20)
                << "TITLE" << setw(30) << "YEAR" << endl;
                break;

            case 2:
                cout << "Periodicals" << endl;
                cout << "AVAIL" << setw(1) << "TITLE" << setw(50)
                << "MONTH" << setw(5) << "YEAR" << endl;
                break;

            default:
                break;
        }

        cout << bookType[i];
        bookType[i].resetCounted();
    }
}


bool BookInventory::addBook(Book*& bookPtr)
{
    bool success = false;
    if (bookPtr) {
        switch (bookPtr->getBookType())
        {
            case 'C':
                success = bookType[0].insert(bookPtr);
                return success;
                break;
                
            case 'H':
                success = bookType[1].insert(bookPtr);
                return success;
                break;
                
            case 'P':
                success = bookType[2].insert(bookPtr);
                return success;
                break;
                
            default:
                return success;
                break;
        }
    }
    return success;
}

bool BookInventory::checkoutBook(Book* bookPtr, string& bookInfo)
{
    bool successful = false;
    if (bookCheck(bookPtr))
    {
        Book* bookToCheckout = getBook(bookPtr);
        if (bookToCheckout -> subtractFromCopies(1)) // borrow book
        {
            successful = true;
        }
    }

    return successful;
}

bool BookInventory::returnBook(Book* bookPtr, string& bookInfo)
{
    if (bookCheck(bookPtr))
    {
        Book* bookToReturn = getBook(bookPtr);
        bookToReturn->addToCopies(1); // return book
        
        return true;
    }
    else
        return false;
}
