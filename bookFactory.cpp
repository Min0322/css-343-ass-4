#include "bookFactory.h"

BookFactory::BookFactory()
{

}

BookFactory::~BookFactory()
{

}

Book* BookFactory::createBook(char bookType, string title, string author, int month, int year, int stock)
{
    Book* newBook = NULL;
    switch(bookType)
    {
        case 'C':
            newBook = new ChildrenBook (bookType, 'C', title, director, stock, year);
            return newBook;
            break;
            
        case 'F':
            newBook = new FictionBook (bookType, 'F', title, director, stock, year);
            return newBook;
            break;
            
        case 'P':
            newBook = new Periodicals (bookType, 'P', title, director, stock, year, month, actor);
            return newBook;
            break;
            
        default:
            cout << "ERROR: " << bookType << " bookType Not Found. Try Again." << endl;
            return newBook;
            break;
    }
}