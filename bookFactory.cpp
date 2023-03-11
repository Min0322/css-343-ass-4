#include "bookFactory.h"

BookFactory::BookFactory()
{

}

BookFactory::~BookFactory()
{

}

Book* BookFactory::createBook(char bookType, string author, string title, int month, int year)
{
    Book* newBook = NULL;
    switch(bookType)
    {
        case 'C':
            newBook = new ChildrenBook (bookType, 'H', author, title, year, 5);
            return newBook;
            break;
            
        case 'F':
            newBook = new FictionBook (bookType, 'H', author, title, year, 5);
            return newBook;
            break;
            
        case 'P':
            newBook = new Periodicals (bookType, 'H', title, month, year, 1);
            return newBook;
            break;
            
        default:
            cout << "ERROR: " << bookType << " bookType Not Found. Try Again." << endl;
            return newBook;
            break;
    }
}