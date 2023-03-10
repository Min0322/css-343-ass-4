#ifndef bookInventory_H
#define bookInventory_H
#include <vector>
#include "book.h"
#include "BST.h"

class BookInventory
{

    public:
        BookInventory();
        ~BookInventory();

        Book* getBook (Book*);
        bool bookCheck (Book*);
        void printInventory();

        // Book* getBookByTitle(int id, string title, int year);

        // bool addBook (Book*& book);
        // bool checkoutBook (Book* book, string& info);
        // bool returnBook (Book* book, string& info);


    private:
    vector<BST> bookType;
};
#endif