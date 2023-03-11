#include "return.h"
#include <iostream>

Return::Return(int id, Book* book)
{
    this->id = id;
    this->book = book;
}

Return::~Return()
{
}

bool Return::action(BookInventory& books, PatronInventory& patrons)
{
    if (!patrons.patronCheck(id))
    {
        std::cout << "ERROR: Return Transaction Failed -- "
                  << "Patron " << id << " does not exist" << std::endl;
        
        // delete book ptr after failed return transaction
        delete book;
        book = NULL;
        
        return false;
    }

    Patron* patron = patrons.getPatron(id);
    if (book != NULL)
    {
        // check if book exists in the stock
        if (books.bookCheck(book))
        {
            string bookInfo = "";
            
            if (books.returnBook(book, bookInfo))
            {
                // update summary of transaction if return performed correctly
                string s = "Return " + bookInfo;
                
                patron->addHistory(s);
                return true;
            }
            else
            {
                std::cout << "ERROR: Return Transaction Failed -- "
                          << "book was not checked out by patron" << std::endl;
            }
        }
        else
        {
            std::cout << "ERROR: Return Transaction Failed -- "
                      << "book does not exist in the inventory" << std::endl;
        }
    }
    
    delete book;         // delete book ptr after failed return transaction
    book = NULL;
    return false;
}
