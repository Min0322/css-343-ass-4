#include "checkout.h"

CheckOut::CheckOut(int id, Book* book)
{
    this->id = id;
    this->book = book;
}

CheckOut:: ~CheckOut()
{

}

bool CheckOut::action(BookInventory& books, PatronInventory& patrons)
{
    if (!patrons.patronCheck(id))
    {
        cout << "ERROR: CheckOut Transaction Failed -- "
        << "Patron " << id << " does not exist" << endl;
        
        // delete book ptr after failed checkout transaction
        delete book;
        book = NULL;
        
        return false;
    }

    Patron* patron = patrons.getPatron(id);
    if (book != NULL)
    {
        // check if movie exists in the stock
        if (books.bookCheck(book))
        {
            string bookInfo = "";
            
            if (books.checkoutBook(book, bookInfo))
            {
                // update summary of transaction if borrow performed correctly
                string s = "CheckOut " + bookInfo;
                
                patron->addHistory(s);
                return true;
            }
            else
            {
                cout << "ERROR: CheckOut Transaction Failed -- "
                << "Not enough copies" << endl;
            }
        }
        else
        {
            cout << "ERROR: CheckOut Transaction Failed -- "
            << "book does not Exist in the Inventory" << endl;
        }
    }
    
    delete book;         // delete movie ptr after failed borrow transaction
    book = NULL;
    return false;
}

